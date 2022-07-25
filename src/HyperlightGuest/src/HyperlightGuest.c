
#include "hyperlight.h" 
#include "hyperlight_guest.h"
#include <setjmp.h>

extern int _fltused = 0;
uintptr_t __security_cookie;
jmp_buf jmpbuf;
HyperlightPEB* pPeb;
void* unusedHeapBufferPointer = 0;
FuncTable* funcTable;

bool runningHyperlight = true;
void (*outb_ptr)(uint16_t port, uint8_t value) = NULL;

#pragma optimize("", off)

void RegisterFunction(const char* FunctionName, guestFunc pFunction, int paramCount, ParameterKind parameterKind[])
{
    if (funcTable->next > funcTable->size)
    {
        char message[100] = { 0 };
        snprintf(message, 100, "Function Table Limit is %d.", funcTable->size);
        setError(TOO_MANY_GUEST_FUNCTIONS, message);
    }
    FuncEntry* funcEntry = (FuncEntry*) malloc(sizeof(FuncEntry));
    if (NULL == funcEntry)
    {
        setError(MALLOC_FAILED, NULL);
    }
    
    funcEntry->FunctionName = FunctionName;
    funcEntry->pFunction = pFunction;
    funcEntry->paramCount = paramCount;
    funcEntry->parameterKind = parameterKind;

    funcTable->funcEntry[funcTable->next] = funcEntry;
    funcTable->next++;
}

void InitialiseFunctionTable(int size)
{
    size = size > 0 ? size : DEFAULT_FUNC_TABLE_SIZE;
    funcTable = (FuncTable*)malloc(sizeof(FuncTable));
    if (NULL == funcTable)
    {
        setError(MALLOC_FAILED, NULL);
    }

    funcTable->next = 0;
    funcTable->size = size;
    funcTable->funcEntry = (FuncEntry**)(malloc(sizeof(FuncEntry*) * size));
    if (NULL == funcTable->funcEntry)
    {
        setError(MALLOC_FAILED, NULL);
    }
}

void outb(uint16_t port, uint8_t value)
{
    const uint8_t outb[] = { 0x89, 0xd0, 0x89, 0xca, 0xee, 0xc3 };

    if (runningHyperlight)
    {
        ((void (*)(uint16_t, uint8_t))outb)(port, value);

    }
    else if (NULL != outb_ptr)
    {
        // We were passed a function pointer for outb - Use it

        // If we are running under Linux, it means the outb_ptr callback is
        // implemented by dotnet running on Linux.  In this case, the calling conventions
        // allow the dotnet code to overwrite rsi/rdi.  If this binary is built
        // using MSVC, it expects rsi/rdi to be preserved by anything it calls.  The optimizer
        // might make use of one of these registers, so we will save/restore them ourselves.
        uint64_t rsi = getrsi();
        uint64_t rdi = getrdi();
        outb_ptr(port, value);
        setrsi(rsi);
        setrdi(rdi);
    }
}

void halt()
{
    const uint8_t hlt = 0xF4;
    if (runningHyperlight)
        ((void (*)()) & hlt)();
}

char* strncpy(char* dest, const char* src, size_t len)
{
    char* result = dest;
    while (len--)
    {
        *dest++ = *src++;
    }
    *dest = 0;
    return result;
}

int printOutput(const char* message)
{
    size_t result = strlen(message);
    if (result >= pPeb->outputdata.outputDataSize)
    {
        result = (int)pPeb->outputdata.outputDataSize - 1;
    }
#pragma warning(suppress : 4996)
    strncpy((char*)pPeb->outputdata.outputDataBuffer, (char*)message, result);
    outb(100, 0);
    return (int)result;
}

void resetError()
{
    pPeb->guestError.errorNo = 0;
    *pPeb->guestError.message = '\0';
}

// SetError sets the specified error and message in memory and then halts execution by returning the the point that setjmp was called

void setError(uint64_t errorCode, char* message)
{
    pPeb->guestError.errorNo = errorCode;
    size_t length = NULL == message ? 0 : strlen(message);
    if (length >= pPeb->guestError.messageSize)
    {
        length = pPeb->guestError.messageSize - 1;
    }

    if (NULL == message)
    {
        *pPeb->guestError.message = '\0';
    }
    else
    {
#pragma warning(suppress : 4996)
        strncpy(pPeb->guestError.message, (char*)message, length);
    }

    *(uint32_t*)pPeb->outputdata.outputDataBuffer = -1;

    longjmp(jmpbuf, 1);
}

void callHostFunction(char* functionName, va_list ap)
{
    HostFunctionCall* functionCall = (HostFunctionCall*)pPeb->outputdata.outputDataBuffer;
    functionCall->FunctionName = functionName;
    uint64_t* ptr = &functionCall->argv;

    void* arg;

    while (arg = va_arg(ap, void*))
    {
        *ptr++ = arg;
    }

    // TODO: Why is the return code getting output via outb?
    // This only happens if running in Hyperlight and on KVM.

    outb(101, 0);
}
// Calls a Host Function that returns an int
int native_symbol_thunk(char* functionName, ...)
{

    va_list ap = NULL;

    va_start(ap, functionName);

    callHostFunction(functionName, ap);

    va_end(ap);

    return *((int*)pPeb->inputdata.inputDataBuffer);
}
// Calls a Host Function that returns an long
long native_symbol_thunk_returning_long(char* functionName, ...)
{

    va_list ap = NULL;

    va_start(ap, functionName);

    callHostFunction(functionName, ap);

    va_end(ap);

    return *((long*)pPeb->inputdata.inputDataBuffer);
}
// Exposed by Hyperlight Sandbox , used by dlmalloc
long GetHyperLightTickCount()
{
    return native_symbol_thunk_returning_long("GetTickCount");
}

int CallGuestFunction(GuestFunctionDetails* guestfunctionDetails)
{
    guestFunc pFunction = NULL;
    int requiredParameterCount = 0;
    ParameterKind* parameterKind = NULL;

    for (int i = 0; i < funcTable->next; i++)
    {
        if (strcmp(guestfunctionDetails->functionName, funcTable->funcEntry[i]->FunctionName) == 0)
        {
            pFunction = funcTable->funcEntry[i]->pFunction;
            requiredParameterCount = funcTable->funcEntry[i]->paramCount;
            parameterKind = funcTable->funcEntry[i]->parameterKind;
            break;
        }
    }

    if (NULL == pFunction)
    {
        // If the function was not found call the GuestDispatchFunction method optionally provided by the guest program.
        // This allows functions exposed by a guest runtime (e.g. WASM) to be called.
        return GuestDispatchFunction(guestfunctionDetails);
    }

    if (requiredParameterCount != guestfunctionDetails->paramc)
    {
        char message[100] = { 0 };
        snprintf(message, 100, "Called function %s with %d parameters but it takes %d.", guestfunctionDetails->functionName, guestfunctionDetails->paramc, requiredParameterCount);
        setError(GUEST_FUNCTION_INCORRECT_NO_OF_PARAMETERS, message);
    }

    for (int i = 0; i < requiredParameterCount; i++)
    {
        if (guestfunctionDetails->paramv[i].kind != parameterKind[i])
        {
            char message[100] = { 0 };
            snprintf(message, 100, "Function %s parameter %d.", guestfunctionDetails->functionName, guestfunctionDetails->paramc);
            setError(GUEST_FUNCTION_PARAMETER_TYPE_MISMATCH, message);
        }
    }

    return pFunction(guestfunctionDetails->paramv);
}

void DispatchFunction()
{
    GuestFunctionDetails* guestFunctionDetails = NULL;
    Parameter* paramv = NULL;
    // setjmp is used to capture state so that if an error occurs then lngjmp is called in setError and control returns to this point , the if returns false and the program exits/halts
    if (!setjmp(jmpbuf))
    {
        resetError();
        GuestFunctionCall*  funcCall = (GuestFunctionCall*)pPeb->outputdata.outputDataBuffer;

        if (NULL == funcCall->FunctionName)
        {
            setError(GUEST_FUNCTION_NAME_NOT_PROVIDED, NULL);
        }

        guestFunctionDetails = (GuestFunctionDetails*)malloc(sizeof(GuestFunctionDetails));

        if (NULL == guestFunctionDetails)
        {
            setError(MALLOC_FAILED, NULL);
        }
        guestFunctionDetails->functionName = funcCall->FunctionName;
        guestFunctionDetails->paramc = (int32_t)funcCall->argc;

        if (0 == guestFunctionDetails->paramc)
        {
            guestFunctionDetails->paramv = NULL;
        }
        else
        {
            paramv = (Parameter*)malloc(guestFunctionDetails->paramc * sizeof(GuestFunctionDetails));
            if (NULL == paramv)
            {
                setError(MALLOC_FAILED, NULL);
            }
            guestFunctionDetails->paramv = paramv;
        }

        for (int32_t i = 0; i < guestFunctionDetails->paramc; i++)
        {
            GuestArgument guestArgument = funcCall->guestArguments[i];
            switch (guestArgument.argt)
            {
                case (string):
                    guestFunctionDetails->paramv[i].value.string = (char*)guestArgument.argv;
                    guestFunctionDetails->paramv[i].kind = string;
                    break;
                case (i32):
                    guestFunctionDetails->paramv[i].value.i32 = (uint32_t)guestArgument.argv;
                    guestFunctionDetails->paramv[i].kind = i32;
                    break;
                case (i64):
                    guestFunctionDetails->paramv[i].value.i64 = (uint64_t)guestArgument.argv;
                    guestFunctionDetails->paramv[i].kind = i64;
                    break;
                case (boolean):
                    guestFunctionDetails->paramv[i].value.boolean = (bool)guestArgument.argv;
                    guestFunctionDetails->paramv[i].kind = boolean;
                    break;
                default:
                    setError(GUEST_FUNCTION_PARAMETER_TYPE_MISMATCH, NULL);
                    break;
            }
        }

        *(uint32_t*)pPeb->outputdata.outputDataBuffer = CallGuestFunction(guestFunctionDetails);
    }

    free(guestFunctionDetails);
    free(paramv);
    
    halt();  // This is a nop if we were just loaded into memory
}

// this is required by print functions to write output.

void _putchar(char c)
{
    *(char*)pPeb->outputdata.outputDataBuffer = c;
    outb(100, 0);
}

// this is called when /Gs check fails

void report_gsfailure()
{
    setError(GS_CHECK_FAILED, NULL);
}

// Called by dlmalloc using ABORT

void dlmalloc_abort()
{
    setError(FAILURE_IN_DLMALLOC, NULL);
}

// this function is called by dlmalloc to allocate heap memory.

void* hyperlightMoreCore(size_t size)
{
    if (size > 0)
    {
        uint64_t newUnusedHeapBufferPointer;
        if (0 == unusedHeapBufferPointer)
        {
            newUnusedHeapBufferPointer = (uint64_t)pPeb->guestheapData.guestHeapBuffer + size;
        }
        else
        {
            newUnusedHeapBufferPointer = (uint64_t)unusedHeapBufferPointer + size;
        }

        // This should not happen if dlmalloc_set_footprint_limit was called with pPeb->guestheapData.guestHeapSize. 

        if (newUnusedHeapBufferPointer - (uint64_t)pPeb->guestheapData.guestHeapBuffer > pPeb->guestheapData.guestHeapSize)
        {
            return (void*)MFAIL;
        }

        unusedHeapBufferPointer = (void*)newUnusedHeapBufferPointer;
    }
    else if (size < 0)
    {
        // This should not happen according to dlmalloc docs as MORECORE_CANNOT_TRIM is set. 

        return (void*)MFAIL;
    }
    return unusedHeapBufferPointer;
}

#pragma optimize("", on)

__declspec(safebuffers) int entryPoint(uint64_t pebAddress, uint64_t seed, int functionTableSize)
{
    pPeb = (HyperlightPEB*)pebAddress;
    if (NULL == pPeb)
    {
        return -1;
    }

    __security_init_cookie();
    resetError();

    // setjmp is used to capture state so that if an error occurs then lngjmp is called in setError and control returns to this point , the if returns false and the program exits/halts
    if (!setjmp(jmpbuf))
    {
        if (*pPeb->pCode != 'J')
        {
            setError(CODE_HEADER_NOT_SET, NULL);
        }

        // Either in WHP partition (hyperlight) or in memory.  If in memory, outb_ptr will be non-NULL
        outb_ptr = (void(*)(uint16_t, uint8_t))pPeb->pOutb;
        if (outb_ptr)
            runningHyperlight = false;
        HostFunctions* pFuncs = (HostFunctions*)pPeb->hostFunctionDefinitions.functionDefinitions;
        pFuncs->header.DispatchFunction = (uint64_t)DispatchFunction;

        size_t limit = dlmalloc_set_footprint_limit(pPeb->guestheapData.guestHeapSize);

        //TODO: Pass FunctionTablesize in entryPoint.

        InitialiseFunctionTable(0);

        // Call Hyperlightmain in the Guest , the guest can use this to register functions that can be called from the host.

        HyperlightMain();

        // Setup return values
        *(int32_t*)pPeb->outputdata.outputDataBuffer = 0;
    }

    halt(); // This is a nop if we were just loaded into memory
    return 0;
}
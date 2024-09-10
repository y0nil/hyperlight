#ifndef FUNCTION_TYPES_BUILDER_H
#define FUNCTION_TYPES_BUILDER_H

/* Generated by flatcc 0.6.2 FlatBuffers schema compiler for C by dvide.com */

#ifndef FUNCTION_TYPES_READER_H
#include "function_types_reader.h"
#endif
#ifndef FLATBUFFERS_COMMON_BUILDER_H
#include "flatbuffers_common_builder.h"
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension "bin"
#endif

#define __Hyperlight_Generated_ParameterType_formal_args , Hyperlight_Generated_ParameterType_enum_t v0
#define __Hyperlight_Generated_ParameterType_call_args , v0
__flatbuffers_build_scalar(flatbuffers_, Hyperlight_Generated_ParameterType, Hyperlight_Generated_ParameterType_enum_t)
#define __Hyperlight_Generated_ReturnType_formal_args , Hyperlight_Generated_ReturnType_enum_t v0
#define __Hyperlight_Generated_ReturnType_call_args , v0
__flatbuffers_build_scalar(flatbuffers_, Hyperlight_Generated_ReturnType, Hyperlight_Generated_ReturnType_enum_t)

typedef flatbuffers_union_ref_t Hyperlight_Generated_ParameterValue_union_ref_t;
typedef flatbuffers_union_vec_ref_t Hyperlight_Generated_ParameterValue_union_vec_ref_t;
static Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_clone(flatbuffers_builder_t *B, Hyperlight_Generated_ParameterValue_union_t t);
typedef flatbuffers_union_ref_t Hyperlight_Generated_ReturnValue_union_ref_t;
typedef flatbuffers_union_vec_ref_t Hyperlight_Generated_ReturnValue_union_vec_ref_t;
static Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_clone(flatbuffers_builder_t *B, Hyperlight_Generated_ReturnValue_union_t t);

static const flatbuffers_voffset_t __Hyperlight_Generated_hlint_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlint_ref_t;
static Hyperlight_Generated_hlint_ref_t Hyperlight_Generated_hlint_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlint_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlint, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hluint_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hluint_ref_t;
static Hyperlight_Generated_hluint_ref_t Hyperlight_Generated_hluint_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hluint_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hluint, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hllong_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hllong_ref_t;
static Hyperlight_Generated_hllong_ref_t Hyperlight_Generated_hllong_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hllong_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hllong, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlulong_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlulong_ref_t;
static Hyperlight_Generated_hlulong_ref_t Hyperlight_Generated_hlulong_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlulong_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlulong, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlfloat_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlfloat_ref_t;
static Hyperlight_Generated_hlfloat_ref_t Hyperlight_Generated_hlfloat_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlfloat_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlfloat, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hldouble_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hldouble_ref_t;
static Hyperlight_Generated_hldouble_ref_t Hyperlight_Generated_hldouble_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hldouble_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hldouble, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlstring_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlstring_ref_t;
static Hyperlight_Generated_hlstring_ref_t Hyperlight_Generated_hlstring_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlstring_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlstring, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlbool_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlbool_ref_t;
static Hyperlight_Generated_hlbool_ref_t Hyperlight_Generated_hlbool_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlbool_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlbool, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlvecbytes_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlvecbytes_ref_t;
static Hyperlight_Generated_hlvecbytes_ref_t Hyperlight_Generated_hlvecbytes_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlvecbytes_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlvecbytes, 1)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlsizeprefixedbuffer_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlsizeprefixedbuffer_ref_t;
static Hyperlight_Generated_hlsizeprefixedbuffer_ref_t Hyperlight_Generated_hlsizeprefixedbuffer_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlsizeprefixedbuffer_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlsizeprefixedbuffer, 2)

static const flatbuffers_voffset_t __Hyperlight_Generated_hlvoid_required[] = { 0 };
typedef flatbuffers_ref_t Hyperlight_Generated_hlvoid_ref_t;
static Hyperlight_Generated_hlvoid_ref_t Hyperlight_Generated_hlvoid_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlvoid_table_t t);
__flatbuffers_build_table(flatbuffers_, Hyperlight_Generated_hlvoid, 0)

#define __Hyperlight_Generated_hlint_formal_args , int32_t v0
#define __Hyperlight_Generated_hlint_call_args , v0
static inline Hyperlight_Generated_hlint_ref_t Hyperlight_Generated_hlint_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlint_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlint, Hyperlight_Generated_hlint_file_identifier, Hyperlight_Generated_hlint_type_identifier)

#define __Hyperlight_Generated_hluint_formal_args , uint32_t v0
#define __Hyperlight_Generated_hluint_call_args , v0
static inline Hyperlight_Generated_hluint_ref_t Hyperlight_Generated_hluint_create(flatbuffers_builder_t *B __Hyperlight_Generated_hluint_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hluint, Hyperlight_Generated_hluint_file_identifier, Hyperlight_Generated_hluint_type_identifier)

#define __Hyperlight_Generated_hllong_formal_args , int64_t v0
#define __Hyperlight_Generated_hllong_call_args , v0
static inline Hyperlight_Generated_hllong_ref_t Hyperlight_Generated_hllong_create(flatbuffers_builder_t *B __Hyperlight_Generated_hllong_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hllong, Hyperlight_Generated_hllong_file_identifier, Hyperlight_Generated_hllong_type_identifier)

#define __Hyperlight_Generated_hlulong_formal_args , uint64_t v0
#define __Hyperlight_Generated_hlulong_call_args , v0
static inline Hyperlight_Generated_hlulong_ref_t Hyperlight_Generated_hlulong_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlulong_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlulong, Hyperlight_Generated_hlulong_file_identifier, Hyperlight_Generated_hlulong_type_identifier)

#define __Hyperlight_Generated_hlfloat_formal_args , float v0
#define __Hyperlight_Generated_hlfloat_call_args , v0
static inline Hyperlight_Generated_hlfloat_ref_t Hyperlight_Generated_hlfloat_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlfloat_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlfloat, Hyperlight_Generated_hlfloat_file_identifier, Hyperlight_Generated_hlfloat_type_identifier)

#define __Hyperlight_Generated_hldouble_formal_args , double v0
#define __Hyperlight_Generated_hldouble_call_args , v0
static inline Hyperlight_Generated_hldouble_ref_t Hyperlight_Generated_hldouble_create(flatbuffers_builder_t *B __Hyperlight_Generated_hldouble_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hldouble, Hyperlight_Generated_hldouble_file_identifier, Hyperlight_Generated_hldouble_type_identifier)

#define __Hyperlight_Generated_hlstring_formal_args , flatbuffers_string_ref_t v0
#define __Hyperlight_Generated_hlstring_call_args , v0
static inline Hyperlight_Generated_hlstring_ref_t Hyperlight_Generated_hlstring_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlstring_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlstring, Hyperlight_Generated_hlstring_file_identifier, Hyperlight_Generated_hlstring_type_identifier)

#define __Hyperlight_Generated_hlbool_formal_args , flatbuffers_bool_t v0
#define __Hyperlight_Generated_hlbool_call_args , v0
static inline Hyperlight_Generated_hlbool_ref_t Hyperlight_Generated_hlbool_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlbool_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlbool, Hyperlight_Generated_hlbool_file_identifier, Hyperlight_Generated_hlbool_type_identifier)

#define __Hyperlight_Generated_hlvecbytes_formal_args , flatbuffers_uint8_vec_ref_t v0
#define __Hyperlight_Generated_hlvecbytes_call_args , v0
static inline Hyperlight_Generated_hlvecbytes_ref_t Hyperlight_Generated_hlvecbytes_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlvecbytes_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlvecbytes, Hyperlight_Generated_hlvecbytes_file_identifier, Hyperlight_Generated_hlvecbytes_type_identifier)

#define __Hyperlight_Generated_hlsizeprefixedbuffer_formal_args , int32_t v0, flatbuffers_uint8_vec_ref_t v1
#define __Hyperlight_Generated_hlsizeprefixedbuffer_call_args , v0, v1
static inline Hyperlight_Generated_hlsizeprefixedbuffer_ref_t Hyperlight_Generated_hlsizeprefixedbuffer_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlsizeprefixedbuffer_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlsizeprefixedbuffer, Hyperlight_Generated_hlsizeprefixedbuffer_file_identifier, Hyperlight_Generated_hlsizeprefixedbuffer_type_identifier)

#define __Hyperlight_Generated_hlvoid_formal_args 
#define __Hyperlight_Generated_hlvoid_call_args 
static inline Hyperlight_Generated_hlvoid_ref_t Hyperlight_Generated_hlvoid_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlvoid_formal_args);
__flatbuffers_build_table_prolog(flatbuffers_, Hyperlight_Generated_hlvoid, Hyperlight_Generated_hlvoid_file_identifier, Hyperlight_Generated_hlvoid_type_identifier)

static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_NONE(void)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_NONE; uref.value = 0; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hlint(Hyperlight_Generated_hlint_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hlint; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hluint(Hyperlight_Generated_hluint_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hluint; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hllong(Hyperlight_Generated_hllong_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hllong; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hlulong(Hyperlight_Generated_hlulong_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hlulong; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hlfloat(Hyperlight_Generated_hlfloat_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hlfloat; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hldouble(Hyperlight_Generated_hldouble_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hldouble; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hlstring(Hyperlight_Generated_hlstring_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hlstring; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hlbool(Hyperlight_Generated_hlbool_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hlbool; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_as_hlvecbytes(Hyperlight_Generated_hlvecbytes_ref_t ref)
{ Hyperlight_Generated_ParameterValue_union_ref_t uref; uref.type = Hyperlight_Generated_ParameterValue_hlvecbytes; uref.value = ref; return uref; }
__flatbuffers_build_union_vector(flatbuffers_, Hyperlight_Generated_ParameterValue)

static Hyperlight_Generated_ParameterValue_union_ref_t Hyperlight_Generated_ParameterValue_clone(flatbuffers_builder_t *B, Hyperlight_Generated_ParameterValue_union_t u)
{
    switch (u.type) {
    case 1: return Hyperlight_Generated_ParameterValue_as_hlint(Hyperlight_Generated_hlint_clone(B, (Hyperlight_Generated_hlint_table_t)u.value));
    case 2: return Hyperlight_Generated_ParameterValue_as_hluint(Hyperlight_Generated_hluint_clone(B, (Hyperlight_Generated_hluint_table_t)u.value));
    case 3: return Hyperlight_Generated_ParameterValue_as_hllong(Hyperlight_Generated_hllong_clone(B, (Hyperlight_Generated_hllong_table_t)u.value));
    case 4: return Hyperlight_Generated_ParameterValue_as_hlulong(Hyperlight_Generated_hlulong_clone(B, (Hyperlight_Generated_hlulong_table_t)u.value));
    case 5: return Hyperlight_Generated_ParameterValue_as_hlfloat(Hyperlight_Generated_hlfloat_clone(B, (Hyperlight_Generated_hlfloat_table_t)u.value));
    case 6: return Hyperlight_Generated_ParameterValue_as_hldouble(Hyperlight_Generated_hldouble_clone(B, (Hyperlight_Generated_hldouble_table_t)u.value));
    case 7: return Hyperlight_Generated_ParameterValue_as_hlstring(Hyperlight_Generated_hlstring_clone(B, (Hyperlight_Generated_hlstring_table_t)u.value));
    case 8: return Hyperlight_Generated_ParameterValue_as_hlbool(Hyperlight_Generated_hlbool_clone(B, (Hyperlight_Generated_hlbool_table_t)u.value));
    case 9: return Hyperlight_Generated_ParameterValue_as_hlvecbytes(Hyperlight_Generated_hlvecbytes_clone(B, (Hyperlight_Generated_hlvecbytes_table_t)u.value));
    default: return Hyperlight_Generated_ParameterValue_as_NONE();
    }
}

static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_NONE(void)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_NONE; uref.value = 0; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlint(Hyperlight_Generated_hlint_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlint; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hluint(Hyperlight_Generated_hluint_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hluint; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hllong(Hyperlight_Generated_hllong_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hllong; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlulong(Hyperlight_Generated_hlulong_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlulong; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlfloat(Hyperlight_Generated_hlfloat_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlfloat; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hldouble(Hyperlight_Generated_hldouble_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hldouble; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlstring(Hyperlight_Generated_hlstring_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlstring; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlbool(Hyperlight_Generated_hlbool_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlbool; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlvoid(Hyperlight_Generated_hlvoid_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlvoid; uref.value = ref; return uref; }
static inline Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_as_hlsizeprefixedbuffer(Hyperlight_Generated_hlsizeprefixedbuffer_ref_t ref)
{ Hyperlight_Generated_ReturnValue_union_ref_t uref; uref.type = Hyperlight_Generated_ReturnValue_hlsizeprefixedbuffer; uref.value = ref; return uref; }
__flatbuffers_build_union_vector(flatbuffers_, Hyperlight_Generated_ReturnValue)

static Hyperlight_Generated_ReturnValue_union_ref_t Hyperlight_Generated_ReturnValue_clone(flatbuffers_builder_t *B, Hyperlight_Generated_ReturnValue_union_t u)
{
    switch (u.type) {
    case 1: return Hyperlight_Generated_ReturnValue_as_hlint(Hyperlight_Generated_hlint_clone(B, (Hyperlight_Generated_hlint_table_t)u.value));
    case 2: return Hyperlight_Generated_ReturnValue_as_hluint(Hyperlight_Generated_hluint_clone(B, (Hyperlight_Generated_hluint_table_t)u.value));
    case 3: return Hyperlight_Generated_ReturnValue_as_hllong(Hyperlight_Generated_hllong_clone(B, (Hyperlight_Generated_hllong_table_t)u.value));
    case 4: return Hyperlight_Generated_ReturnValue_as_hlulong(Hyperlight_Generated_hlulong_clone(B, (Hyperlight_Generated_hlulong_table_t)u.value));
    case 5: return Hyperlight_Generated_ReturnValue_as_hlfloat(Hyperlight_Generated_hlfloat_clone(B, (Hyperlight_Generated_hlfloat_table_t)u.value));
    case 6: return Hyperlight_Generated_ReturnValue_as_hldouble(Hyperlight_Generated_hldouble_clone(B, (Hyperlight_Generated_hldouble_table_t)u.value));
    case 7: return Hyperlight_Generated_ReturnValue_as_hlstring(Hyperlight_Generated_hlstring_clone(B, (Hyperlight_Generated_hlstring_table_t)u.value));
    case 8: return Hyperlight_Generated_ReturnValue_as_hlbool(Hyperlight_Generated_hlbool_clone(B, (Hyperlight_Generated_hlbool_table_t)u.value));
    case 9: return Hyperlight_Generated_ReturnValue_as_hlvoid(Hyperlight_Generated_hlvoid_clone(B, (Hyperlight_Generated_hlvoid_table_t)u.value));
    case 10: return Hyperlight_Generated_ReturnValue_as_hlsizeprefixedbuffer(Hyperlight_Generated_hlsizeprefixedbuffer_clone(B, (Hyperlight_Generated_hlsizeprefixedbuffer_table_t)u.value));
    default: return Hyperlight_Generated_ReturnValue_as_NONE();
    }
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hlint_value, flatbuffers_int32, int32_t, 4, 4, INT32_C(0), Hyperlight_Generated_hlint)

static inline Hyperlight_Generated_hlint_ref_t Hyperlight_Generated_hlint_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlint_formal_args)
{
    if (Hyperlight_Generated_hlint_start(B)
        || Hyperlight_Generated_hlint_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hlint_end(B);
}

static Hyperlight_Generated_hlint_ref_t Hyperlight_Generated_hlint_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlint_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlint_start(B)
        || Hyperlight_Generated_hlint_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlint_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hluint_value, flatbuffers_uint32, uint32_t, 4, 4, UINT32_C(0), Hyperlight_Generated_hluint)

static inline Hyperlight_Generated_hluint_ref_t Hyperlight_Generated_hluint_create(flatbuffers_builder_t *B __Hyperlight_Generated_hluint_formal_args)
{
    if (Hyperlight_Generated_hluint_start(B)
        || Hyperlight_Generated_hluint_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hluint_end(B);
}

static Hyperlight_Generated_hluint_ref_t Hyperlight_Generated_hluint_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hluint_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hluint_start(B)
        || Hyperlight_Generated_hluint_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hluint_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hllong_value, flatbuffers_int64, int64_t, 8, 8, INT64_C(0), Hyperlight_Generated_hllong)

static inline Hyperlight_Generated_hllong_ref_t Hyperlight_Generated_hllong_create(flatbuffers_builder_t *B __Hyperlight_Generated_hllong_formal_args)
{
    if (Hyperlight_Generated_hllong_start(B)
        || Hyperlight_Generated_hllong_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hllong_end(B);
}

static Hyperlight_Generated_hllong_ref_t Hyperlight_Generated_hllong_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hllong_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hllong_start(B)
        || Hyperlight_Generated_hllong_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hllong_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hlulong_value, flatbuffers_uint64, uint64_t, 8, 8, UINT64_C(0), Hyperlight_Generated_hlulong)

static inline Hyperlight_Generated_hlulong_ref_t Hyperlight_Generated_hlulong_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlulong_formal_args)
{
    if (Hyperlight_Generated_hlulong_start(B)
        || Hyperlight_Generated_hlulong_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hlulong_end(B);
}

static Hyperlight_Generated_hlulong_ref_t Hyperlight_Generated_hlulong_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlulong_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlulong_start(B)
        || Hyperlight_Generated_hlulong_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlulong_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hlfloat_value, flatbuffers_float, float, 4, 4, 0.00000000f, Hyperlight_Generated_hlfloat)

static inline Hyperlight_Generated_hlfloat_ref_t Hyperlight_Generated_hlfloat_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlfloat_formal_args)
{
    if (Hyperlight_Generated_hlfloat_start(B)
        || Hyperlight_Generated_hlfloat_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hlfloat_end(B);
}

static Hyperlight_Generated_hlfloat_ref_t Hyperlight_Generated_hlfloat_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlfloat_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlfloat_start(B)
        || Hyperlight_Generated_hlfloat_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlfloat_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hldouble_value, flatbuffers_double, double, 8, 8, 0.0000000000000000, Hyperlight_Generated_hldouble)

static inline Hyperlight_Generated_hldouble_ref_t Hyperlight_Generated_hldouble_create(flatbuffers_builder_t *B __Hyperlight_Generated_hldouble_formal_args)
{
    if (Hyperlight_Generated_hldouble_start(B)
        || Hyperlight_Generated_hldouble_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hldouble_end(B);
}

static Hyperlight_Generated_hldouble_ref_t Hyperlight_Generated_hldouble_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hldouble_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hldouble_start(B)
        || Hyperlight_Generated_hldouble_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hldouble_end(B));
}

__flatbuffers_build_string_field(0, flatbuffers_, Hyperlight_Generated_hlstring_value, Hyperlight_Generated_hlstring)

static inline Hyperlight_Generated_hlstring_ref_t Hyperlight_Generated_hlstring_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlstring_formal_args)
{
    if (Hyperlight_Generated_hlstring_start(B)
        || Hyperlight_Generated_hlstring_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hlstring_end(B);
}

static Hyperlight_Generated_hlstring_ref_t Hyperlight_Generated_hlstring_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlstring_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlstring_start(B)
        || Hyperlight_Generated_hlstring_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlstring_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hlbool_value, flatbuffers_bool, flatbuffers_bool_t, 1, 1, UINT8_C(0), Hyperlight_Generated_hlbool)

static inline Hyperlight_Generated_hlbool_ref_t Hyperlight_Generated_hlbool_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlbool_formal_args)
{
    if (Hyperlight_Generated_hlbool_start(B)
        || Hyperlight_Generated_hlbool_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hlbool_end(B);
}

static Hyperlight_Generated_hlbool_ref_t Hyperlight_Generated_hlbool_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlbool_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlbool_start(B)
        || Hyperlight_Generated_hlbool_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlbool_end(B));
}

__flatbuffers_build_vector_field(0, flatbuffers_, Hyperlight_Generated_hlvecbytes_value, flatbuffers_uint8, uint8_t, Hyperlight_Generated_hlvecbytes)

static inline Hyperlight_Generated_hlvecbytes_ref_t Hyperlight_Generated_hlvecbytes_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlvecbytes_formal_args)
{
    if (Hyperlight_Generated_hlvecbytes_start(B)
        || Hyperlight_Generated_hlvecbytes_value_add(B, v0)) {
        return 0;
    }
    return Hyperlight_Generated_hlvecbytes_end(B);
}

static Hyperlight_Generated_hlvecbytes_ref_t Hyperlight_Generated_hlvecbytes_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlvecbytes_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlvecbytes_start(B)
        || Hyperlight_Generated_hlvecbytes_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlvecbytes_end(B));
}

__flatbuffers_build_scalar_field(0, flatbuffers_, Hyperlight_Generated_hlsizeprefixedbuffer_size, flatbuffers_int32, int32_t, 4, 4, INT32_C(0), Hyperlight_Generated_hlsizeprefixedbuffer)
__flatbuffers_build_vector_field(1, flatbuffers_, Hyperlight_Generated_hlsizeprefixedbuffer_value, flatbuffers_uint8, uint8_t, Hyperlight_Generated_hlsizeprefixedbuffer)

static inline Hyperlight_Generated_hlsizeprefixedbuffer_ref_t Hyperlight_Generated_hlsizeprefixedbuffer_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlsizeprefixedbuffer_formal_args)
{
    if (Hyperlight_Generated_hlsizeprefixedbuffer_start(B)
        || Hyperlight_Generated_hlsizeprefixedbuffer_size_add(B, v0)
        || Hyperlight_Generated_hlsizeprefixedbuffer_value_add(B, v1)) {
        return 0;
    }
    return Hyperlight_Generated_hlsizeprefixedbuffer_end(B);
}

static Hyperlight_Generated_hlsizeprefixedbuffer_ref_t Hyperlight_Generated_hlsizeprefixedbuffer_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlsizeprefixedbuffer_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlsizeprefixedbuffer_start(B)
        || Hyperlight_Generated_hlsizeprefixedbuffer_size_pick(B, t)
        || Hyperlight_Generated_hlsizeprefixedbuffer_value_pick(B, t)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlsizeprefixedbuffer_end(B));
}


static inline Hyperlight_Generated_hlvoid_ref_t Hyperlight_Generated_hlvoid_create(flatbuffers_builder_t *B __Hyperlight_Generated_hlvoid_formal_args)
{
    if (Hyperlight_Generated_hlvoid_start(B)) {
        return 0;
    }
    return Hyperlight_Generated_hlvoid_end(B);
}

static Hyperlight_Generated_hlvoid_ref_t Hyperlight_Generated_hlvoid_clone(flatbuffers_builder_t *B, Hyperlight_Generated_hlvoid_table_t t)
{
    __flatbuffers_memoize_begin(B, t);
    if (Hyperlight_Generated_hlvoid_start(B)) {
        return 0;
    }
    __flatbuffers_memoize_end(B, t, Hyperlight_Generated_hlvoid_end(B));
}

#include "flatcc/flatcc_epilogue.h"
#endif /* FUNCTION_TYPES_BUILDER_H */

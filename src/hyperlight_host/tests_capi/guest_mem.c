#include "guest_mem.h"
#include "munit/munit.h"
#include "hyperlight_host.h"
#include "stdint.h"
#include "mem.h"
#include "err.h"

static const uint64_t GUEST_MEM_SIZE = 3200;

MunitResult test_guest_mem_create_delete()
{
    Context *ctx = context_new();
    Handle ref = guest_memory_new(ctx, GUEST_MEM_SIZE);
    handle_free(ctx, ref);
    context_free(ctx);
    return MUNIT_OK;
}

#define READ_WRITE_READ_VALID(check_fn, read_fn, write_fn, int_convert_fn, ctx, ref, addr, val) \
    Handle init_ref = (*read_fn)(ctx, ref, addr);                                               \
    munit_assert_true(check_fn(ctx, init_ref));                                                 \
    Handle set_ref = (*write_fn)(ctx, ref, addr, val);                                          \
    handle_assert_no_error(ctx, set_ref);                                                       \
    Handle read_ref = (*read_fn)(ctx, ref, addr);                                               \
    munit_assert_true((*check_fn)(ctx, read_ref));                                              \
    munit_assert_int(val, ==, (*int_convert_fn)(ctx, read_ref));                                \
    handle_free(ctx, init_ref);                                                                 \
    handle_free(ctx, set_ref);                                                                  \
    handle_free(ctx, read_ref);

#define READ_WRITE_READ_INVALID(read_fn, write_fn, ctx, addr) \
    Handle init_ref = (*read_fn)(ctx, ref, addr);             \
    handle_assert_error(ctx, init_ref);                       \
    Handle set_ref = (*write_fn)(ctx, ref, addr, 8000);       \
    handle_assert_error(ctx, set_ref);                        \
    Handle read_ref = (*read_fn)(ctx, ref, addr);             \
    handle_assert_error(ctx, read_ref);                       \
    handle_free(ctx, init_ref);                               \
    handle_free(ctx, set_ref);                                \
    handle_free(ctx, read_ref);

MunitResult test_guest_mem_read_write()
{
    {
        // read-write-read an i64
        Context *ctx = context_new();
        Handle ref = guest_memory_new(ctx, GUEST_MEM_SIZE);

        {
            // valid address
            READ_WRITE_READ_VALID(
                handle_is_int_64,
                guest_memory_read_int_64,
                guest_memory_write_int_64,
                handle_get_int_64,
                ctx,
                ref,
                GUEST_MEM_SIZE / 2,
                4000);
        }

        {
            // invalid address
            READ_WRITE_READ_INVALID(
                guest_memory_read_int_64,
                guest_memory_write_int_64,
                ctx,
                GUEST_MEM_SIZE * 4);
        }
        handle_free(ctx, ref);
        context_free(ctx);
    }
    {
        // read-write-read an i32
        Context *ctx = context_new();
        Handle ref = guest_memory_new(ctx, GUEST_MEM_SIZE);

        {
            // valid address
            READ_WRITE_READ_VALID(
                handle_is_int_32,
                guest_memory_read_int_32,
                guest_memory_write_int_32,
                handle_get_int_32,
                ctx,
                ref,
                GUEST_MEM_SIZE / 2,
                6000);
        }
        {
            // invalid address
            READ_WRITE_READ_INVALID(
                guest_memory_read_int_32,
                guest_memory_write_int_32,
                ctx,
                GUEST_MEM_SIZE * 4);
        }
        handle_free(ctx, ref);
        context_free(ctx);
    }

    return MUNIT_OK;
}

MunitResult test_guest_mem_copy_byte_array()
{
    Context *ctx = context_new();
    Handle ref = guest_memory_new(ctx, GUEST_MEM_SIZE);
    {
        const int len = 1;

        // copy a very small byte array to the very beginning
        // of guest memory
        uint8_t *mem = create_u8_mem(len, true);
        Handle barr_ref = byte_array_new(ctx, mem, len);
        Handle copy_ref_start = guest_memory_copy_byte_array(
            ctx,
            ref,
            barr_ref,
            0,
            0,
            len);
        handle_assert_no_error(ctx, copy_ref_start);
        handle_free(ctx, copy_ref_start);

        // copy the same small byte array to the very end of
        // guest memory
        Handle copy_ref_end = guest_memory_copy_byte_array(
            ctx,
            ref,
            barr_ref,
            GUEST_MEM_SIZE - 2,
            0,
            len);
        handle_assert_no_error(ctx, copy_ref_end);
        handle_free(ctx, copy_ref_end);
        handle_free(ctx, copy_ref_end);

        // copy the same small byte array to an invalid address.
        Handle copy_ref_invalid_addr = guest_memory_copy_byte_array(
            ctx,
            ref,
            barr_ref,
            GUEST_MEM_SIZE + 2,
            0,
            1);
        handle_assert_error(ctx, copy_ref_invalid_addr);
        handle_free(ctx, copy_ref_invalid_addr);

        // copy too much of the small byte array
        Handle copy_ref_arr_too_long = guest_memory_copy_byte_array(
            ctx,
            ref,
            barr_ref,
            5,
            0,
            len * 10);
        handle_assert_error(ctx, copy_ref_arr_too_long);
        handle_free(ctx, copy_ref_arr_too_long);

        // copy the small byte array starting at an invalid
        // array index
        Handle copy_ref_arr_invalid_idx = guest_memory_copy_byte_array(
            ctx,
            ref,
            barr_ref,
            10,
            len * 10,
            1);
        handle_assert_error(ctx, copy_ref_arr_invalid_idx);
        handle_free(ctx, copy_ref_arr_invalid_idx);

        handle_free(ctx, barr_ref);
        free(mem);
    }
    handle_free(ctx, ref);
    context_free(ctx);
    return MUNIT_OK;
}
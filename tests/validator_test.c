/*
* Mathi C Library - validator_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include "mathi/validator.h"

static void print_check(const char *label, const char *input, int result)
{
    printf("%s(\"%s\") = %s\n", label, input, result ? "true" : "false");
}

static void print_range_check(const char *label, int value, int min, int max, int result)
{
    printf("%s(%d, %d, %d) = %s\n", label, value, min, max, result ? "true" : "false");
}

void test_validator()
{
    printf("Starting validator tests...\n\n");

    // Numeric checks
    print_check("mathi_is_int", "123", mathi_is_int("123"));
    assert(mathi_is_int("123"));

    print_check("mathi_is_int", "12.3", mathi_is_int("12.3"));
    assert(!mathi_is_int("12.3"));

    print_check("mathi_is_float", "12.3", mathi_is_float("12.3"));
    assert(mathi_is_float("12.3"));

    print_check("mathi_is_float", "abc", mathi_is_float("abc"));
    assert(!mathi_is_float("abc"));

    print_check("mathi_is_double", "12.34", mathi_is_double("12.34"));
    assert(mathi_is_double("12.34"));

    print_check("mathi_is_double", "12.3a", mathi_is_double("12.3a"));
    assert(!mathi_is_double("12.3a"));

    print_check("mathi_is_number", "12", mathi_is_number("12"));
    assert(mathi_is_number("12"));

    print_check("mathi_is_number", "12.3", mathi_is_number("12.3"));
    assert(mathi_is_number("12.3"));

    print_check("mathi_is_number", "abc", mathi_is_number("abc"));
    assert(!mathi_is_number("abc"));

    printf("\n");

    // Character checks
    print_check("mathi_is_alpha", "abcXYZ", mathi_is_alpha("abcXYZ"));
    assert(mathi_is_alpha("abcXYZ"));

    print_check("mathi_is_alpha", "abc123", mathi_is_alpha("abc123"));
    assert(!mathi_is_alpha("abc123"));

    print_check("mathi_is_alnum", "abc123", mathi_is_alnum("abc123"));
    assert(mathi_is_alnum("abc123"));

    print_check("mathi_is_alnum", "abc!123", mathi_is_alnum("abc!123"));
    assert(!mathi_is_alnum("abc!123"));

    print_check("mathi_is_binary", "010101", mathi_is_binary("010101"));
    assert(mathi_is_binary("010101"));

    print_check("mathi_is_binary", "01201", mathi_is_binary("01201"));
    assert(!mathi_is_binary("01201"));

    print_check("mathi_is_hex", "1a2B3C", mathi_is_hex("1a2B3C"));
    assert(mathi_is_hex("1a2B3C"));

    print_check("mathi_is_hex", "1G3H", mathi_is_hex("1G3H"));
    assert(!mathi_is_hex("1G3H"));

    printf("\n");

    // Range checks
    print_range_check("mathi_in_range", 5, 0, 10, mathi_in_range(5, 0, 10));
    assert(mathi_in_range(5, 0, 10));

    print_range_check("mathi_in_range", -1, 0, 10, mathi_in_range(-1, 0, 10));
    assert(!mathi_in_range(-1, 0, 10));

    print_range_check("mathi_in_range", 10, 0, 10, mathi_in_range(10, 0, 10));
    assert(mathi_in_range(10, 0, 10));

    printf("\nAll validator tests passed!\n");
}

int main()
{
    test_validator();
    return 0;
}
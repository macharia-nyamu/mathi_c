/*
* Mathi C Library - validator_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include "mathi/validator.h"

static void print_check(const char *label, const char *input, int result) {
    printf("%s(\"%s\") = %s\n", label, input, result ? "true" : "false");
}

static void print_range_check(const char *label, int value, int min, int max, int result) {
    printf("%s(%d, %d, %d) = %s\n", label, value, min, max, result ? "true" : "false");
}

void test_validator() {
    printf("Starting validator tests...\n\n");

    // Numeric checks
    print_check("is_int", "123", is_int("123"));
    assert(is_int("123"));

    print_check("is_int", "12.3", is_int("12.3"));
    assert(!is_int("12.3"));

    print_check("is_float", "12.3", is_float("12.3"));
    assert(is_float("12.3"));

    print_check("is_float", "abc", is_float("abc"));
    assert(!is_float("abc"));

    print_check("is_double", "12.34", is_double("12.34"));
    assert(is_double("12.34"));

    print_check("is_double", "12.3a", is_double("12.3a"));
    assert(!is_double("12.3a"));

    print_check("is_number", "12", is_number("12"));
    assert(is_number("12"));

    print_check("is_number", "12.3", is_number("12.3"));
    assert(is_number("12.3"));

    print_check("is_number", "abc", is_number("abc"));
    assert(!is_number("abc"));

    printf("\n");

    // Character checks
    print_check("is_alpha", "abcXYZ", is_alpha("abcXYZ"));
    assert(is_alpha("abcXYZ"));

    print_check("is_alpha", "abc123", is_alpha("abc123"));
    assert(!is_alpha("abc123"));

    print_check("is_alnum", "abc123", is_alnum("abc123"));
    assert(is_alnum("abc123"));

    print_check("is_alnum", "abc!123", is_alnum("abc!123"));
    assert(!is_alnum("abc!123"));

    print_check("is_binary", "010101", is_binary("010101"));
    assert(is_binary("010101"));

    print_check("is_binary", "01201", is_binary("01201"));
    assert(!is_binary("01201"));

    print_check("is_hex", "1a2B3C", is_hex("1a2B3C"));
    assert(is_hex("1a2B3C"));

    print_check("is_hex", "1G3H", is_hex("1G3H"));
    assert(!is_hex("1G3H"));

    printf("\n");

    // Range checks
    print_range_check("is_in_range", 5, 0, 10, is_in_range(5, 0, 10));
    assert(is_in_range(5, 0, 10));

    print_range_check("is_in_range", -1, 0, 10, is_in_range(-1, 0, 10));
    assert(!is_in_range(-1, 0, 10));

    print_range_check("is_in_range", 10, 0, 10, is_in_range(10, 0, 10));
    assert(is_in_range(10, 0, 10));

    printf("\nAll validator tests passed!\n");
}

int main() {
    test_validator();
    return 0;
}
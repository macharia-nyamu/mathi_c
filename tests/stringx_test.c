/*
* Mathi C Library - string_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mathi/stringx.h"
#include "mathi/print.h"

void test_strings()
{
    char buf[50];

    // Reverse
    strcpy(buf, "hello");
    printf("Original string:\n");
    mathi_prnt_str("buf", buf);
    mathi_string_reverse(buf);
    mathi_prnt_str("Reversed", buf);
    assert(strcmp(buf, "olleh") == 0);
    printf("Reverse test passed!\n\n");

    // Index, contains, count
    printf("Testing string_index_of, string_contains, string_count_char...\n");
    int idx = mathi_string_index_of("apple", 'p');
    printf("Index of 'p' in \"apple\": %d\n", idx);
    assert(idx == 1);

    int contains = mathi_string_contains("apple", 'z');
    printf("Contains 'z' in \"apple\": %d\n", contains);
    assert(contains == 0);

    int count = mathi_string_count_char("banana", 'a');
    printf("Count of 'a' in \"banana\": %d\n", count);
    assert(count == 3);
    printf("Index/Contains/Count tests passed!\n\n");

    // Upper & lower
    strcpy(buf, "Hello");
    printf("Original string for case conversion:\n");
    mathi_prnt_str("buf", buf);
    mathi_string_to_upper(buf);
    mathi_prnt_str("Uppercase", buf);
    assert(strcmp(buf, "HELLO") == 0);
    mathi_string_to_lower(buf);
    mathi_prnt_str("Lowercase", buf);
    assert(strcmp(buf, "hello") == 0);
    printf("Case conversion tests passed!\n\n");

    // Length
    int len = mathi_string_length("abc");
    printf("Length of \"abc\": %d\n", len);
    assert(len == 3);
    printf("Length test passed!\n\n");

    // Concat & copy
    strcpy(buf, "foo");
    printf("Original string for concat/copy:\n");
    mathi_prnt_str("buf", buf);
    mathi_string_concat(buf, "bar");
    mathi_prnt_str("After concat \"bar\"", buf);
    assert(strcmp(buf, "foobar") == 0);
    mathi_string_copy(buf, "baz");
    mathi_prnt_str("After copy \"baz\"", buf);
    assert(strcmp(buf, "baz") == 0);
    printf("Concat/Copy tests passed!\n\n");

    // Compare
    int cmp1 = mathi_string_compare("abc", "abc");
    int cmp2 = mathi_string_compare("abc", "abd");
    printf("Compare \"abc\" vs \"abc\": %d\n", cmp1);
    printf("Compare \"abc\" vs \"abd\": %d\n", cmp2);
    assert(cmp1 == 0 && cmp2 < 0);
    printf("Compare tests passed!\n\n");

    // Starts/Ends with
    int starts = mathi_string_starts_with("hello", "he");
    int ends = mathi_string_ends_with("hello", "lo");
    printf("Starts with \"he\"? %d\n", starts);
    printf("Ends with \"lo\"? %d\n", ends);
    assert(starts == 1 && ends == 1);
    printf("Starts/Ends tests passed!\n\n");

    // Trim
    strcpy(buf, "  hi  ");
    printf("Original string for trim:\n");
    mathi_prnt_str("buf", buf);
    mathi_string_trim(buf);
    mathi_prnt_str("Trimmed", buf);
    assert(strcmp(buf, "hi") == 0);
    printf("Trim test passed!\n\n");

    // Replace
    strcpy(buf, "banana");
    printf("Original string for replace:\n");
    mathi_prnt_str("buf", buf);
    mathi_string_replace(buf, 'a', 'o');
    mathi_prnt_str("After replace 'a'->'o'", buf);
    assert(strcmp(buf, "bonono") == 0);
    printf("Replace test passed!\n\n");

    printf("All string tests passed!\n");
}

int main()
{
    test_strings();
    return 0;
}
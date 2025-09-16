/*
* Mathi C Library - util_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include "mathi/util.h"
#include "mathi/print.h"

void test_util()
{
    printf("Starting utility function tests...\n\n");

    // Swap int
    int a = 5, b = 10;
    mathi_prnt_int_pair("Before swap_int", a, b);
    mathi_swap_int(&a, &b);
    mathi_prnt_int_pair("After swap_int", a, b);
    assert(a == 10 && b == 5);
    printf("swap_int test passed!\n\n");

    // Swap double
    double x = 1.5, y = 2.5;
    mathi_prnt_double_pair("Before swap_double", x, y);
    mathi_swap_double(&x, &y);
    mathi_prnt_double_pair("After swap_double", x, y);
    assert(x == 2.5 && y == 1.5);
    printf("swap_double test passed!\n\n");

    // Swap char
    char c1 = 'A', c2 = 'B';
    mathi_prnt_char_pair("Before swap_char", c1, c2);
    mathi_swap_char(&c1, &c2);
    mathi_prnt_char_pair("After swap_char", c1, c2);
    assert(c1 == 'B' && c2 == 'A');
    printf("swap_char test passed!\n\n");

    // Clamp int
    printf("Clamp int tests:\n");
    printf("mathi_clamp_int(5,0,10) = %d\n", mathi_clamp_int(5, 0, 10));
    printf("mathi_clamp_int(-5,0,10) = %d\n", mathi_clamp_int(-5, 0, 10));
    printf("mathi_clamp_int(15,0,10) = %d\n", mathi_clamp_int(15, 0, 10));
    assert(mathi_clamp_int(5, 0, 10) == 5);
    assert(mathi_clamp_int(-5, 0, 10) == 0);
    assert(mathi_clamp_int(15, 0, 10) == 10);
    printf("mathi_clamp_int tests passed!\n\n");

    // Clamp double
    printf("Clamp double tests:\n");
    printf("mathi_clamp_double(3.5,1.0,3.0) = %.3f\n", mathi_clamp_double(3.5, 1.0, 3.0));
    printf("mathi_clamp_double(0.5,1.0,3.0) = %.3f\n", mathi_clamp_double(0.5, 1.0, 3.0));
    assert(mathi_clamp_double(3.5, 1.0, 3.0) == 3.0);
    assert(mathi_clamp_double(0.5, 1.0, 3.0) == 1.0);
    printf("mathi_clamp_double tests passed!\n\n");

    // Memory operations
    char mem1[3] = {1,2,3}, mem2[3] = {4,5,6};
    mathi_prnt_mem("Before mem_swap mem1", mem1, 3);
    mathi_prnt_mem("Before mem_swap mem2", mem2, 3);
    mathi_mem_swap(mem1, mem2, 3);
    mathi_prnt_mem("After mem_swap mem1", mem1, 3);
    mathi_prnt_mem("After mem_swap mem2", mem2, 3);
    assert(mem1[0] == 4 && mem2[2] == 3);
    printf("mem_swap test passed!\n\n");

    mathi_mem_zero(mem1, 3);
    mathi_prnt_mem("After mem_zero mem1", mem1, 3);
    assert(mem1[0] == 0 && mem1[2] == 0);
    printf("mem_zero test passed!\n\n");

    char src[3] = {7,8,9}, dst[3];
    mathi_prnt_mem("Source before mem_copy", src, 3);
    mathi_mem_copy(dst, src, 3);
    mathi_prnt_mem("Destination after mem_copy", dst, 3);
    assert(dst[1] == 8);
    printf("mem_copy test passed!\n\n");

    printf("All util tests passed!\n");
}

int main()
{
    test_util();
    return 0;
}
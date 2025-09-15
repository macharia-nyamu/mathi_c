/*
* Mathi C Library - util_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mathi/util.h"

static void print_int_pair(const char *label, int a, int b) {
    printf("%s: a=%d, b=%d\n", label, a, b);
}

static void print_double_pair(const char *label, double x, double y) {
    printf("%s: x=%.3f, y=%.3f\n", label, x, y);
}

static void print_char_pair(const char *label, char c1, char c2) {
    printf("%s: c1='%c', c2='%c'\n", label, c1, c2);
}

static void print_mem(const char *label, char *mem, size_t n) {
    printf("%s: [", label);
    for(size_t i = 0; i < n; i++) {
        printf("%d", (unsigned char)mem[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

void test_util() {
    printf("Starting utility function tests...\n\n");

    // Swap int
    int a = 5, b = 10;
    print_int_pair("Before swap_int", a, b);
    swap_int(&a, &b);
    print_int_pair("After swap_int", a, b);
    assert(a == 10 && b == 5);
    printf("swap_int test passed!\n\n");

    // Swap double
    double x = 1.5, y = 2.5;
    print_double_pair("Before swap_double", x, y);
    swap_double(&x, &y);
    print_double_pair("After swap_double", x, y);
    assert(x == 2.5 && y == 1.5);
    printf("swap_double test passed!\n\n");

    // Swap char
    char c1 = 'A', c2 = 'B';
    print_char_pair("Before swap_char", c1, c2);
    swap_char(&c1, &c2);
    print_char_pair("After swap_char", c1, c2);
    assert(c1 == 'B' && c2 == 'A');
    printf("swap_char test passed!\n\n");

    // Clamp int
    printf("Clamp int tests:\n");
    printf("clamp_int(5,0,10) = %d\n", clamp_int(5, 0, 10));
    printf("clamp_int(-5,0,10) = %d\n", clamp_int(-5, 0, 10));
    printf("clamp_int(15,0,10) = %d\n", clamp_int(15, 0, 10));
    assert(clamp_int(5, 0, 10) == 5);
    assert(clamp_int(-5, 0, 10) == 0);
    assert(clamp_int(15, 0, 10) == 10);
    printf("clamp_int tests passed!\n\n");

    // Clamp double
    printf("Clamp double tests:\n");
    printf("clamp_double(3.5,1.0,3.0) = %.3f\n", clamp_double(3.5, 1.0, 3.0));
    printf("clamp_double(0.5,1.0,3.0) = %.3f\n", clamp_double(0.5, 1.0, 3.0));
    assert(clamp_double(3.5, 1.0, 3.0) == 3.0);
    assert(clamp_double(0.5, 1.0, 3.0) == 1.0);
    printf("clamp_double tests passed!\n\n");

    // Memory operations
    char mem1[3] = {1,2,3}, mem2[3] = {4,5,6};
    print_mem("Before mem_swap", mem1, 3);
    print_mem("Before mem_swap", mem2, 3);
    mem_swap(mem1, mem2, 3);
    print_mem("After mem_swap", mem1, 3);
    print_mem("After mem_swap", mem2, 3);
    assert(mem1[0] == 4 && mem2[2] == 3);
    printf("mem_swap test passed!\n\n");

    mem_zero(mem1, 3);
    print_mem("After mem_zero mem1", mem1, 3);
    assert(mem1[0] == 0 && mem1[2] == 0);
    printf("mem_zero test passed!\n\n");

    char src[3] = {7,8,9}, dst[3];
    print_mem("Source before mem_copy", src, 3);
    mem_copy(dst, src, 3);
    print_mem("Destination after mem_copy", dst, 3);
    assert(dst[1] == 8);
    printf("mem_copy test passed!\n\n");

    printf("All util tests passed!\n");
}

int main() {
    test_util();
    return 0;
}
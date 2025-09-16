/*
* Mathi C Library - search_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/search.h"

void test_search_algorithms()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Linear search
    printf("Testing linear_search...\n");
    assert(mathi_linear_search(arr, n, 7) == 3);
    assert(mathi_linear_search(arr, n, 2) == -1);

    // Binary search
    printf("Testing binary_search...\n");
    assert(mathi_binary_search(arr, n, 11) == 5);
    assert(mathi_binary_search(arr, n, 8) == -1);

    // Jump search
    printf("Testing jump_search...\n");
    assert(mathi_jump_search(arr, n, 1) == 0);
    assert(mathi_jump_search(arr, n, 16) == -1);

    // Interpolation search
    printf("Testing interpolation_search...\n");
    assert(mathi_interpolation_search(arr, n, 15) == 7);
    assert(mathi_interpolation_search(arr, n, 4) == -1);

    printf("All search algorithm tests passed successfully!\n");
}

int main()
{
    test_search_algorithms();
    return 0;
}
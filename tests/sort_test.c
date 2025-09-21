/*
* Mathi C Library - sort_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mathi/sort.h"
#include "mathi/print.h"
#include "mathi/array.h"

void test_sort_algorithms()
{
    int original[] = {5, 3, 8, 1, 2, 7, 4, 6};
    int n = sizeof(original)/sizeof(original[0]);
    int arr[8];

    printf("Original array:\n");
    mathi_prnt_arr(original, n, "Original");
    printf("\n");

    // Bubble sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Bubble Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_bubble_sort(arr, n);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Bubble Sort passed!\n\n");

    // Selection sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Selection Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_selection_sort(arr, n);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Selection Sort passed!\n\n");

    // Insertion sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Insertion Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_insertion_sort(arr, n);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Insertion Sort passed!\n\n");

    // Merge sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Merge Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_merge_sort(arr, n);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Merge Sort passed!\n\n");

    // Quick sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Quick Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_quick_sort(arr, n);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Quick Sort passed!\n\n");

    // Heap sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Heap Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_heap_sort(arr, n);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Heap Sort passed!\n\n");

    // Counting sort (max = 8)
    memcpy(arr, original, sizeof(original));
    printf("Testing Counting Sort...\n");
    mathi_prnt_arr(arr, n, "Before");
    mathi_counting_sort(arr, n, 8);
    mathi_prnt_arr(arr, n, "After");
    assert(mathi_arr_sorted(arr, n));
    printf("Counting Sort passed!\n\n");

    printf("All sort algorithm tests passed!\n");
}

int main()
{
    test_sort_algorithms();
    return 0;
}
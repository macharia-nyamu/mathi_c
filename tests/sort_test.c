/*
* Mathi C Library - sort_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mathi/sort.h"  // your file with all the sorting functions

static int is_sorted(int *arr, int n) {
    for(int i = 1; i < n; i++) if(arr[i-1] > arr[i]) return 0;
    return 1;
}

static void print_array(const char *label, int *arr, int n) {
    printf("%s: [", label);
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

void test_sort_algorithms() {
    int original[] = {5, 3, 8, 1, 2, 7, 4, 6};
    int n = sizeof(original)/sizeof(original[0]);
    int arr[8];

    printf("Original array:\n");
    print_array("Original", original, n);
    printf("\n");

    // Bubble sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Bubble Sort...\n");
    print_array("Before", arr, n);
    bubble_sort(arr, n);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Bubble Sort passed!\n\n");

    // Selection sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Selection Sort...\n");
    print_array("Before", arr, n);
    selection_sort(arr, n);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Selection Sort passed!\n\n");

    // Insertion sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Insertion Sort...\n");
    print_array("Before", arr, n);
    insertion_sort(arr, n);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Insertion Sort passed!\n\n");

    // Merge sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Merge Sort...\n");
    print_array("Before", arr, n);
    merge_sort(arr, n);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Merge Sort passed!\n\n");

    // Quick sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Quick Sort...\n");
    print_array("Before", arr, n);
    quick_sort(arr, n);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Quick Sort passed!\n\n");

    // Heap sort
    memcpy(arr, original, sizeof(original));
    printf("Testing Heap Sort...\n");
    print_array("Before", arr, n);
    heap_sort(arr, n);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Heap Sort passed!\n\n");

    // Counting sort (max = 8)
    memcpy(arr, original, sizeof(original));
    printf("Testing Counting Sort...\n");
    print_array("Before", arr, n);
    counting_sort(arr, n, 8);
    print_array("After", arr, n);
    assert(is_sorted(arr, n));
    printf("Counting Sort passed!\n\n");

    printf("All sort algorithm tests passed!\n");
}

int main() {
    test_sort_algorithms();
    return 0;
}
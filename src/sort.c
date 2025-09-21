/*
* Mathi C Library - Sorting Algorithms
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Sort an integer array using Bubble Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 */
void mathi_bubble_sort(int *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1]) 
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

/**
 * @brief Sort an integer array using Selection Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 */
void mathi_selection_sort(int *arr, int n)
{
    for(int i = 0; i < n - 1; i++) 
    {
        int min = i;
        for(int j = i + 1; j < n; j++) 
            if(arr[j] < arr[min]) min = j;
        if(min != i) 
        {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

/**
 * @brief Sort an integer array using Insertion Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 */
void mathi_insertion_sort(int *arr, int n)
{
    for(int i = 1; i < n; i++) 
    {
        int key = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Merge two subarrays of an array (helper for Merge Sort).
 * @param arr Array to merge.
 * @param l Left index.
 * @param m Middle index.
 * @param r Right index.
 */
static void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int)), *R = malloc(n2 * sizeof(int));
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) arr[k++] = (L[i] <= R[j] ? L[i++] : R[j++]);
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

/**
 * @brief Recursive Merge Sort implementation.
 * @param arr Array to sort.
 * @param l Left index.
 * @param r Right index.
 */
static void merge_sort_rec(int *arr, int l, int r)
{
    if(l < r) 
    {
        int m = l + (r - l) / 2;
        merge_sort_rec(arr, l, m);
        merge_sort_rec(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * @brief Sort an integer array using Merge Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 */
void mathi_merge_sort(int *arr, int n)
{
    merge_sort_rec(arr, 0, n - 1);
}

/**
 * @brief Partition function for Quick Sort.
 * @param arr Array to partition.
 * @param low Starting index.
 * @param high Ending index.
 * @return Index of the pivot element after partition.
 */
static int mathi_partition(int *arr, int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for(int j = low; j < high; j++) 
        if(arr[j] <= pivot) 
        {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }

    int tmp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = tmp;

    return i + 1;
}

/**
 * @brief Recursive Quick Sort implementation.
 * @param arr Array to sort.
 * @param low Starting index.
 * @param high Ending index.
 */
static void quick_sort_rec(int *arr, int low, int high)
{
    if(low < high) 
    {
        int pi = mathi_partition(arr, low, high);
        quick_sort_rec(arr, low, pi - 1);
        quick_sort_rec(arr, pi + 1, high);
    }
}

/**
 * @brief Sort an integer array using Quick Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 */
void mathi_quick_sort(int *arr, int n)
{
    quick_sort_rec(arr, 0, n - 1);
}

/**
 * @brief Heapify function for Heap Sort.
 * @param arr Array to heapify.
 * @param n Size of the heap.
 * @param i Index to heapify at.
 */
static void heapify(int *arr, int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;

    if(largest != i) 
    {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}

/**
 * @brief Sort an integer array using Heap Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 */
void mathi_heap_sort(int *arr, int n)
{
    for(int i = n/2 -1; i >= 0; i--) heapify(arr, n, i);
    for(int i = n -1; i > 0; i--) 
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

/**
 * @brief Sort an integer array using Counting Sort.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @param max Maximum value in the array.
 */
void mathi_counting_sort(int *arr, int n, int max)
{
    int *count = calloc(max + 1, sizeof(int));
    for(int i = 0; i < n; i++) count[arr[i]]++;
    int idx = 0;
    for(int i = 0; i <= max; i++) while(count[i]-- > 0) arr[idx++] = i;
    free(count);
}
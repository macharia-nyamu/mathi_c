/**
 * Mathi C Library - Sorting Algorithms
 * 
 * Provides common sorting routines for integer arrays: bubble, selection, insertion,
 * merge, quick, heap, and counting sort.
 * 
 * @file sort.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_SORT_H
#define MATHI_SORT_H

/**
 * @brief Sort an array using bubble sort.
 * @param arr Array of integers
 * @param n Number of elements
 */
void bubble_sort(int *arr, int n);

/**
 * @brief Sort an array using selection sort.
 * @param arr Array of integers
 * @param n Number of elements
 */
void selection_sort(int *arr, int n);

/**
 * @brief Sort an array using insertion sort.
 * @param arr Array of integers
 * @param n Number of elements
 */
void insertion_sort(int *arr, int n);

/**
 * @brief Sort an array using merge sort.
 * @param arr Array of integers
 * @param n Number of elements
 */
void merge_sort(int *arr, int n);

/**
 * @brief Sort an array using quick sort.
 * @param arr Array of integers
 * @param n Number of elements
 */
void quick_sort(int *arr, int n);

/**
 * @brief Sort an array using heap sort.
 * @param arr Array of integers
 * @param n Number of elements
 */
void heap_sort(int *arr, int n);

/**
 * @brief Sort an array using counting sort.
 * @param arr Array of integers
 * @param n Number of elements
 * @param max Maximum value in the array
 */
void counting_sort(int *arr, int n, int max);

#endif
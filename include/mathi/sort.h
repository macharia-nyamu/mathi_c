/*
 * Mathi C Library - Sorting Algorithms
 * sort.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_SORT_H
#define MATHI_SORT_H

/**
 * @file mathi/sort.h
 * @brief Standard sorting algorithms for integer arrays.
 */

/**
 * @brief Bubble Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_bubble_sort(int *arr, int n);

/**
 * @brief Selection Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_selection_sort(int *arr, int n);

/**
 * @brief Insertion Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_insertion_sort(int *arr, int n);

/**
 * @brief Merge Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_merge_sort(int *arr, int n);

/**
 * @brief Quick Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_quick_sort(int *arr, int n);

/**
 * @brief Heap Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_heap_sort(int *arr, int n);

/**
 * @brief Counting Sort (requires maximum element)
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 * @param max Maximum value in the array
 */
void mathi_counting_sort(int *arr, int n, int max);

#endif // MATHI_SORT_H
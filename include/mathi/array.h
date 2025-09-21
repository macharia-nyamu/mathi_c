/*
* Mathi C Library - Array Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#ifndef MATHI_ARRAY_H
#define MATHI_ARRAY_H

#include <stddef.h>  // for size_t
#include <stdlib.h>  // for malloc/free

/**
 * @file mathi/array.h
 * @brief Array manipulation functions: search, copy, reverse, shuffle, etc.
 */

/**
 * @brief Find the index of a value in an array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @param value Value to find.
 * @return Index of value if found, -1 otherwise.
 */
int mathi_arr_index(const int *restrict arr, size_t n, int value);

/**
 * @brief Check if an array contains a value.
 * @param arr Array to search.
 * @param n Size of the array.
 * @param value Value to check.
 * @return 1 if value exists, 0 otherwise.
 */
int mathi_arr_contains(const int *restrict arr, size_t n, int value);

/**
 * @brief Reverse an array in place.
 * @param arr Array to reverse.
 * @param n Size of the array.
 */
void mathi_arr_reverse(int *arr, size_t n);

/**
 * @brief Copy contents from one array to another.
 * @param src Source array.
 * @param dest Destination array.
 * @param n Number of elements to copy.
 */
void mathi_arr_copy(const int *restrict src, int *restrict dest, size_t n);

/**
 * @brief Fill an array with a specific value.
 * @param arr Array to fill.
 * @param n Size of the array.
 * @param value Value to fill.
 */
void mathi_arr_fill(int *arr, size_t n, int value);

/**
 * @brief Compute the sum of elements in an array.
 * @param arr Array to sum.
 * @param n Size of the array.
 * @return Sum of elements.
 */
int mathi_arr_sum(const int *restrict arr, size_t n);

/**
 * @brief Find the maximum value in an array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @return Maximum value, or 0 if n <= 0.
 */
int mathi_arr_max(const int *restrict arr, size_t n);

/**
 * @brief Find the minimum value in an array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @return Minimum value, or 0 if n <= 0.
 */
int mathi_arr_min(const int *restrict arr, size_t n);

/**
 * @brief Compute the average of array elements.
 * @param arr Array to process.
 * @param n Size of the array.
 * @return Average as double, or 0 if n <= 0.
 */
double mathi_arr_average(const int *restrict arr, size_t n);

/**
 * @brief Check if two arrays are equal.
 * @param a First array.
 * @param b Second array.
 * @param n Size of arrays.
 * @return 1 if equal, 0 otherwise.
 */
int mathi_arr_equal(const int *restrict a, const int *restrict b, size_t n);

/**
 * @brief Shuffle an array randomly.
 * @param arr Array to shuffle.
 * @param n Size of the array.
 */
void mathi_arr_shuffle(int *arr, size_t n);

/**
 * @brief Remove duplicate elements from an array.
 * @param arr Array to deduplicate.
 * @param n Pointer to size of array; updated with new size.
 */
void mathi_arr_distinct(int *arr, size_t *n);

/**
 * @brief Rotate array elements k times to the right.
 * @param arr Array to rotate.
 * @param n Size of the array.
 * @param k Number of rotations.
 */
void mathi_arr_rotate(int *arr, size_t n, size_t k);

/**
 * @brief Check if an array is sorted in ascending order.
 * @param arr Array to check.
 * @param n Size of the array.
 * @return 1 if sorted, 0 otherwise.
 */
int mathi_arr_sorted(const int *restrict arr, size_t n);

#endif // MATHI_ARRAY_H
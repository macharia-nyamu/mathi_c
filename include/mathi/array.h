/**
 * Mathi C Library - Array Utilities
 * 
 * This header provides common array operations such as searching, reversing,
 * copying, filling, summing, finding min/max, averaging, equality checks,
 * shuffling, and deduplication.
 * 
 * @file array.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_ARRAY_H
#define MATHI_ARRAY_H

/**
 * @brief Find the index of a value in an array.
 * @param arr The array to search.
 * @param n The size of the array.
 * @param value The value to find.
 * @return The index of the value or -1 if not found.
 */
int array_index_of(int *arr, int n, int value);

/**
 * @brief Check if an array contains a value.
 * @param arr The array to search.
 * @param n The size of the array.
 * @param value The value to check for.
 * @return 1 if found, 0 otherwise.
 */
int array_contains(int *arr, int n, int value);

/**
 * @brief Reverse an array in-place.
 * @param arr The array to reverse.
 * @param n The size of the array.
 */
void array_reverse(int *arr, int n);

/**
 * @brief Copy contents of one array to another.
 * @param src Source array.
 * @param dest Destination array.
 * @param n Number of elements to copy.
 */
void array_copy(int *src, int *dest, int n);

/**
 * @brief Fill an array with a given value.
 * @param arr The array to fill.
 * @param n The size of the array.
 * @param value The value to fill.
 */
void array_fill(int *arr, int n, int value);

/**
 * @brief Compute the sum of all elements in an array.
 * @param arr The array to sum.
 * @param n The size of the array.
 * @return Sum of elements.
 */
int array_sum(int *arr, int n);

/**
 * @brief Find the maximum element in an array.
 * @param arr The array to search.
 * @param n The size of the array.
 * @return Maximum value.
 */
int array_max(int *arr, int n);

/**
 * @brief Find the minimum element in an array.
 * @param arr The array to search.
 * @param n The size of the array.
 * @return Minimum value.
 */
int array_min(int *arr, int n);

/**
 * @brief Compute the average of an array.
 * @param arr The array to average.
 * @param n The size of the array.
 * @return Average value as a double.
 */
double array_average(int *arr, int n);

/**
 * @brief Check if two arrays are equal.
 * @param a First array.
 * @param b Second array.
 * @param n Number of elements to compare.
 * @return 1 if arrays are equal, 0 otherwise.
 */
int array_equals(int *a, int *b, int n);

/**
 * @brief Shuffle an array randomly.
 * @param arr The array to shuffle.
 * @param n The size of the array.
 */
void array_shuffle(int *arr, int n);

/**
 * @brief Remove duplicate elements from an array.
 * @param arr The array to deduplicate.
 * @param n Pointer to the size of the array; will be updated with the new size
 */
void array_unique(int *arr, int *n);

#endif // MATHI_ARRAY_H

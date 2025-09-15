/**
 * Mathi C Library - Search Algorithms
 * 
 * Provides basic search routines: linear, binary, jump, and interpolation search.
 * Return values are the index of the found element, or -1 if not found.
 * 
 * @file search.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_SEARCH_H
#define MATHI_SEARCH_H

/**
 * @brief Perform linear search on an array.
 * @param arr Array of integers
 * @param n Size of the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int linear_search(int *arr, int n, int key);

/**
 * @brief Perform binary search on a sorted array.
 * @param arr Sorted array of integers
 * @param n Size of the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int binary_search(int *arr, int n, int key);

/**
 * @brief Perform jump search on a sorted array.
 * @param arr Sorted array of integers
 * @param n Size of the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int jump_search(int *arr, int n, int key);

/**
 * @brief Perform interpolation search on a sorted array.
 * @param arr Sorted array of integers
 * @param n Size of the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int interpolation_search(int *arr, int n, int key);

#endif
/*
 * Mathi C Library - Search Algorithms
 * search.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_SEARCH_H
#define MATHI_SEARCH_H

/**
 * @file mathi/search.h
 * @brief Linear, binary, jump, and interpolation search algorithms for integer arrays.
 */

/**
 * @brief Perform linear search on an array.
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_linear_search(int *arr, int n, int key);

/**
 * @brief Perform binary search on a sorted array.
 * @param arr Pointer to sorted integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_binary_search(int *arr, int n, int key);

/**
 * @brief Perform jump search on a sorted array.
 * @param arr Pointer to sorted integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_jump_search(int *arr, int n, int key);

/**
 * @brief Perform interpolation search on a sorted array.
 * @param arr Pointer to sorted integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_interpolation_search(int *arr, int n, int key);

#endif // MATHI_SEARCH_H
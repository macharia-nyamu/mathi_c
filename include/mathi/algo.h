/*
* Mathi C Library - Math Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#ifndef MATHI_ALGO_H
#define MATHI_ALGO_H

#include <stddef.h>  // for size_t
#include <stdlib.h>  // for abs()

/**
 * @file mathi/math.h
 * @brief Math utility functions: Fibonacci, factorial, digit operations.
 */

/**
 * @brief Compute the n-th Fibonacci number.
 * @param n Index of the Fibonacci sequence (0-based).
 * @return n-th Fibonacci number.
 */
int mathi_fibonacci(int n);

/**
 * @brief Count the occurrences of a value in an integer array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @param value Value to count.
 * @return Number of occurrences of value in arr.
 */
int mathi_occurs(const int *restrict arr, size_t n, int value);

/**
 * @brief Compute factorial of a number iteratively.
 * @param n Non-negative integer.
 * @return Factorial of n, or -1 if n < 0.
 */
int mathi_factorial_iterative(int n);

/**
 * @brief Compute factorial of a number recursively.
 * @param n Non-negative integer.
 * @return Factorial of n, or -1 if n < 0.
 */
int mathi_factorial_recursive(int n);

/**
 * @brief Compute the sum of digits of an integer.
 * @param n Integer value.
 * @return Sum of digits of n.
 */
int mathi_dgts_sum(int n);

/**
 * @brief Compute the root digital (single-digit sum) of an integer.
 * @param n Integer value.
 * @return Root digital of n.
 */
int mathi_rt_digital(int n);

#endif // MATHI_ALGO_H
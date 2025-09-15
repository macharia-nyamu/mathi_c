/**
 * Mathi C Library - Algorithm Utilities
 * 
 * This header provides common algorithmic functions for arrays and numbers,
 * including Fibonacci calculation, factorials, array rotation, sorting checks,
 * digit operations, and element counting.
 * 
 * @file algo.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_ALGO_H
#define MATHI_ALGO_H

/**
 * @brief Compute the nth Fibonacci number.
 * @param n The position in the Fibonacci sequence.
 * @return The nth Fibonacci number.
 */
int fibonacci(int n);

/**
 * @brief Count occurrences of a value in an array.
 * @param arr The array to search.
 * @param n The size of the array.
 * @param value The value to count.
 * @return The number of times value appears in arr.
 */
int count_occurrences(int arr[], int n, int value);

/**
 * @brief Rotate an array k positions to the right.
 * @param arr The array to rotate.
 * @param n The size of the array.
 * @param k Number of positions to rotate.
 */
void rotate_array(int *arr, int n, int k);

/**
 * @brief Compute factorial iteratively.
 * @param n The number to compute factorial for.
 * @return Factorial of n.
 */
int factorial_iterative(int n);

/**
 * @brief Compute factorial recursively.
 * @param n The number to compute factorial for.
 * @return Factorial of n.
 */
int factorial_recursive(int n);

/**
 * @brief Check if an array is sorted in ascending order.
 * @param arr The array to check.
 * @param n The size of the array.
 * @return 1 if sorted, 0 otherwise.
 */
int is_sorted(int *arr, int n);

/**
 * @brief Compute the nth Fibonacci number (alternate method).
 * @param n The position in the Fibonacci sequence.
 * @return The nth Fibonacci number.
 */
int nth_fibonacci(int n);

/**
 * @brief Compute the sum of digits of a number.
 * @param n The number to sum digits of.
 * @return Sum of digits.
 */
int sum_of_digits(int n);

/**
 * @brief Compute the digital root of a number.
 * @param n The number to find digital root for.
 * @return Digital root of n.
 */
int digital_root(int n);

#endif
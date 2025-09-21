/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * A lightweight C library providing common mathematical functions.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Compute the nth Fibonacci number.
 * @param n Index in the Fibonacci sequence (n >= 0)
 * @return Fibonacci number at index n
 */
int mathi_fibonacci(int n)
{
    if (n <= 1) 
        return n;

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

/**
 * @brief Count how many times a value occurs in an array.
 * @param arr Array of integers
 * @param n Number of elements in arr
 * @param value Value to count
 * @return Number of occurrences of value in arr
 */
int mathi_occurs(int arr[], int n, int value)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] == value)
            count++;

    return count;
}

/**
 * @brief Compute factorial iteratively.
 * @param n Non-negative integer
 * @return Factorial of n, or -1 if n < 0
 */
int mathi_factorial_iterative(int n)
{
    if (n < 0) 
        return -1;

    int res = 1;

    for (int i = 2; i <= n; i++)
        res *= i;

    return res;
}

/**
 * @brief Compute factorial recursively.
 * @param n Non-negative integer
 * @return Factorial of n, or -1 if n < 0
 */
int mathi_factorial_recursive(int n)
{
    if (n < 0) 
        return -1;

    if (n == 0 || n == 1) 
        return 1;

    return n * mathi_factorial_recursive(n - 1);
}

/**
 * @brief Sum the digits of an integer.
 * @param n Integer
 * @return Sum of digits of n
 */
int mathi_dgts_sum(int n)
{
    int sum = 0;
    n = abs(n); // make n positive

    while (n)
    {
        sum += n % 10;  // add last digit
        n /= 10;        // remove last digit
    }

    return sum;
}

/**
 * @brief Compute the repeated digital root of an integer.
 * @param n Integer
 * @return Single-digit result obtained by summing digits repeatedly
 */
int mathi_rt_digital(int n)
{
    n = abs(n);

    while (n >= 10)
        n = mathi_dgts_sum(n); // reduce to single digit

    return n;
}
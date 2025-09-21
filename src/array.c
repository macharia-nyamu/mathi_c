/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Array utility functions for common operations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Find the index of a value in an array.
 * @return Index of value or -1 if not found
 */
int mathi_arr_index(int *arr, int n, int value)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == value)
            return i;

    return -1;
}

/**
 * @brief Check if an array contains a value.
 * @return 1 if found, 0 otherwise
 */
int mathi_arr_contains(int *arr, int n, int value)
{
    return mathi_arr_index(arr, n, value) != -1;
}

/**
 * @brief Reverse an array in place.
 */
void mathi_arr_reverse(int *arr, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

/**
 * @brief Copy one array to another.
 */
void mathi_arr_copy(int *src, int *dest, int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

/**
 * @brief Fill an array with a specific value.
 */
void mathi_arr_fill(int *arr, int n, int value)
{
    for (int i = 0; i < n; i++)
        arr[i] = value;
}

/**
 * @brief Compute the sum of array elements.
 */
int mathi_arr_sum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

/**
 * @brief Find the maximum element in an array.
 */
int mathi_arr_max(int *arr, int n)
{
    if (n <= 0) 
        return 0;

    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

/**
 * @brief Find the minimum element in an array.
 */
int mathi_arr_min(int *arr, int n)
{
    if (n <= 0) 
        return 0;

    int min = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];

    return min;
}

/**
 * @brief Compute the average of array elements.
 */
double mathi_arr_average(int *arr, int n)
{
    if (n <= 0) 
        return 0;

    return (double)mathi_arr_sum(arr, n) / n;
}

/**
 * @brief Check if two arrays are equal.
 */
int mathi_arr_equal(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}

/**
 * @brief Shuffle an array randomly.
 */
void mathi_arr_shuffle(int *arr, int n)
{
    srand((unsigned int)time(NULL));

    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

/**
 * @brief Remove duplicate elements from an array in place.
 * @param n Pointer to size of array; updated with new size
 */
void mathi_arr_distinct(int *arr, int *n)
{
    if (*n <= 1) 
        return;

    int j = 0;

    for (int i = 1; i < *n; i++)
    {
        int found = 0;

        for (int k = 0; k <= j; k++)
            if (arr[i] == arr[k])
            {
                found = 1;
                break;
            }

        if (!found)
            arr[++j] = arr[i];
    }

    *n = j + 1;
}

/**
 * @brief Rotate array elements to the right k times.
 */
void mathi_arr_rotate(int *arr, int n, int k)
{
    k = k % n;
    if (k == 0) 
        return;

    int *tmp = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
        tmp[i] = arr[n - k + i];

    for (int i = n - 1; i >= k; i--)
        arr[i] = arr[i - k];

    for (int i = 0; i < k; i++)
        arr[i] = tmp[i];

    free(tmp);
}

/**
 * @brief Check if an array is sorted in ascending order.
 * @return 1 if sorted, 0 otherwise
 */
int mathi_arr_sorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}
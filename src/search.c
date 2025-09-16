/*
* Mathi C Library - Search Algorithms
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Perform linear search on an integer array.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @param key Value to search for.
 * @return Index of the key if found, -1 otherwise.
 */
int mathi_linear_search(int *arr, int n, int key)
{
    for(int i = 0; i < n; i++) 
        if(arr[i] == key) return i;
    return -1;
}

/**
 * @brief Perform binary search on a sorted integer array.
 * @param arr Pointer to the sorted array.
 * @param n Number of elements in the array.
 * @param key Value to search for.
 * @return Index of the key if found, -1 otherwise.
 */
int mathi_binary_search(int *arr, int n, int key)
{
    int low = 0, high = n - 1;
    while(low <= high) 
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/**
 * @brief Perform jump search on a sorted integer array.
 * @param arr Pointer to the sorted array.
 * @param n Number of elements in the array.
 * @param key Value to search for.
 * @return Index of the key if found, -1 otherwise.
 */
int mathi_jump_search(int *arr, int n, int key)
{
    int step = (int)sqrt(n);
    int prev = 0;

    while(step < n && arr[step - 1] < key) 
    {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return -1;
    }

    int end = step < n ? step : n;
    for (int i = prev; i < end; i++) 
    {
        if (arr[i] == key) return i;
    }

    return -1;
}

/**
 * @brief Perform interpolation search on a sorted integer array.
 * @param arr Pointer to the sorted array.
 * @param n Number of elements in the array.
 * @param key Value to search for.
 * @return Index of the key if found, -1 otherwise.
 */
int mathi_interpolation_search(int *arr, int n, int key)
{
    int low = 0, high = n - 1;
    while(low <= high && key >= arr[low] && key <= arr[high]) 
    {
        if(arr[low] == arr[high]) 
        {
            if(arr[low] == key) return low;
            else return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);
        if(arr[pos] == key) return pos;
        if(arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}
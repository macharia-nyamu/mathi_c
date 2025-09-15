/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_STATS_H
#define MATHI_STATS_H

/**
 * @file stats.h
 * @brief Statistical functions for integer arrays.
 */

/**
 * @brief Compute the mean (average) of an integer array.
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 * @return The mean value as a double. Returns 0 if n <= 0.
 */
double mean(int *arr, int n);

/**
 * @brief Compute the median of an integer array.
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 * @return The median value as a double. Returns 0 if n <= 0.
 */
double median(int *arr, int n);

/**
 * @brief Compute the variance of an integer array.
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 * @return The variance as a double. Returns 0 if n <= 0.
 */
double variance(int *arr, int n);

/**
 * @brief Compute the standard deviation of an integer array.
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 * @return The standard deviation as a double. Returns 0 if n <= 0.
 */
double stddev(int *arr, int n);

/**
 * @brief Compute the mode (most frequent value) of an integer array.
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 * @return The mode as an integer. Returns 0 if n <= 0.
 */
int mode(int *arr, int n);

/**
 * @brief Compute the percentile value of an integer array.
 * @param arr Pointer to the integer array.
 * @param n Number of elements in the array.
 * @param p The desired percentile (0-100).
 * @return The percentile value as a double. Returns 0 if n <= 0.
 */
double percentile(int *arr, int n, double p);

#endif /* MATHI_STATS_H */
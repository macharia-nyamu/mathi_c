/*
 * Mathi C Library - Statistics Utilities
 * stats.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_STATS_H
#define MATHI_STATS_H

/**
 * @file mathi/stats.h
 * @brief Basic statistical functions for integer arrays.
 */

/**
 * @brief Compute the mean (average) of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Mean value as double
 */
double mathi_mean(int *arr, int n);

/**
 * @brief Compute the median of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Median value as double
 */
double mathi_median(int *arr, int n);

/**
 * @brief Compute the variance of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Variance as double
 */
double mathi_variance(int *arr, int n);

/**
 * @brief Compute the standard deviation of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Standard deviation as double
 */
double mathi_stddev(int *arr, int n);

/**
 * @brief Compute the mode (most frequent value) of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Mode as integer
 */
int mathi_mode(int *arr, int n);

/**
 * @brief Compute a percentile value of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @param p Percentile (0-100)
 * @return Percentile value as double
 */
double mathi_percentile(int *arr, int n, double p);

#endif // MATHI_STATS_H
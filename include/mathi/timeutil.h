/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_TIMEUTIL_H
#define MATHI_TIMEUTIL_H

#include <stddef.h>

/**
 * @file timeutil.h
 * @brief Time utility functions for timestamps, formatting, sleeping, and elapsed time calculation.
 */

/**
 * @brief Get the current timestamp in seconds since the Unix epoch.
 * @return Current timestamp as a long integer.
 */
long current_timestamp();

/**
 * @brief Format the current local time as a human-readable string.
 * @param buffer Character buffer to store the formatted time.
 * @param size Size of the buffer.
 */
void format_time(char *buffer, size_t size);

/**
 * @brief Sleep for a specified number of milliseconds.
 * @param ms Number of milliseconds to sleep.
 * 
 * @note Uses platform-specific functions: Sleep() on Windows, usleep() on Unix-like systems.
 */
void sleep_ms(int ms);

/**
 * @brief Calculate the number of elapsed seconds between two timestamps.
 * @param start Start timestamp.
 * @param end End timestamp.
 * @return Number of seconds elapsed (end - start).
 */
int elapsed_seconds(long start, long end);

#endif
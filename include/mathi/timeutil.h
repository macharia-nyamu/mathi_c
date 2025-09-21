/*
 * Mathi C Library - Time Utilities
 * time.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_TIME_H
#define MATHI_TIME_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file mathi/time.h
 * @brief Time and timestamp utility functions.
 */

/**
 * @brief Get the current Unix timestamp
 * @return Current timestamp in seconds since epoch
 */
long mathi_current_timestamp(void);

/**
 * @brief Format current local time into a string
 * @param buffer Buffer to store formatted time
 * @param size Size of the buffer
 *
 * Format used: "YYYY-MM-DD HH:MM:SS"
 */
void mathi_format_time(char *buffer, size_t size);

/**
 * @brief Sleep for a specified number of milliseconds
 * @param ms Number of milliseconds to sleep
 *
 * Cross-platform implementation: uses Sleep on Windows and usleep on Unix.
 */
void mathi_sleep_ms(int ms);

/**
 * @brief Calculate elapsed seconds between two timestamps
 * @param start Start timestamp
 * @param end End timestamp
 * @return Number of seconds elapsed
 */
int mathi_elapsed_seconds(long start, long end);

#ifdef __cplusplus
}
#endif

#endif // MATHI_TIME_H
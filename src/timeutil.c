/*
* Mathi C Library - Time Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/**
 * @brief Get the current timestamp in seconds since the Epoch.
 * @return Current time as a long integer.
 */
long mathi_current_timestamp()
{
    return (long)time(NULL);
}

/**
 * @brief Format the current local time into a human-readable string.
 * @param buffer Buffer to store the formatted string.
 * @param size Size of the buffer.
 */
void mathi_format_time(char *buffer, size_t size)
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

/**
 * @brief Sleep for a specified number of milliseconds.
 * @param ms Number of milliseconds to sleep.
 */
void mathi_sleep_ms(int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

/**
 * @brief Compute elapsed time in seconds between two timestamps.
 * @param start Start timestamp.
 * @param end End timestamp.
 * @return Elapsed time in seconds.
 */
int mathi_elapsed_seconds(long start, long end)
{
    return (int)(end - start);
}
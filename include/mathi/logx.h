/*
 * Mathi C Library - Logging Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_LOGX_H
#define MATHI_LOGX_H

/**
 * @file mathi/logx.h
 * @brief Logging functions (info, warn, error) with optional file output.
 */

/* Status codes */
#define LOG_SUCCESS   0
#define LOG_FILE_ERROR 1
#define LOG_INVALID_PATH 2


/**
 * @brief Set the file to which logs should be written.
 * @param path File path.
 * @return LOG_SUCCESS on success, LOG_FILE_ERROR if file can't be opened, LOG_INVALID_PATH if path is NULL.
 */
int mathi_set_log_file(const char *path);

/**
 * @brief Log an informational message.
 * @param fmt Format string (like printf).
 * @return LOG_SUCCESS
 */
int mathi_log_info(const char *fmt, ...);

/**
 * @brief Log a warning message.
 * @param fmt Format string (like printf).
 * @return LOG_SUCCESS
 */
int mathi_log_warn(const char *fmt, ...);

/**
 * @brief Log an error message.
 * @param fmt Format string (like printf).
 * @return LOG_SUCCESS
 */
int mathi_log_error(const char *fmt, ...);

#endif // MATHI_LOGX_H
/**
 * Mathi C Library - Logging Utilities
 * 
 * This header provides structured logging functions for informational, warning,
 * and error messages. Logs can optionally be written to a specified file.
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - FILE_ERROR
 * 2 - INVALID_INPUT
 * 3 - UNKNOWN_ERROR
 * 
 * @file logx.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_LOGX_H
#define MATHI_LOGX_H

#include <stdarg.h>

/**
 * @brief Log an informational message.
 * @param fmt printf-style format string.
 * @param ... Arguments corresponding to the format string.
 * @return Status code (0 = SUCCESS, 1 = FILE_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int log_info(const char *fmt, ...);

/**
 * @brief Log a warning message.
 * @param fmt printf-style format string.
 * @param ... Arguments corresponding to the format string.
 * @return Status code (0 = SUCCESS, 1 = FILE_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int log_warn(const char *fmt, ...);

/**
 * @brief Log an error message.
 * @param fmt printf-style format string.
 * @param ... Arguments corresponding to the format string.
 * @return Status code (0 = SUCCESS, 1 = FILE_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int log_error(const char *fmt, ...);

/**
 * @brief Set the file path to write logs to.
 * @param path Path to the log file.
 * @return Status code (0 = SUCCESS, 1 = FILE_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int set_log_file(const char *path);

#endif
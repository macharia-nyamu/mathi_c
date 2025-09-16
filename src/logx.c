/*
* Mathi C Library - Logging Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/logx.h"
#include <stdio.h>
#include <stdarg.h>

// Static file pointer for optional logging to file
static FILE *log_file = NULL;

int mathi_set_log_file(const char *path) 
{
    if (!path) return 2; // INVALID_INPUT
    log_file = fopen(path, "a"); // Open in append mode
    return log_file ? 0 : 1;    // SUCCESS or FILE_ERROR
}

int mathi_log_info(const char *fmt, ...) 
{
    va_list args;
    va_start(args, fmt);

    // If log_file is set, write to file; otherwise, print to stdout
    vfprintf(log_file ? log_file : stdout, fmt, args);
    fprintf(log_file ? log_file : stdout, "\n"); // Ensure newline

    va_end(args);
    return 0; // SUCCESS
}

int mathi_log_warn(const char *fmt, ...) 
{
    va_list args;
    va_start(args, fmt);

    // Prefix with [WARN] for easy identification
    fprintf(log_file ? log_file : stdout, "[WARN] ");
    vfprintf(log_file ? log_file : stdout, fmt, args);
    fprintf(log_file ? log_file : stdout, "\n");

    va_end(args);
    return 0; // SUCCESS
}

int mathi_log_error(const char *fmt, ...) 
{
    va_list args;
    va_start(args, fmt);

    // Prefix with [ERROR] for visibility
    fprintf(log_file ? log_file : stdout, "[ERROR] ");
    vfprintf(log_file ? log_file : stdout, fmt, args);
    fprintf(log_file ? log_file : stdout, "\n");

    va_end(args);
    return 0; // SUCCESS
}
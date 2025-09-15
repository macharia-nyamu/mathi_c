/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/logx.h"
#include <stdio.h>
#include <stdarg.h>

static FILE *log_file = NULL;

int set_log_file(const char *path) {
    if (!path) return 2;
    log_file = fopen(path, "a");
    return log_file ? 0 : 1;
}

int log_info(const char *fmt, ...) {
    va_list args; va_start(args, fmt);
    vfprintf(log_file ? log_file : stdout, fmt, args); fprintf(log_file ? log_file : stdout, "\n");
    va_end(args);
    return 0;
}

int log_warn(const char *fmt, ...) {
    va_list args; va_start(args, fmt);
    fprintf(log_file ? log_file : stdout, "[WARN] ");
    vfprintf(log_file ? log_file : stdout, fmt, args); fprintf(log_file ? log_file : stdout, "\n");
    va_end(args);
    return 0;
}

int log_error(const char *fmt, ...) {
    va_list args; va_start(args, fmt);
    fprintf(log_file ? log_file : stdout, "[ERROR] ");
    vfprintf(log_file ? log_file : stdout, fmt, args); fprintf(log_file ? log_file : stdout, "\n");
    va_end(args);
    return 0;
}
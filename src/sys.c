/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#include "mathi/sys.h"
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <string.h>
#endif

/**
 * @brief Get the value of an environment variable.
 */
char* get_env(const char *name) {
    if(!name) return NULL;
    return getenv(name);
}

/**
 * @brief Set an environment variable.
 */
int set_env(const char *name, const char *value, int overwrite) {
    if(!name || !value) return 0;

#if defined(_WIN32) || defined(_WIN64)
    if(!overwrite && getenv(name)) return 1; // do not overwrite existing
    return (_putenv_s(name, value) == 0) ? 1 : 0;
#else
    return (setenv(name, value, overwrite ? 1 : 0) == 0) ? 1 : 0;
#endif
}
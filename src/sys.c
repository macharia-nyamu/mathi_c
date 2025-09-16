/*
 * Mathi C Library - System Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#include "mathi/sys.h"
#include <stdlib.h>

#if defined(_WIN32) || defined(_WIN64)
#include <string.h>
#endif

/**
 * @brief Retrieve the value of an environment variable.
 * @param name Name of the environment variable.
 * @return Pointer to the value string if found, NULL otherwise.
 */
char* mathi_get_env(const char *name)
{
    if(!name) return NULL;
    return getenv(name);
}

/**
 * @brief Set or update an environment variable.
 * @param name Name of the environment variable.
 * @param value Value to set.
 * @param overwrite If non-zero, overwrite existing value.
 * @return 1 if successful, 0 if failed.
 */
int mathi_set_env(const char *name, const char *value, int overwrite)
{
    if(!name || !value) return 0;

#if defined(_WIN32) || defined(_WIN64)
    if(!overwrite && getenv(name)) return 1; // Do not overwrite
    return (_putenv_s(name, value) == 0) ? 1 : 0;
#else
    return (setenv(name, value, overwrite ? 1 : 0) == 0) ? 1 : 0;
#endif
}
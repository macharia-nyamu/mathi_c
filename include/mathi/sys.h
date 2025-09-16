/*
 * Mathi C Library - System Utilities
 * sys.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_SYS_H
#define MATHI_SYS_H

/**
 * @file mathi/sys.h
 * @brief System and environment utility functions.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the value of an environment variable
 * @param name Name of the environment variable
 * @return Pointer to the value string, or NULL if not found
 */
char* mathi_get_env(const char *name);

/**
 * @brief Set the value of an environment variable
 * @param name Name of the environment variable
 * @param value Value to set
 * @param overwrite If non-zero, overwrite existing variable
 * @return 1 on success, 0 on failure
 */
int mathi_set_env(const char *name, const char *value, int overwrite);

#ifdef __cplusplus
}
#endif

#endif // MATHI_SYS_H
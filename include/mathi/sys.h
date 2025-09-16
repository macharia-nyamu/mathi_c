/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_SYS_H
#define MATHI_SYS_H

/**
 * @file sys.h
 * @brief Fundamental system utilities (environment variables, memory info, etc.).
 * 
 * Focused on universal functions usable on any platform.
 */

/**
 * @brief Get the value of an environment variable.
 * @param name Name of the environment variable.
 * @return Pointer to the value string, or NULL if the variable is not set.
 */
char* get_env(const char *name);

/**
 * @brief Set an environment variable.
 * @param name Name of the environment variable.
 * @param value Value to set.
 * @param overwrite If non-zero, existing variable will be overwritten.
 * @return 1 on success, 0 on failure.
 */
int set_env(const char *name, const char *value, int overwrite);

#endif
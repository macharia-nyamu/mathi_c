/*
* Mathi C Library - Config Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#ifndef MATHI_CONFIG_H
#define MATHI_CONFIG_H

#include <stddef.h>  // for size_t

/**
 * @file mathi/config.h
 * @brief Configuration file utilities.
 */

/**
 * @brief Load a configuration file.
 * @param file_path Path to the config file.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_load(const char *file_path);

/**
 * @brief Get a string value from the configuration.
 * @param key Key to look up.
 * @return String value, or empty string if not found.
 */
const char* mathi_conf_get_string(const char *key);

/**
 * @brief Get an integer value from the configuration.
 * @param key Key to look up.
 * @param value Pointer to store the integer result.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_get_int(const char *key, int *value);

/**
 * @brief Set a string value in the configuration.
 * @param key Key to set.
 * @param value Value to assign.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_set_string(const char *key, const char *value);

/**
 * @brief Save the current configuration to file.
 * @param file_path Path to save the config file.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_save(const char *file_path);

#endif // MATHI_CONFIG_H

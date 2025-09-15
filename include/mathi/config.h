/**
 * Mathi C Library - Configuration Utilities
 * 
 * This header provides functions for loading, reading, modifying, and saving
 * configuration files (INI-style or similar). It allows retrieval of strings
 * and integers, as well as updating and saving configurations.
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - FILE_ERROR
 * 2 - MEMORY_ERROR
 * 3 - KEY_NOT_FOUND
 * 4 - INVALID_INPUT
 * 5 - UNKNOWN_ERROR
 * 
 * @file config.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_CONFIG_H
#define MATHI_CONFIG_H

/**
 * @brief Load a configuration file.
 * @param file_path Path to the configuration file.
 * @return Status code (0 = SUCCESS, 1 = FILE_ERROR, 2 = MEMORY_ERROR, 5 = UNKNOWN_ERROR).
 */
int config_load(const char *file_path);

/**
 * @brief Get a string value from the configuration.
 * @param key The configuration key.
 * @return Pointer to the string value, or NULL if not found.
 */
const char* config_get_string(const char *key);

/**
 * @brief Get an integer value from the configuration.
 * @param key The configuration key.
 * @param value Pointer to store the retrieved integer.
 * @return Status code (0 = SUCCESS, 3 = KEY_NOT_FOUND, 4 = INVALID_INPUT, 5 = UNKNOWN_ERROR).
 */
int config_get_int(const char *key, int *value);

/**
 * @brief Set a string value in the configuration.
 * @param key The configuration key.
 * @param value The string value to set.
 * @return Status code (0 = SUCCESS, 2 = MEMORY_ERROR, 4 = INVALID_INPUT, 5 = UNKNOWN_ERROR).
 */
int config_set_string(const char *key, const char *value);

/**
 * @brief Save the configuration to a file.
 * @param file_path Path to the output configuration file.
 * @return Status code (0 = SUCCESS, 1 = FILE_ERROR, 2 = MEMORY_ERROR, 5 = UNKNOWN_ERROR).
 */
int config_save(const char *file_path);

#endif
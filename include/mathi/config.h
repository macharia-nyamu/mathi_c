/*
 * Mathi C Library - Config Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Configuration file utilities using MathiJSON.
 * Supports string, int, bool, double, array, and object types.
 * Stores all data in a single root JSON object.
 */

#ifndef MATHI_CONFIG_H
#define MATHI_CONFIG_H

#include <stddef.h>
#include <stdbool.h>
#include "mathison.h"

/* --- Load / Save configuration --- */

/**
 * @brief Load a configuration file into memory.
 * @param file_path Path to the JSON config file.
 * @return 0 on success, non-zero on failure.
 *
 * Loads the entire file into a single MathiJSON root object.
 */
int mathi_conf_load(const char *file_path);

/**
 * @brief Save the current configuration to a file.
 * @param file_path Path to write the JSON config file.
 * @return 0 on success, non-zero on failure.
 *
 * Serializes the MathiJSON root object into a JSON string and writes to file.
 */
int mathi_conf_save(const char *file_path);

/* --- String operations --- */

/**
 * @brief Get a string value by key.
 * @param key The key to retrieve.
 * @return Pointer to string value, or empty string if key does not exist or type mismatch.
 */
const char* mathi_conf_get_string(const char *key);

/**
 * @brief Set a string value by key.
 * @param key The key to set.
 * @param value The string value to assign.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_set_string(const char *key, const char *value);

/* --- Integer operations --- */

/**
 * @brief Get an integer value by key.
 * @param key The key to retrieve.
 * @param value Pointer to store the integer result.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_get_int(const char *key, int *value);

/**
 * @brief Set an integer value by key.
 * @param key The key to set.
 * @param value Integer value to assign.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_set_int(const char *key, int value);

/* --- Boolean operations --- */

/**
 * @brief Get a boolean value by key.
 * @param key The key to retrieve.
 * @param value Pointer to store the boolean result.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_get_bool(const char *key, bool *value);

/**
 * @brief Set a boolean value by key.
 * @param key The key to set.
 * @param value Boolean value to assign.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_set_bool(const char *key, bool value);

/* --- Double (floating-point) operations --- */

/**
 * @brief Get a double value by key.
 * @param key The key to retrieve.
 * @param value Pointer to store the double result.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_get_double(const char *key, double *value);

/**
 * @brief Set a double value by key.
 * @param key The key to set.
 * @param value Double value to assign.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_set_double(const char *key, double value);

/* --- Array operations --- */

/**
 * @brief Get an array by key.
 * @param key The key to retrieve.
 * @param array Pointer to store the MathiJSON array.
 * @return 0 on success, non-zero on failure.
 *
 * Returns a pointer to the existing MathiJSON array stored in the root object.
 */
int mathi_conf_get_array(const char *key, MathiJSON **array);

/**
 * @brief Set an array by key.
 * @param key The key to set.
 * @param array MathiJSON array to assign.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_set_array(const char *key, MathiJSON *array);

/* --- Object operations --- */

/**
 * @brief Get a nested object by key.
 * @param key The key to retrieve.
 * @param object Pointer to store the MathiJSON object.
 * @return 0 on success, non-zero on failure.
 *
 * Returns a pointer to the existing MathiJSON object stored in the root object.
 */
int mathi_conf_get_object(const char *key, MathiJSON **object);

/**
 * @brief Set a nested object by key.
 * @param key The key to set.
 * @param object MathiJSON object to assign.
 * @return 0 on success, non-zero on failure.
 */
int mathi_conf_set_object(const char *key, MathiJSON *object);

/* --- Key removal and existence --- */

/**
 * @brief Remove a key/value pair from the configuration.
 * @param key The key to remove.
 * @return 0 on success, non-zero if key does not exist.
 */
int mathi_conf_remove_key(const char *key);

/**
 * @brief Check if a key exists in the configuration.
 * @param key The key to check.
 * @return true if the key exists, false otherwise.
 */
bool mathi_conf_has_key(const char *key);

#endif // MATHI_CONFIG_H
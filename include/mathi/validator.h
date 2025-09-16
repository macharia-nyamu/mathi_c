/*
 * Mathi C Library - Validator Utilities
 * validator.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef VALIDATOR_H
#define VALIDATOR_H

/**
 * @file validator.h
 * @brief Functions for validating strings and numeric ranges.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Check if a string represents a valid integer.
 * @param str The string to check.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int mathi_is_int(const char *str);

/**
 * @brief Check if a string represents a valid float.
 * @param str The string to check.
 * @return 1 if the string is a valid float, 0 otherwise.
 */
int mathi_is_float(const char *str);

/**
 * @brief Check if a string represents a valid double.
 * @param str The string to check.
 * @return 1 if the string is a valid double, 0 otherwise.
 */
int mathi_is_double(const char *str);

/**
 * @brief Check if a string represents any numeric value (int, float, or double).
 * @param str The string to check.
 * @return 1 if the string is numeric, 0 otherwise.
 */
int mathi_is_number(const char *str);

/**
 * @brief Check if a string contains only alphabetic characters.
 * @param str The string to check.
 * @return 1 if the string is alphabetic, 0 otherwise.
 */
int mathi_is_alpha(const char *str);

/**
 * @brief Check if a string contains only alphanumeric characters.
 * @param str The string to check.
 * @return 1 if the string is alphanumeric, 0 otherwise.
 */
int mathi_is_alnum(const char *str);

/**
 * @brief Check if a string contains only binary digits ('0' or '1').
 * @param str The string to check.
 * @return 1 if the string is binary, 0 otherwise.
 */
int mathi_is_binary(const char *str);

/**
 * @brief Check if a string contains only valid hexadecimal characters.
 * @param str The string to check.
 * @return 1 if the string is hexadecimal, 0 otherwise.
 */
int mathi_is_hex(const char *str);

/**
 * @brief Check if an integer is within a specified range.
 * @param value The value to check.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return 1 if value is within [min, max], 0 otherwise.
 */
int mathi_in_range(int value, int min, int max);

#ifdef __cplusplus
}
#endif

#endif // VALIDATOR_H
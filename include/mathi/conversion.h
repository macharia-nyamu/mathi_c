/*
* Mathi C Library - Conversion Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#ifndef MATHI_CONVERSION_H
#define MATHI_CONVERSION_H

#include <stddef.h>  // for size_t

/**
 * @file mathi/conversion.h
 * @brief Number and string conversion utilities.
 */

/**
 * @brief Convert binary string to decimal integer.
 * @param bin Binary string (e.g., "1010").
 * @param result Pointer to store the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_bin_to_dcm(const char *bin, int *result);

/**
 * @brief Convert decimal integer to binary string.
 * @param num Integer to convert.
 * @param out Pointer to allocated string for the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_dcm_to_bin(int num, char **out);

/**
 * @brief Convert hexadecimal string to decimal integer.
 * @param hex Hex string (e.g., "1A3F").
 * @param result Pointer to store the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_hex_to_dcm(const char *hex, int *result);

/**
 * @brief Convert decimal integer to hexadecimal string.
 * @param num Integer to convert.
 * @param out Pointer to allocated string for the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_dcm_to_hex(int num, char **out);

/**
 * @brief Convert integer to string.
 * @param num Integer to convert.
 * @param out Pointer to allocated string for the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_int_to_str(int num, char **out);

/**
 * @brief Convert string to integer.
 * @param str Input string.
 * @param result Pointer to store the integer result.
 * @return 0 on success, 2 on invalid input.
 */
int mathi_str_to_int(const char *str, int *result);

/**
 * @brief Convert string to double.
 * @param str Input string.
 * @param result Pointer to store the double result.
 * @return 0 on success, 2 on invalid input.
 */
int mathi_str_to_dbl(const char *str, double *result);

#endif // MATHI_CONVERSION_H
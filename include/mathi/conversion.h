/**
 * Mathi C Library - Conversion Utilities
 * 
 * This header provides functions for converting between different numeric
 * representations (binary, decimal, hexadecimal) and for converting numbers
 * to and from strings.
 * 
 * @file conversion.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_CONVERSION_H
#define MATHI_CONVERSION_H

/**
 * @brief Convert a binary string to decimal integer.
 * @param bin Null-terminated binary string.
 * @return Decimal integer value.
 */
int binary_to_decimal(const char *bin);

/**
 * @brief Convert a decimal integer to binary string.
 * @param num Decimal integer.
 * @param buffer Buffer to store null-terminated binary string (must be preallocated).
 */
void decimal_to_binary(int num, char *buffer);

/**
 * @brief Convert a hexadecimal string to decimal integer.
 * @param hex Null-terminated hexadecimal string.
 * @return Decimal integer value.
 */
int hex_to_decimal(const char *hex);

/**
 * @brief Convert a decimal integer to hexadecimal string.
 * @param num Decimal integer.
 * @param buffer Buffer to store null-terminated hexadecimal string (must be preallocated).
 */
void decimal_to_hex(int num, char *buffer);

/**
 * @brief Convert an integer to string.
 * @param num Integer to convert.
 * @param buffer Buffer to store null-terminated string (must be preallocated).
 * @return Pointer to the buffer.
 */
char *int_to_string(int num, char *buffer);

/**
 * @brief Convert a string to integer.
 * @param str Null-terminated string representing an integer.
 * @return Integer value.
 */
int string_to_int(const char *str);

/**
 * @brief Convert a string to double.
 * @param str Null-terminated string representing a floating-point number.
 * @return Double value.
 */
double string_to_double(const char *str);

#endif
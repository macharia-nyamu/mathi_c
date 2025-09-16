/*
 * Mathi C Library - String Utilities
 * stringx.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_STRINGX_H
#define MATHI_STRINGX_H

#include <stddef.h>

/**
 * @file mathi/stringx.h
 * @brief String manipulation functions.
 */

/**
 * @brief Reverse a string in place
 * @param str The string to reverse
 * @return Pointer to the reversed string
 */
char *mathi_string_reverse(char *str);

/**
 * @brief Find the index of a character in a string
 * @param str The string to search
 * @param c The character to find
 * @return Index of character or -1 if not found
 */
int mathi_string_index_of(const char *str, char c);

/**
 * @brief Check if a string contains a character
 * @param str The string to check
 * @param c The character to find
 * @return 1 if found, 0 otherwise
 */
int mathi_string_contains(const char *str, char c);

/**
 * @brief Count occurrences of a character in a string
 * @param str The string to check
 * @param c The character to count
 * @return Number of occurrences
 */
int mathi_string_count_char(const char *str, char c);

/**
 * @brief Convert a string to uppercase in place
 * @param str The string to convert
 * @return Pointer to the converted string
 */
char *mathi_string_to_upper(char *str);

/**
 * @brief Convert a string to lowercase in place
 * @param str The string to convert
 * @return Pointer to the converted string
 */
char *mathi_string_to_lower(char *str);

/**
 * @brief Get the length of a string
 * @param str The string to measure
 * @return Length of the string
 */
int mathi_string_length(const char *str);

/**
 * @brief Concatenate two strings
 * @param dest Destination string (must have enough space)
 * @param src Source string to append
 * @return Pointer to the destination string
 */
char *mathi_string_concat(char *dest, const char *src);

/**
 * @brief Copy a string
 * @param dest Destination string (must have enough space)
 * @param src Source string
 * @return Pointer to the destination string
 */
char *mathi_string_copy(char *dest, const char *src);

/**
 * @brief Compare two strings
 * @param a First string
 * @param b Second string
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int mathi_string_compare(const char *a, const char *b);

/**
 * @brief Check if string starts with a prefix
 * @param str String to check
 * @param prefix Prefix to match
 * @return 1 if yes, 0 if no
 */
int mathi_string_starts_with(const char *str, const char *prefix);

/**
 * @brief Check if string ends with a suffix
 * @param str String to check
 * @param suffix Suffix to match
 * @return 1 if yes, 0 if no
 */
int mathi_string_ends_with(const char *str, const char *suffix);

/**
 * @brief Trim leading and trailing whitespace from string
 * @param str String to trim (modified in place)
 * @return Pointer to trimmed string
 */
char *mathi_string_trim(char *str);

/**
 * @brief Replace all occurrences of a character with another
 * @param str String to modify
 * @param old Character to replace
 * @param newc Replacement character
 * @return Pointer to modified string
 */
char *mathi_string_replace(char *str, char old, char newc);

#endif // MATHI_STRINGX_H
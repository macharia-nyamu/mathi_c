#ifndef MATHI_STRINGX_H
#define MATHI_STRINGX_H

/**
 * @file stringx.h
 * @brief String manipulation utilities for C.
 */

/**
 * @brief Reverse a string in place.
 * @param str The string to reverse.
 * @return Pointer to the reversed string.
 */
char *string_reverse(char *str);

/**
 * @brief Find the index of a character in a string.
 * @param str The string to search.
 * @param c The character to find.
 * @return Index of the first occurrence, or -1 if not found.
 */
int string_index_of(const char *str, char c);

/**
 * @brief Check if a string contains a character.
 * @param str The string to search.
 * @param c The character to check.
 * @return 1 if character exists, 0 otherwise.
 */
int string_contains(const char *str, char c);

/**
 * @brief Count occurrences of a character in a string.
 * @param str The string to search.
 * @param c The character to count.
 * @return Number of occurrences.
 */
int string_count_char(const char *str, char c);

/**
 * @brief Convert all characters in a string to uppercase.
 * @param str The string to convert.
 * @return Pointer to the modified string.
 */
char *string_to_upper(char *str);

/**
 * @brief Convert all characters in a string to lowercase.
 * @param str The string to convert.
 * @return Pointer to the modified string.
 */
char *string_to_lower(char *str);

/**
 * @brief Get the length of a string.
 * @param str The string.
 * @return Number of characters in the string.
 */
int string_length(const char *str);

/**
 * @brief Concatenate source string to destination string.
 * @param dest Destination string buffer.
 * @param src Source string to append.
 * @return Pointer to the concatenated string (dest).
 */
char *string_concat(char *dest, const char *src);

/**
 * @brief Copy source string to destination string.
 * @param dest Destination string buffer.
 * @param src Source string to copy.
 * @return Pointer to the destination string.
 */
char *string_copy(char *dest, const char *src);

/**
 * @brief Compare two strings.
 * @param a First string.
 * @param b Second string.
 * @return 0 if equal, negative if a < b, positive if a > b.
 */
int string_compare(const char *a, const char *b);

/**
 * @brief Check if a string starts with a prefix.
 * @param str The string to check.
 * @param prefix The prefix to match.
 * @return 1 if string starts with prefix, 0 otherwise.
 */
int string_starts_with(const char *str, const char *prefix);

/**
 * @brief Check if a string ends with a suffix.
 * @param str The string to check.
 * @param suffix The suffix to match.
 * @return 1 if string ends with suffix, 0 otherwise.
 */
int string_ends_with(const char *str, const char *suffix);

/**
 * @brief Trim leading and trailing whitespace from a string.
 * @param str The string to trim.
 * @return Pointer to the trimmed string.
 */
char *string_trim(char *str);

/**
 * @brief Replace all occurrences of a character in a string with another character.
 * @param str The string to modify.
 * @param old The character to replace.
 * @param newc The replacement character.
 * @return Pointer to the modified string.
 */
char *string_replace(char *str, char old, char newc);

#endif
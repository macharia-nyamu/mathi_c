/*
* Mathi C Library - Validator Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/validator.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Check if a string represents a valid integer.
 * @param str Input string.
 * @return 1 if valid integer, 0 otherwise.
 */
int mathi_is_int(const char *str)
{
    if(!str || *str == '\0') return 0;
    char *endptr;
    strtol(str, &endptr, 10);
    return *endptr == '\0';
}

/**
 * @brief Check if a string represents a valid float.
 * @param str Input string.
 * @return 1 if valid float, 0 otherwise.
 */
int mathi_is_float(const char *str)
{
    if(!str || *str == '\0') return 0;
    char *endptr;
    strtof(str, &endptr);
    return *endptr == '\0';
}

/**
 * @brief Check if a string represents a valid double.
 * @param str Input string.
 * @return 1 if valid double, 0 otherwise.
 */
int mathi_is_double(const char *str)
{
    if(!str || *str == '\0') return 0;
    char *endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

/**
 * @brief Check if a string is a number (int, float, or double).
 * @param str Input string.
 * @return 1 if string is a number, 0 otherwise.
 */
int mathi_is_number(const char *str)
{
    return mathi_is_int(str) || mathi_is_float(str) || mathi_is_double(str);
}

/**
 * @brief Check if a string contains only alphabetic characters.
 * @param str Input string.
 * @return 1 if alphabetic, 0 otherwise.
 */
int mathi_is_alpha(const char *str)
{
    if(!str) return 0;
    while(*str) { if(!isalpha(*str)) return 0; str++; }
    return 1;
}

/**
 * @brief Check if a string contains only alphanumeric characters.
 * @param str Input string.
 * @return 1 if alphanumeric, 0 otherwise.
 */
int mathi_is_alnum(const char *str)
{
    if(!str) return 0;
    while(*str) { if(!isalnum(*str)) return 0; str++; }
    return 1;
}

/**
 * @brief Check if a string contains only binary digits (0 or 1).
 * @param str Input string.
 * @return 1 if binary, 0 otherwise.
 */
int mathi_is_binary(const char *str)
{
    if(!str) return 0;
    while(*str) { if(*str != '0' && *str != '1') return 0; str++; }
    return 1;
}

/**
 * @brief Check if a string contains only hexadecimal characters (0-9, A-F, a-f).
 * @param str Input string.
 * @return 1 if hexadecimal, 0 otherwise.
 */
int mathi_is_hex(const char *str)
{
    if(!str) return 0;
    while(*str) 
    {
        char c = *str;
        if(!((c >= '0' && c <= '9') || 
             (c >= 'A' && c <= 'F') || 
             (c >= 'a' && c <= 'f'))) return 0;
        str++;
    }
    return 1;
}

/**
 * @brief Check if an integer value is within a specified range.
 * @param value Value to check.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return 1 if value is in range [min, max], 0 otherwise.
 */
int mathi_in_range(int value, int min, int max)
{
    return value >= min && value <= max;
}
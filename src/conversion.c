/*
 * Mathi C Library - Conversion Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Functions for converting between binary, decimal, hexadecimal, strings, and doubles.
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "mathi/conversion.h"

/**
 * @brief Convert a binary string to a decimal integer.
 * @param bin Input binary string
 * @param result Pointer to store result
 * @return 0 on success, 2 on invalid input
 */
int mathi_bin_to_dcm(const char *bin, int *result)
{
    if (!bin || !result) 
        return 2;

    int res = 0;
    for (size_t i = 0; bin[i]; i++)
    {
        if (bin[i] == '1') 
            res = res * 2 + 1;
        else if (bin[i] == '0') 
            res *= 2;
        else 
            return 2; // invalid character
    }

    *result = res;
    return 0;
}

/**
 * @brief Convert a decimal integer to a binary string.
 * @param num Input integer
 * @param out Pointer to store output string (allocated inside)
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_dcm_to_bin(int num, char **out)
{
    if (!out) 
        return 2;

    char buffer[33];
    if (num == 0) 
    { 
        buffer[0] = '0'; 
        buffer[1] = '\0'; 
    }
    else 
    {
        int i = 0;
        unsigned int n = (unsigned int)num;
        while (n) 
        { 
            buffer[i++] = (n % 2) + '0'; 
            n /= 2; 
        }
        buffer[i] = '\0';

        // Reverse string
        for (int j = 0; j < i / 2; j++)
        {
            char tmp = buffer[j];
            buffer[j] = buffer[i - j - 1];
            buffer[i - j - 1] = tmp;
        }
    }

    *out = strdup(buffer);
    return (*out) ? 0 : 1;
}

/**
 * @brief Convert a hexadecimal string to a decimal integer.
 * @param hex Input hexadecimal string
 * @param result Pointer to store result
 * @return 0 on success, 2 on invalid input
 */
int mathi_hex_to_dcm(const char *hex, int *result)
{
    if (!hex || !result) 
        return 2;

    int res = 0;
    for (size_t i = 0; hex[i]; i++)
    {
        char c = toupper(hex[i]);
        int val = (c >= '0' && c <= '9') ? c - '0' :
                  (c >= 'A' && c <= 'F') ? 10 + c - 'A' : -1;

        if (val == -1) 
            return 2;

        res = res * 16 + val;
    }

    *result = res;
    return 0;
}

/**
 * @brief Convert a decimal integer to a hexadecimal string.
 * @param num Input integer
 * @param out Pointer to store output string (allocated inside)
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_dcm_to_hex(int num, char **out)
{
    if (!out) 
        return 2;

    char buffer[9];
    if (num == 0) 
    { 
        buffer[0] = '0'; 
        buffer[1] = '\0'; 
    }
    else 
    {
        int i = 0;
        unsigned int n = (unsigned int)num;
        while (n) 
        {
            int r = n % 16;
            buffer[i++] = (r < 10) ? r + '0' : r - 10 + 'A';
            n /= 16;
        }
        buffer[i] = '\0';

        // Reverse string
        for (int j = 0; j < i / 2; j++)
        {
            char tmp = buffer[j];
            buffer[j] = buffer[i - j - 1];
            buffer[i - j - 1] = tmp;
        }
    }

    *out = strdup(buffer);
    return (*out) ? 0 : 1;
}

/**
 * @brief Convert an integer to a string.
 * @param num Input integer
 * @param out Pointer to store output string (allocated inside)
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_int_to_str(int num, char **out)
{
    if (!out) 
        return 2;

    char buffer[12];
    sprintf(buffer, "%d", num);
    *out = strdup(buffer);
    return (*out) ? 0 : 1;
}

/**
 * @brief Convert a string to an integer.
 * @param str Input string
 * @param result Pointer to store integer result
 * @return 0 on success, 2 on invalid input
 */
int mathi_str_to_int(const char *str, int *result)
{
    if (!str || !result) 
        return 2;

    char *endptr;
    long val = strtol(str, &endptr, 10);
    if (*endptr != '\0') 
        return 2;

    *result = (int)val;
    return 0;
}

/**
 * @brief Convert a string to a double.
 * @param str Input string
 * @param result Pointer to store double result
 * @return 0 on success, 2 on invalid input
 */
int mathi_str_to_dbl(const char *str, double *result)
{
    if (!str || !result) 
        return 2;

    char *endptr;
    double val = strtod(str, &endptr);
    if (*endptr != '\0') 
        return 2;

    *result = val;
    return 0;
}
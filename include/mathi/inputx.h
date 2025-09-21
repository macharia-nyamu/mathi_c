/*
 * Mathi C Library - Input Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Provides safe user input functions: integer, double, binary, hex, and string input.
 */

#ifndef MATHI_INPUTX_H
#define MATHI_INPUTX_H

#include <stddef.h>

#define INPUT_OK              0
#define INPUT_EMPTY           1
#define INPUT_INVALID_INT     2
#define INPUT_INVALID_DOUBLE  3
#define INPUT_INVALID_BINARY  4
#define INPUT_INVALID_HEX     5

typedef struct {
    int code;   /**< Status code: 0 = OK, >0 = error */
    void *value;/**< Pointer to value (int*, double*, or char*) */
} InputResult;


/**
 * @brief Prompt the user and read an integer.
 * @param prompt Message to display
 * @return InputResult containing status and pointer to int
 */
InputResult mathi_get_int(const char *prompt);

/**
 * @brief Prompt the user and read a double.
 * @param prompt Message to display
 * @return InputResult containing status and pointer to double
 */
InputResult mathi_get_double(const char *prompt);

/**
 * @brief Prompt the user and read a binary string (e.g., "10101").
 * @param prompt Message to display
 * @return InputResult containing status and pointer to string
 */
InputResult mathi_get_binary(const char *prompt);

/**
 * @brief Prompt the user and read a hexadecimal string (e.g., "1A3F").
 * @param prompt Message to display
 * @return InputResult containing status and pointer to string
 */
InputResult mathi_get_hex(const char *prompt);

/**
 * @brief Prompt the user and read a string.
 * @param prompt Message to display
 * @return InputResult containing status and pointer to string
 */
InputResult mathi_get_string(const char *prompt);

#endif // MATHI_INPUTX_H
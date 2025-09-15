/**
 * Mathi C Library - Input Utilities
 * 
 * This header provides functions for safely reading and parsing user input,
 * including integers, doubles, binary strings, hexadecimal strings, and general strings.
 * Each function returns an InputResult struct containing a status code and the parsed value.
 * 
 * Input codes:
 * 0 - INPUT_OK: Success
 * 1 - INPUT_EMPTY: Input is empty
 * 2 - INPUT_INVALID_INT: Expected an integer
 * 3 - INPUT_INVALID_DOUBLE: Expected a number
 * 4 - INPUT_INVALID_BINARY: Expected 0/1 only
 * 5 - INPUT_INVALID_HEX: Expected 0-9, A-F only
 * 6 - INPUT_UNKNOWN: Unknown error
 * 
 * @file inputx.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_INPUTX_H
#define MATHI_INPUTX_H

/** Structure to hold parsed input and status code */
typedef struct {
    int code;       /**< Status code of input */
    void *value;    /**< Pointer to parsed value (int*, double*, char*, etc.) */
} InputResult;

/* --- Input Functions --- */

/**
 * @brief Get an integer input from the user.
 * @param prompt Prompt string to display.
 * @return InputResult struct containing status code and parsed integer.
 */
InputResult get_int(const char *prompt);

/**
 * @brief Get a double input from the user.
 * @param prompt Prompt string to display.
 * @return InputResult struct containing status code and parsed double.
 */
InputResult get_double(const char *prompt);

/**
 * @brief Get a binary string input from the user.
 * @param prompt Prompt string to display.
 * @return InputResult struct containing status code and parsed binary string.
 */
InputResult get_binary(const char *prompt);

/**
 * @brief Get a hexadecimal string input from the user.
 * @param prompt Prompt string to display.
 * @return InputResult struct containing status code and parsed hexadecimal string.
 */
InputResult get_hex(const char *prompt);

/**
 * @brief Get a general string input from the user.
 * @param prompt Prompt string to display.
 * @return InputResult struct containing status code and input string.
 */
InputResult get_string(const char *prompt);

#endif
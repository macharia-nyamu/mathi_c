/*
 * Mathi C Library - Utilities
 * utils.h
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_UTILS_H
#define MATHI_UTILS_H

#include <stddef.h>

/**
 * @file utils.h
 * @brief General utility functions for swapping, clamping, and memory operations.
 */

/**
 * @brief Swap two integers in place.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void mathi_swap_int(int *a, int *b);

/**
 * @brief Swap two doubles in place.
 * @param a Pointer to the first double.
 * @param b Pointer to the second double.
 */
void mathi_swap_double(double *a, double *b);

/**
 * @brief Swap two characters in place.
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 */
void mathi_swap_char(char *a, char *b);

/**
 * @brief Clamp an integer to a specified range.
 * @param value The value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return The clamped value within [min, max].
 */
int mathi_clamp_int(int value, int min, int max);

/**
 * @brief Clamp a double to a specified range.
 * @param value The value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return The clamped value within [min, max].
 */
double mathi_clamp_double(double value, double min, double max);

/**
 * @brief Set a memory block to zero.
 * @param ptr Pointer to the memory block.
 * @param size Size of the memory block in bytes.
 */
void mathi_mem_zero(void *ptr, size_t size);

/**
 * @brief Copy a memory block from source to destination.
 * @param dest Destination pointer.
 * @param src Source pointer.
 * @param size Size of the memory block in bytes.
 */
void mathi_mem_copy(void *dest, const void *src, size_t size);

/**
 * @brief Swap two memory blocks of arbitrary size.
 * @param a Pointer to the first memory block.
 * @param b Pointer to the second memory block.
 * @param size Size of the memory blocks in bytes.
 */
void mathi_mem_swap(void *a, void *b, size_t size);

#endif // MATHI_UTILS_H
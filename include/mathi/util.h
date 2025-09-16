/*
 * Mathi C Library
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_UTIL_H
#define MATHI_UTIL_H

#include <stddef.h>

/**
 * @file util.h
 * @brief Utility functions for swapping, clamping, and memory operations.
 */

/**
 * @brief Swap two integers in place.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap_int(int *a, int *b);

/**
 * @brief Swap two double values in place.
 * @param a Pointer to the first double.
 * @param b Pointer to the second double.
 */
void swap_double(double *a, double *b);

/**
 * @brief Swap two characters in place.
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 */
void swap_char(char *a, char *b);

/**
 * @brief Clamp an integer value between a minimum and maximum.
 * @param value The value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return The clamped value.
 */
int clamp_int(int value, int min, int max);

/**
 * @brief Clamp a double value between a minimum and maximum.
 * @param value The value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return The clamped value.
 */
double clamp_double(double value, double min, double max);

/**
 * @brief Set a block of memory to zero.
 * @param ptr Pointer to the memory block.
 * @param size Size of the memory block in bytes.
 */
void mem_zero(void *ptr, size_t size);

/**
 * @brief Copy a block of memory.
 * @param dest Destination memory block.
 * @param src Source memory block.
 * @param size Size of the memory block in bytes.
 */
void mem_copy(void *dest, const void *src, size_t size);

/**
 * @brief Swap two memory blocks of arbitrary size.
 * @param a Pointer to the first memory block.
 * @param b Pointer to the second memory block.
 * @param size Size of each memory block in bytes.
 */
void mem_swap(void *a, void *b, size_t size);

#endif
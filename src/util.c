/*
* Mathi C Library - Utility Helpers
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Swap two integers.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void mathi_swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @brief Swap two double values.
 * @param a Pointer to the first double.
 * @param b Pointer to the second double.
 */
void mathi_swap_double(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @brief Swap two characters.
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 */
void mathi_swap_char(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @brief Clamp an integer value within a specified range.
 * @param value Value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return Clamped integer.
 */
int mathi_clamp_int(int value, int min, int max)
{
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

/**
 * @brief Clamp a double value within a specified range.
 * @param value Value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return Clamped double.
 */
double mathi_clamp_double(double value, double min, double max)
{
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

/**
 * @brief Set a memory block to zero.
 * @param ptr Pointer to the memory block.
 * @param size Size of the memory block in bytes.
 */
void mathi_mem_zero(void *ptr, size_t size)
{
    memset(ptr, 0, size);
}

/**
 * @brief Copy memory from source to destination.
 * @param dest Destination memory block.
 * @param src Source memory block.
 * @param size Number of bytes to copy.
 */
void mathi_mem_copy(void *dest, const void *src, size_t size)
{
    memcpy(dest, src, size);
}

/**
 * @brief Swap two memory blocks of a given size.
 * @param a Pointer to the first memory block.
 * @param b Pointer to the second memory block.
 * @param size Number of bytes to swap.
 */
void mathi_mem_swap(void *a, void *b, size_t size)
{
    unsigned char *p = a, *q = b, tmp;
    for(size_t i = 0; i < size; i++)
    {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}
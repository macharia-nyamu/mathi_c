/*
 * Mathi C Library - Printing Utilities
 * print.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_PRINT_H
#define MATHI_PRINT_H

#include <stddef.h>
#include "mathi/ds.h"

/**
 * @file mathi/print.h
 * @brief Functions to print arrays, matrices, linked lists, strings, and byte data.
 */


/**
 * @brief Print a linked list of integers.
 * @param head Pointer to the head node
 * @param name Label to display before the list
 */
void mathi_prnt_linked_list(Node *head, const char *name);


/**
 * @brief Print an integer array.
 * @param arr Pointer to array
 * @param n Number of elements
 * @param name Label to display before the array
 */
void mathi_prnt_arr(int *arr, int n, const char *name);


/**
 * @brief Print a 2D integer matrix.
 * @param m Pointer to array of row pointers
 * @param rows Number of rows
 * @param cols Number of columns
 * @param name Label to display before the matrix
 */
void mathi_prnt_matrix(int *m[], int rows, int cols, const char *name);


/**
 * @brief Print a string with a label.
 * @param label Label to display
 * @param str String to print
 */
void mathi_prnt_str(const char *label, const char *str);


/**
 * @brief Print byte data as unsigned integers.
 * @param data Pointer to byte array
 * @param len Number of bytes
 * @param name Label to display before the byte array
 */
void mathi_prnt_bytes(const unsigned char *data, size_t len, const char *name);

void mathi_prnt_int_pair(const char *label, int a, int b);

void mathi_prnt_double_pair(const char *label, double x, double y);

void mathi_prnt_char_pair(const char *label, char c1, char c2);

void mathi_prnt_mem(const char *label, char *mem, size_t n);

#endif // MATHI_PRINT_H
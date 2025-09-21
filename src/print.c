/*
 * Mathi C Library - Printing Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#include <stdio.h>
#include "mathi/print.h"

/**
 * @brief Print a linked list of integers.
 * @param head Pointer to the head of the linked list.
 * @param name Name label for printing.
 */
void mathi_prnt_linked_list(Node *head, const char *name) 
{
    printf("%s = [", name);
    Node *current = head;
    while(current) 
    {
        printf("%d", current->v);
        if(current->next) printf(", ");
        current = current->next;
    }
    printf("]\n\n");
}

/**
 * @brief Print an integer array.
 * @param arr Pointer to the array.
 * @param n Number of elements in the array.
 * @param name Name label for printing.
 */
void mathi_prnt_arr(int *arr, int n, const char *name)
{
    printf("%s = [", name);
    for(int i = 0; i < n; i++) 
    {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

/**
 * @brief Print a 2D integer matrix.
 * @param m Pointer to the 2D matrix.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @param name Name label for printing.
 */
void mathi_prnt_matrix(int *m[], int rows, int cols, const char *name) 
{
    printf("%s:\n", name);
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Print a string with a label.
 * @param label Label to print before the string.
 * @param str String to print.
 */
void mathi_prnt_str(const char *label, const char *str) 
{
    printf("%s: \"%s\"\n", label, str);
}

/**
 * @brief Print a byte array.
 * @param data Pointer to the byte array.
 * @param len Number of bytes to print.
 * @param name Name label for printing.
 */
void mathi_prnt_bytes(const unsigned char *data, size_t len, const char *name) 
{
    if (!data) { printf("%s = NULL\n", name); return; }
    printf("%s = [", name);
    for (size_t i = 0; i < len; i++) 
    {
        printf("%u", data[i]);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
}

/**
 * @brief Print a pair of integers.
 * @param label Label to print before the pair.
 * @param a First integer.
 * @param b Second integer.
 */
void mathi_prnt_int_pair(const char *label, int a, int b) 
{
    printf("%s: a=%d, b=%d\n", label, a, b);
}

/**
 * @brief Print a pair of doubles.
 * @param label Label to print before the pair.
 * @param x First double.
 * @param y Second double.
 */
void mathi_prnt_double_pair(const char *label, double x, double y) 
{
    printf("%s: x=%.3f, y=%.3f\n", label, x, y);
}

/**
 * @brief Print a pair of characters.
 * @param label Label to print before the pair.
 * @param c1 First character.
 * @param c2 Second character.
 */
void mathi_prnt_char_pair(const char *label, char c1, char c2) 
{
    printf("%s: c1='%c', c2='%c'\n", label, c1, c2);
}

/**
 * @brief Print raw memory contents as unsigned integers.
 * @param label Label to print before the memory content.
 * @param mem Pointer to the memory block.
 * @param n Number of bytes to print.
 */
void mathi_prnt_mem(const char *label, char *mem, size_t n) 
{
    printf("%s: [", label);
    for(size_t i = 0; i < n; i++) 
    {
        printf("%d", (unsigned char)mem[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}
/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_double(double *a, double *b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_char(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int clamp_int(int value, int min, int max) {
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

double clamp_double(double value, double min, double max) {
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

void mem_zero(void *ptr, size_t size) {
    memset(ptr, 0, size);
}

void mem_copy(void *dest, const void *src, size_t size) {
    memcpy(dest, src, size);
}

void mem_swap(void *a, void *b, size_t size) {
    unsigned char *p = a, *q = b, tmp;
    for(size_t i = 0; i < size; i++) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}
/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int array_index_of(int *arr, int n, int value) {
    for(int i = 0; i < n; i++) if(arr[i] == value) return i;
    return -1;
}

int array_contains(int *arr, int n, int value) {
    return array_index_of(arr, n, value) != -1;
}

void array_reverse(int *arr, int n) {
    for(int i = 0, j = n - 1; i < j; i++, j--) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void array_copy(int *src, int *dest, int n) {
    for(int i = 0; i < n; i++) dest[i] = src[i];
}

void array_fill(int *arr, int n, int value) {
    for(int i = 0; i < n; i++) arr[i] = value;
}

int array_sum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

int array_max(int *arr, int n) {
    if(n <= 0) return 0;
    int max = arr[0];
    for(int i = 1; i < n; i++) if(arr[i] > max) max = arr[i];
    return max;
}

int array_min(int *arr, int n) {
    if(n <= 0) return 0;
    int min = arr[0];
    for(int i = 1; i < n; i++) if(arr[i] < min) min = arr[i];
    return min;
}

double array_average(int *arr, int n) {
    if(n <= 0) return 0;
    return (double)array_sum(arr, n) / n;
}

int array_equals(int *a, int *b, int n) {
    for(int i = 0; i < n; i++) if(a[i] != b[i]) return 0;
    return 1;
}

void array_shuffle(int *arr, int n) {
    srand((unsigned int)time(NULL));
    for(int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void array_unique(int *arr, int *n) {
    if(*n <= 1) return;
    int j = 0;
    for(int i = 1; i < *n; i++) {
        int found = 0;
        for(int k = 0; k <= j; k++) if(arr[i] == arr[k]) { found = 1; break; }
        if(!found) arr[++j] = arr[i];
    }
    *n = j + 1;
}
/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if(n <= 1) return n;
    int a = 0, b = 1, c, i;
    for(i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int count_occurrences(int arr[], int n, int value) {
    int count = 0;
    for(int i = 0; i < n; i++) if(arr[i] == value) count++;
    return count;
}

void rotate_array(int *arr, int n, int k) {
    k = k % n;
    if(k == 0) return;
    int *tmp = (int*)malloc(k * sizeof(int));
    for(int i = 0; i < k; i++) tmp[i] = arr[n - k + i];
    for(int i = n - 1; i >= k; i--) arr[i] = arr[i - k];
    for(int i = 0; i < k; i++) arr[i] = tmp[i];
    free(tmp);
}

int factorial_iterative(int n) {
    if(n < 0) return -1;
    int res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

int factorial_recursive(int n) {
    if(n < 0) return -1;
    if(n == 0 || n == 1) return 1;
    return n * factorial_recursive(n - 1);
}

int is_sorted(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) if(arr[i] > arr[i + 1]) return 0;
    return 1;
}

int nth_fibonacci(int n) {
    return fibonacci(n);
}

int sum_of_digits(int n) {
    int sum = 0;
    n = abs(n);
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int digital_root(int n) {
    n = abs(n);
    while(n >= 10) n = sum_of_digits(n);
    return n;
}
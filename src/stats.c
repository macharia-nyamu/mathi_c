/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(int *arr, int n) {
    if(n <= 0) return 0;
    double sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

int cmp_int(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double median(int *arr, int n) {
    if(n <= 0) return 0;
    int *copy = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copy[i] = arr[i];
    qsort(copy, n, sizeof(int), cmp_int);
    double med = (n % 2) ? copy[n/2] : (copy[n/2 - 1] + copy[n/2]) / 2.0;
    free(copy);
    return med;
}

double variance(int *arr, int n) {
    if(n <= 0) return 0;
    double m = mean(arr, n), sum = 0;
    for(int i = 0; i < n; i++) sum += (arr[i] - m) * (arr[i] - m);
    return n > 1 ? sum / (n - 1) : 0;  // sample variance
}

double stddev(int *arr, int n) {
    return sqrt(variance(arr, n));
}

int mode(int *arr, int n) {
    if(n <= 0) return 0;
    int *copy = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copy[i] = arr[i];
    qsort(copy, n, sizeof(int), cmp_int);
    int mode = copy[0], max_count = 1, count = 1;
    for(int i = 1; i < n; i++) {
        if(copy[i] == copy[i-1]) count++;
        else count = 1;
        if(count > max_count) { max_count = count; mode = copy[i]; }
    }
    free(copy);
    return mode;
}

double percentile(int *arr, int n, double p) {
    if(n <= 0) return 0;
    int *copy = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) copy[i] = arr[i];
    qsort(copy, n, sizeof(int), cmp_int);
    double rank = (p / 100.0) * (n - 1);
    int lo = (int)rank, hi = lo + 1;
    double frac = rank - lo;
    double val = copy[lo];
    if(hi < n) val += frac * (copy[hi] - copy[lo]);
    free(copy);
    return val;
}
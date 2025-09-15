/*
* Mathi C Library - statistics_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "mathi/stats.h"

static int arr_equal(int *arr1, int *arr2, int n) {
    for(int i = 0; i < n; i++) if(arr1[i] != arr2[i]) return 0;
    return 1;
}

static void print_array(const char *label, int *arr, int n) {
    printf("%s: [", label);
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

void test_statistics() {
    int data[] = {1, 2, 2, 3, 4, 5, 5, 5, 6};
    int n = sizeof(data)/sizeof(data[0]);

    printf("Data array:\n");
    print_array("Data", data, n);
    printf("\n");

    // Mean
    double m = mean(data, n);
    printf("Mean: %.6f\n", m);
    assert(fabs(m - 3.666667) < 1e-6);

    // Median
    double med = median(data, n);
    printf("Median: %.6f\n", med);
    assert(fabs(med - 4.0) < 1e-6);

    // Variance (sample)
    double var = variance(data, n);
    printf("Variance: %.6f\n", var);
    assert(fabs(var - 3.0) < 1e-6);

    // Stddev
    double sd = stddev(data, n);
    printf("Standard Deviation: %.6f\n", sd);
    assert(fabs(sd - sqrt(3.0)) < 1e-6);

    // Mode
    int mo = mode(data, n);
    printf("Mode: %d\n", mo);
    assert(mo == 5);

    // Percentiles
    double p25 = percentile(data, n, 25);
    double p50 = percentile(data, n, 50);
    double p75 = percentile(data, n, 75);
    printf("Percentiles:\n");
    printf("  25th percentile: %.6f\n", p25);
    printf("  50th percentile: %.6f\n", p50);
    printf("  75th percentile: %.6f\n", p75);
    assert(fabs(p25 - 2.0) < 1e-6);
    assert(fabs(p50 - 4.0) < 1e-6);
    assert(fabs(p75 - 5.0) < 1e-6);

    printf("\nAll statistics tests passed!\n");
}

int main() {
    test_statistics();
    return 0;
}
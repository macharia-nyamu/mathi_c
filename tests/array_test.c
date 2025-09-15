#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/array.h"

void print_array(int *arr, int n, const char *name) {
    printf("%s = [", name);
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

void test_array_index_of() {
    printf("Testing array_index_of...\n");
    int arr[] = {1, 2, 3, 4, 5};
    print_array(arr, 5, "arr");
    int idx1 = array_index_of(arr, 5, 3);
    int idx2 = array_index_of(arr, 5, 6);
    printf("array_index_of(arr, 3) = %d\n", idx1);
    printf("array_index_of(arr, 6) = %d\n", idx2);
    assert(idx1 == 2);
    assert(idx2 == -1);
}

void test_array_contains() {
    printf("Testing array_contains...\n");
    int arr[] = {1, 2, 3};
    print_array(arr, 3, "arr");
    int c1 = array_contains(arr, 3, 2);
    int c2 = array_contains(arr, 3, 5);
    printf("array_contains(arr, 2) = %d\n", c1);
    printf("array_contains(arr, 5) = %d\n", c2);
    assert(c1 == 1);
    assert(c2 == 0);
}

void test_array_reverse() {
    printf("Testing array_reverse...\n");
    int arr[] = {1, 2, 3, 4};
    print_array(arr, 4, "original arr");
    array_reverse(arr, 4);
    print_array(arr, 4, "arr after reverse");
    int expected[] = {4, 3, 2, 1};
    print_array(expected, 4, "expected arr");
    for(int i = 0; i < 4; i++) assert(arr[i] == expected[i]);
}

void test_array_copy() {
    printf("Testing array_copy...\n");
    int src[] = {1, 2, 3};
    int dest[3];
    print_array(src, 3, "src");
    array_copy(src, dest, 3);
    print_array(dest, 3, "dest after copy");
    for(int i = 0; i < 3; i++) assert(dest[i] == src[i]);
}

void test_array_fill() {
    printf("Testing array_fill...\n");
    int arr[5];
    array_fill(arr, 5, 7);
    print_array(arr, 5, "arr after fill with 7");
    for(int i = 0; i < 5; i++) assert(arr[i] == 7);
}

void test_array_sum() {
    printf("Testing array_sum...\n");
    int arr[] = {1, 2, 3, 4};
    print_array(arr, 4, "arr");
    int sum = array_sum(arr, 4);
    printf("array_sum(arr) = %d\n", sum);
    assert(sum == 10);
}

void test_array_max_min() {
    printf("Testing array_max & array_min...\n");
    int arr[] = {3, 7, 1, 9, 2};
    print_array(arr, 5, "arr");
    int max = array_max(arr, 5);
    int min = array_min(arr, 5);
    printf("array_max(arr) = %d\n", max);
    printf("array_min(arr) = %d\n", min);
    assert(max == 9);
    assert(min == 1);
}

void test_array_average() {
    printf("Testing array_average...\n");
    int arr[] = {2, 4, 6, 8};
    print_array(arr, 4, "arr");
    double avg = array_average(arr, 4);
    printf("array_average(arr) = %.2f\n", avg);
    assert(avg == 5.0);
}

void test_array_equals() {
    printf("Testing array_equals...\n");
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3};
    int c[] = {3, 2, 1};
    print_array(a, 3, "a");
    print_array(b, 3, "b");
    print_array(c, 3, "c");
    int eq1 = array_equals(a, b, 3);
    int eq2 = array_equals(a, c, 3);
    printf("array_equals(a, b) = %d\n", eq1);
    printf("array_equals(a, c) = %d\n", eq2);
    assert(eq1 == 1);
    assert(eq2 == 0);
}

void test_array_shuffle() {
    printf("Testing array_shuffle...\n");
    int arr[] = {1, 2, 3, 4, 5};
    print_array(arr, 5, "original arr");
    array_shuffle(arr, 5);
    print_array(arr, 5, "arr after shuffle");
    int copy[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) {
        int found = 0;
        for(int j = 0; j < 5; j++) if(arr[i] == copy[j]) found = 1;
        assert(found);
    }
}

void test_array_unique() {
    printf("Testing array_unique...\n");
    int arr[] = {1, 2, 2, 3, 1, 4};
    int n = 6;
    print_array(arr, n, "original arr");
    array_unique(arr, &n);
    print_array(arr, n, "arr after unique");
    printf("new length = %d\n", n);
    int expected[] = {1, 2, 3, 4};
    print_array(expected, 4, "expected arr");
    assert(n == 4);
    for(int i = 0; i < n; i++) assert(arr[i] == expected[i]);
}

int main() {
    test_array_index_of();
    test_array_contains();
    test_array_reverse();
    test_array_copy();
    test_array_fill();
    test_array_sum();
    test_array_max_min();
    test_array_average();
    test_array_equals();
    test_array_shuffle();
    test_array_unique();

    printf("All array tests passed successfully!\n");
    return 0;
}
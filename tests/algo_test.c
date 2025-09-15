#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/algo.h"

void print_array(int *arr, int n, const char *name) {
    printf("%s = [", name);
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}

void test_fibonacci() {
    printf("Testing fibonacci...\n");
    int vals[] = {0, 1, 5, 10};
    for(int i = 0; i < 4; i++) {
        int f = fibonacci(vals[i]);
        printf("fibonacci(%d) = %d\n", vals[i], f);
        assert(f == (vals[i]==0?0:(vals[i]==1?1:(vals[i]==5?5:55)))); // keep original assertions
    }
}

void test_count_occurrences() {
    printf("Testing count_occurrences...\n");
    int arr[] = {1, 2, 3, 2, 2, 4, 5};
    print_array(arr, 7, "arr");
    int v1 = count_occurrences(arr, 7, 2);
    printf("count_occurrences(arr, 2) = %d\n", v1);
    int v2 = count_occurrences(arr, 7, 5);
    printf("count_occurrences(arr, 5) = %d\n", v2);
    int v3 = count_occurrences(arr, 7, 6);
    printf("count_occurrences(arr, 6) = %d\n", v3);
    assert(v1 == 3);
    assert(v2 == 1);
    assert(v3 == 0);
}

void test_rotate_array() {
    printf("Testing rotate_array...\n");
    int arr[] = {1, 2, 3, 4, 5};
    print_array(arr, 5, "original arr");
    rotate_array(arr, 5, 2);
    print_array(arr, 5, "arr after rotate 2");
    int expected[] = {4, 5, 1, 2, 3};
    print_array(expected, 5, "expected arr");
    for(int i = 0; i < 5; i++) assert(arr[i] == expected[i]);

    rotate_array(arr, 5, 5); // rotate by n -> unchanged
    print_array(arr, 5, "arr after rotate 5");
    int unchanged[] = {4, 5, 1, 2, 3};
    print_array(unchanged, 5, "unchanged expected");
    for(int i = 0; i < 5; i++) assert(arr[i] == unchanged[i]);
}

void test_factorial() {
    printf("Testing factorial_iterative & factorial_recursive...\n");
    int vals[] = {0, 5, -3};
    for(int i = 0; i < 3; i++) {
        int fi = factorial_iterative(vals[i]);
        int fr = factorial_recursive(vals[i]);
        printf("factorial_iterative(%d) = %d\n", vals[i], fi);
        printf("factorial_recursive(%d) = %d\n", vals[i], fr);
    }
    assert(factorial_iterative(0) == 1);
    assert(factorial_iterative(5) == 120);
    assert(factorial_iterative(-3) == -1);

    assert(factorial_recursive(0) == 1);
    assert(factorial_recursive(6) == 720);
    assert(factorial_recursive(-1) == -1);
}

void test_is_sorted() {
    printf("Testing is_sorted...\n");
    int sorted[] = {1, 2, 2, 4, 5};
    int unsorted[] = {5, 2, 3, 1};
    print_array(sorted, 5, "sorted");
    print_array(unsorted, 4, "unsorted");
    int s1 = is_sorted(sorted, 5);
    int s2 = is_sorted(unsorted, 4);
    printf("is_sorted(sorted) = %d\n", s1);
    printf("is_sorted(unsorted) = %d\n", s2);
    assert(s1 == 1);
    assert(s2 == 0);
}

void test_nth_fibonacci() {
    printf("Testing nth_fibonacci...\n");
    int n0 = nth_fibonacci(0);
    int n7 = nth_fibonacci(7);
    printf("nth_fibonacci(0) = %d\n", n0);
    printf("nth_fibonacci(7) = %d\n", n7);
    assert(n0 == 0);
    assert(n7 == 13);
}

void test_sum_of_digits() {
    printf("Testing sum_of_digits...\n");
    int nums[] = {12345, -123, 0};
    for(int i = 0; i < 3; i++) {
        int sum = sum_of_digits(nums[i]);
        printf("sum_of_digits(%d) = %d\n", nums[i], sum);
    }
    assert(sum_of_digits(12345) == 15);
    assert(sum_of_digits(-123) == 6);
    assert(sum_of_digits(0) == 0);
}

void test_digital_root() {
    printf("Testing digital_root...\n");
    int nums[] = {942, 0, -9876};
    for(int i = 0; i < 3; i++) {
        int dr = digital_root(nums[i]);
        printf("digital_root(%d) = %d\n", nums[i], dr);
    }
    assert(digital_root(942) == 6);
    assert(digital_root(0) == 0);
    assert(digital_root(-9876) == 3);
}

int main() {
    test_fibonacci();
    test_count_occurrences();
    test_rotate_array();
    test_factorial();
    test_is_sorted();
    test_nth_fibonacci();
    test_sum_of_digits();
    test_digital_root();

    printf("All algo tests passed successfully!\n");
    return 0;
}
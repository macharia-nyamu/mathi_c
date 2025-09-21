#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/array.h"
#include "mathi/print.h"

void test_mathi_arr_index() 
{
    printf("Testing mathi arr index...\n");

    int arr[] = {1, 2, 3, 4, 5};
    mathi_prnt_arr(arr, 5, "arr");

    int idx1 = mathi_arr_index(arr, 5, 3);
    int idx2 = mathi_arr_index(arr, 5, 6);

    printf("mathi_arr_index(arr, 3) = %d\n", idx1);
    printf("mathi_arr_index(arr, 6) = %d\n", idx2);

    assert(idx1 == 2);
    assert(idx2 == -1);

    printf("\n");
}

void test_array_contains() 
{
    printf("Testing array_contains...\n");

    int arr[] = {1, 2, 3};
    mathi_prnt_arr(arr, 3, "arr");

    int c1 = mathi_arr_contains(arr, 3, 2);
    int c2 = mathi_arr_contains(arr, 3, 5);

    printf("array_contains(arr, 2) = %d\n", c1);
    printf("array_contains(arr, 5) = %d\n", c2);

    assert(c1 == 1);
    assert(c2 == 0);

    printf("\n");
}

void test_array_reverse() 
{
    printf("Testing array_reverse...\n");

    int arr[] = {1, 2, 3, 4};
    mathi_prnt_arr(arr, 4, "original arr");

    mathi_arr_reverse(arr, 4);
    mathi_prnt_arr(arr, 4, "arr after reverse");

    int expected[] = {4, 3, 2, 1};
    mathi_prnt_arr(expected, 4, "expected arr");

    for(int i = 0; i < 4; i++) 
    {
        assert(arr[i] == expected[i]);
    }

    printf("\n");
}

void test_array_copy() 
{
    printf("Testing array_copy...\n");

    int src[] = {1, 2, 3};
    int dest[3];

    mathi_prnt_arr(src, 3, "src");

    mathi_arr_copy(src, dest, 3);
    mathi_prnt_arr(dest, 3, "dest after copy");

    for(int i = 0; i < 3; i++) 
    {
        assert(dest[i] == src[i]);
    }

    printf("\n");
}

void test_array_fill() 
{
    printf("Testing array_fill...\n");

    int arr[5];
    mathi_arr_fill(arr, 5, 7);
    mathi_prnt_arr(arr, 5, "arr after fill with 7");

    for(int i = 0; i < 5; i++) 
    {
        assert(arr[i] == 7);
    }

    printf("\n");
}

void test_array_sum() 
{
    printf("Testing array_sum...\n");

    int arr[] = {1, 2, 3, 4};
    mathi_prnt_arr(arr, 4, "arr");

    int sum = mathi_arr_sum(arr, 4);
    printf("array_sum(arr) = %d\n", sum);

    assert(sum == 10);

    printf("\n");
}

void test_array_max_min() 
{
    printf("Testing array_max & array_min...\n");

    int arr[] = {3, 7, 1, 9, 2};
    mathi_prnt_arr(arr, 5, "arr");

    int max = mathi_arr_max(arr, 5);
    int min = mathi_arr_min(arr, 5);

    printf("array_max(arr) = %d\n", max);
    printf("array_min(arr) = %d\n", min);

    assert(max == 9);
    assert(min == 1);

    printf("\n");
}

void test_array_average() 
{
    printf("Testing array_average...\n");

    int arr[] = {2, 4, 6, 8};
    mathi_prnt_arr(arr, 4, "arr");

    double avg = mathi_arr_average(arr, 4);
    printf("array_average(arr) = %.2f\n", avg);

    assert(avg == 5.0);

    printf("\n");
}

void test_array_equals() 
{
    printf("Testing array_equals...\n");

    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3};
    int c[] = {3, 2, 1};

    mathi_prnt_arr(a, 3, "a");
    mathi_prnt_arr(b, 3, "b");
    mathi_prnt_arr(c, 3, "c");

    int eq1 = mathi_arr_equal(a, b, 3);
    int eq2 = mathi_arr_equal(a, c, 3);

    printf("array_equals(a, b) = %d\n", eq1);
    printf("array_equals(a, c) = %d\n", eq2);

    assert(eq1 == 1);
    assert(eq2 == 0);

    printf("\n");
}

void test_array_shuffle() 
{
    printf("Testing array_shuffle...\n");

    int arr[] = {1, 2, 3, 4, 5};
    mathi_prnt_arr(arr, 5, "original arr");

    mathi_arr_shuffle(arr, 5);
    mathi_prnt_arr(arr, 5, "arr after shuffle");

    int copy[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++) 
    {
        int found = 0;
        for(int j = 0; j < 5; j++) 
        {
            if(arr[i] == copy[j]) 
            {
                found = 1;
            }
        }
        assert(found);
    }

    printf("\n");
}

void test_array_unique() 
{
    printf("Testing array_unique...\n");

    int arr[] = {1, 2, 2, 3, 1, 4};
    size_t n = 6;

    mathi_prnt_arr(arr, n, "original arr");
    mathi_arr_distinct(arr, &n);
    mathi_prnt_arr(arr, n, "arr after unique");
    printf("new length = %zu\n", n);

    int expected[] = {1, 2, 3, 4};
    assert(n == 4);
    for(size_t i = 0; i < n; i++) 
    {
        assert(arr[i] == expected[i]);
    }

    printf("\n");
}

void test_mathi_arr_sorted() 
{
    printf("Testing mathi_arr_sorted...\n");

    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {1, 2, 2, 3, 4};
    int arr4[] = {10};
    int arr5[] = {};

    printf("arr1 sorted? %d\n", mathi_arr_sorted(arr1, 5));
    assert(mathi_arr_sorted(arr1, 5) == 1);

    printf("arr2 sorted? %d\n", mathi_arr_sorted(arr2, 5));
    assert(mathi_arr_sorted(arr2, 5) == 0);

    printf("arr3 sorted? %d\n", mathi_arr_sorted(arr3, 5));
    assert(mathi_arr_sorted(arr3, 5) == 1);

    printf("arr4 sorted? %d\n", mathi_arr_sorted(arr4, 1));
    assert(mathi_arr_sorted(arr4, 1) == 1);

    printf("arr5 sorted? %d\n", mathi_arr_sorted(arr5, 0));
    assert(mathi_arr_sorted(arr5, 0) == 1);

    printf("All mathi_arr_sorted tests passed!\n\n");
}

void test_rotate_array() 
{
    printf("Testing rotate_array...\n");

    int arr[] = {1, 2, 3, 4, 5};
    mathi_prnt_arr(arr, 5, "original arr");

    mathi_arr_rotate(arr, 5, 2);
    mathi_prnt_arr(arr, 5, "arr after rotate 2");

    int expected[] = {4, 5, 1, 2, 3};
    mathi_prnt_arr(expected, 5, "expected arr");

    for(int i = 0; i < 5; i++) 
    {
        assert(arr[i] == expected[i]);
    }

    mathi_arr_rotate(arr, 5, 5);
    mathi_prnt_arr(arr, 5, "arr after rotate 5");

    int unchanged[] = {4, 5, 1, 2, 3};
    mathi_prnt_arr(unchanged, 5, "unchanged expected");

    for(int i = 0; i < 5; i++) 
    {
        assert(arr[i] == unchanged[i]);
    }

    printf("\n");
}

void test_is_sorted() 
{
    printf("Testing is_sorted...\n");

    int sorted[] = {1, 2, 2, 4, 5};
    int unsorted[] = {5, 2, 3, 1};

    mathi_prnt_arr(sorted, 5, "sorted");
    mathi_prnt_arr(unsorted, 4, "unsorted");

    int s1 = mathi_arr_sorted(sorted, 5);
    int s2 = mathi_arr_sorted(unsorted, 4);

    printf("is_sorted(sorted) = %d\n", s1);
    printf("is_sorted(unsorted) = %d\n", s2);

    assert(s1 == 1);
    assert(s2 == 0);

    printf("\n");
}

int main() 
{
    test_mathi_arr_index();
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
    test_mathi_arr_sorted();
    test_rotate_array();
    test_is_sorted();

    printf("All array tests passed successfully!\n");

    return 0;
}
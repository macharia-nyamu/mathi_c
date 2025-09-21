#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/algo.h"
#include "mathi/print.h"

void test_fibonacci() 
{
    printf("Testing fibonacci...\n");

    int times = 15; // expected 610
    printf("Fibonacci(%d) = %d\n", times, mathi_fibonacci(times));

    printf("\n");
}

void test_count_occurrences() 
{
    printf("Testing count_occurrences...\n");

    int arr[] = {1, 2, 3, 2, 2, 4, 5};
    mathi_prnt_arr(arr, 7, "arr");

    int v1 = mathi_occurs(arr, 7, 2);
    int v2 = mathi_occurs(arr, 7, 5);
    int v3 = mathi_occurs(arr, 7, 6);

    printf("count_occurrences(arr, 2) = %d\n", v1);
    printf("count_occurrences(arr, 5) = %d\n", v2);
    printf("count_occurrences(arr, 6) = %d\n", v3);

    assert(v1 == 3);
    assert(v2 == 1);
    assert(v3 == 0);

    printf("\n");
}

void test_factorial() 
{
    printf("Testing factorial_iterative & factorial_recursive...\n");

    int vals[] = {0, 5, -3};

    for(int i = 0; i < 3; i++) 
    {
        int fi = mathi_factorial_iterative(vals[i]);
        int fr = mathi_factorial_recursive(vals[i]);

        printf("factorial_iterative(%d) = %d\n", vals[i], fi);
        printf("factorial_recursive(%d) = %d\n", vals[i], fr);

        printf("\n");
    }

    assert(mathi_factorial_iterative(0) == 1);
    assert(mathi_factorial_iterative(5) == 120);
    assert(mathi_factorial_iterative(-3) == -1);

    assert(mathi_factorial_recursive(0) == 1);
    assert(mathi_factorial_recursive(6) == 720);
    assert(mathi_factorial_recursive(-1) == -1);
}

void test_sum_of_digits() 
{
    printf("Testing sum_of_digits...\n");

    int nums[] = {123545, -123, 0};

    for(int i = 0; i < 3; i++) 
    {
        int sum = mathi_dgts_sum(nums[i]);
        printf("sum_of_digits(%d) = %d\n", nums[i], sum);
    }

    assert(mathi_dgts_sum(12345) == 15);
    assert(mathi_dgts_sum(-123) == 6);
    assert(mathi_dgts_sum(0) == 0);

    printf("\n");
}

void test_digital_root() 
{
    printf("Testing digital_root...\n");

    int nums[] = {942, 0, -9876};

    for(int i = 0; i < 3; i++) 
    {
        int dr = mathi_rt_digital(nums[i]);
        printf("digital_root(%d) = %d\n", nums[i], dr);
    }

    assert(mathi_rt_digital(942) == 6);
    assert(mathi_rt_digital(0) == 0);
    assert(mathi_rt_digital(-9876) == 3);

    printf("\n");
}

int main() 
{
    test_fibonacci();
    test_count_occurrences();
    test_factorial();
    test_sum_of_digits();
    test_digital_root();

    printf("All algo tests passed successfully!\n");

    return 0;
}
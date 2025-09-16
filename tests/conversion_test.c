/*
* Mathi C Library - Conversion Test
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/conversion.h"

void mathi_prnt_bytes(const unsigned char *data, size_t len, const char *name) 
{
    if (!data) 
    { 
        printf("%s = NULL\n", name); 
        return; 
    }

    printf("%s = [", name);
    for(size_t i = 0; i < len; i++) 
    {
        printf("%u", data[i]);
        if(i < len - 1) 
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void test_binary_to_decimal() 
{
    printf("\nTesting binary_to_decimal\n");

    const char *bins[] = {"101", "0", "1111", "102"};
    int val;

    for(int i = 0; i < 4; i++) 
    {
        int status = mathi_bin_to_dcm(bins[i], &val);
        printf("binary_to_decimal('%s') = %d (status=%d)\n", bins[i], val, status);
    }

    assert(mathi_bin_to_dcm("101", &val) == 0 && val == 5);
    assert(mathi_bin_to_dcm("0", &val) == 0 && val == 0);
    assert(mathi_bin_to_dcm("1111", &val) == 0 && val == 15);
    assert(mathi_bin_to_dcm("102", &val) == 2);

    printf("\n");
}

void test_decimal_to_binary() 
{
    printf("\nTesting decimal_to_binary\n");

    int nums[] = {5, 0, 15};
    char *str = NULL;

    for(int i = 0; i < 3; i++) 
    {
        int status = mathi_dcm_to_bin(nums[i], &str);
        printf("decimal_to_binary(%d) = '%s' (status=%d)\n", nums[i], str, status);
        free(str);
        str = NULL;
    }

    mathi_dcm_to_bin(15, &str);
    assert(strcmp(str, "1111") == 0);
    free(str);

    printf("\n");
}

void test_hex_to_decimal() 
{
    printf("\nTesting hex_to_decimal\n");

    const char *hexes[] = {"1A", "0", "FF", "G1"};
    int val;

    for(int i = 0; i < 4; i++) 
    {
        int status = mathi_hex_to_dcm(hexes[i], &val);
        printf("hex_to_decimal('%s') = %d (status=%d)\n", hexes[i], val, status);
    }

    assert(mathi_hex_to_dcm("1A", &val) == 0 && val == 26);
    assert(mathi_hex_to_dcm("0", &val) == 0 && val == 0);
    assert(mathi_hex_to_dcm("FF", &val) == 0 && val == 255);
    assert(mathi_hex_to_dcm("G1", &val) == 2);

    printf("\n");
}

void test_decimal_to_hex() 
{
    printf("\nTesting decimal_to_hex\n");

    int nums[] = {26, 0, 255};
    char *str = NULL;

    for(int i = 0; i < 3; i++) 
    {
        int status = mathi_dcm_to_hex(nums[i], &str);
        printf("decimal_to_hex(%d) = '%s' (status=%d)\n", nums[i], str, status);
        free(str);
        str = NULL;
    }

    mathi_dcm_to_hex(255, &str);
    assert(strcmp(str, "FF") == 0);
    free(str);

    printf("\n");
}

void test_int_to_string() 
{
    printf("\nTesting int_to_string\n");

    int nums[] = {123, 0, -456};
    char *str = NULL;

    for(int i = 0; i < 3; i++) 
    {
        int status = mathi_int_to_str(nums[i], &str);
        printf("int_to_string(%d) = '%s' (status=%d)\n", nums[i], str, status);
        free(str);
        str = NULL;
    }

    mathi_int_to_str(-456, &str);
    assert(strcmp(str, "-456") == 0);
    free(str);

    printf("\n");
}

void test_string_to_int() 
{
    printf("\nTesting string_to_int\n");

    const char *strs[] = {"123", "0", "-456", "abc"};
    int val;

    for(int i = 0; i < 4; i++) 
    {
        int status = mathi_str_to_int(strs[i], &val);
        printf("string_to_int('%s') = %d (status=%d)\n", strs[i], val, status);
    }

    assert(mathi_str_to_int("123", &val) == 0 && val == 123);
    assert(mathi_str_to_int("0", &val) == 0 && val == 0);
    assert(mathi_str_to_int("-456", &val) == 0 && val == -456);
    assert(mathi_str_to_int("abc", &val) == 2);

    printf("\n");
}

void test_string_to_double() 
{
    printf("\nTesting string_to_double\n");

    const char *strs[] = {"123.45", "0.0", "-456.78", "abc"};
    double val;

    for(int i = 0; i < 4; i++) 
    {
        int status = mathi_str_to_dbl(strs[i], &val);
        printf("string_to_double('%s') = %.2f (status=%d)\n", strs[i], val, status);
    }

    assert(mathi_str_to_dbl("123.45", &val) == 0 && val == 123.45);
    assert(mathi_str_to_dbl("0.0", &val) == 0 && val == 0.0);
    assert(mathi_str_to_dbl("-456.78", &val) == 0 && val == -456.78);
    assert(mathi_str_to_dbl("abc", &val) == 2);

    printf("\n");
}

int main() 
{
    test_binary_to_decimal();
    test_decimal_to_binary();
    test_hex_to_decimal();
    test_decimal_to_hex();
    test_int_to_string();
    test_string_to_int();
    test_string_to_double();

    printf("All conversion tests passed successfully!\n");

    return 0;
}
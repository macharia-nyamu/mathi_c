#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/conversion.h"

void test_binary_to_decimal() {
    printf("Testing binary_to_decimal...\n");
    const char *bins[] = {"101", "0", "1111", "102"};
    for(int i = 0; i < 4; i++) {
        int val = binary_to_decimal(bins[i]);
        printf("binary_to_decimal('%s') = %d\n", bins[i], val);
    }
    assert(binary_to_decimal("101") == 5);
    assert(binary_to_decimal("0") == 0);
    assert(binary_to_decimal("1111") == 15);
    assert(binary_to_decimal("102") == -1); // invalid binary
}

void test_decimal_to_binary() {
    printf("Testing decimal_to_binary...\n");
    int nums[] = {5, 0, 15};
    char buffer[32];
    for(int i = 0; i < 3; i++) {
        decimal_to_binary(nums[i], buffer);
        printf("decimal_to_binary(%d) = '%s'\n", nums[i], buffer);
    }
    assert(strcmp(buffer, "1111") == 0); // last value
}

void test_hex_to_decimal() {
    printf("Testing hex_to_decimal...\n");
    const char *hexes[] = {"1A", "0", "FF", "G1"};
    for(int i = 0; i < 4; i++) {
        int val = hex_to_decimal(hexes[i]);
        printf("hex_to_decimal('%s') = %d\n", hexes[i], val);
    }
    assert(hex_to_decimal("1A") == 26);
    assert(hex_to_decimal("0") == 0);
    assert(hex_to_decimal("FF") == 255);
    assert(hex_to_decimal("G1") == -1); // invalid hex
}

void test_decimal_to_hex() {
    printf("Testing decimal_to_hex...\n");
    int nums[] = {26, 0, 255};
    char buffer[32];
    for(int i = 0; i < 3; i++) {
        decimal_to_hex(nums[i], buffer);
        printf("decimal_to_hex(%d) = '%s'\n", nums[i], buffer);
    }
    assert(strcmp(buffer, "FF") == 0); // last value
}

void test_int_to_string() {
    printf("Testing int_to_string...\n");
    int nums[] = {123, 0, -456};
    char buffer[32];
    for(int i = 0; i < 3; i++) {
        int_to_string(nums[i], buffer);
        printf("int_to_string(%d) = '%s'\n", nums[i], buffer);
    }
    assert(strcmp(buffer, "-456") == 0); // last value
}

void test_string_to_int() {
    printf("Testing string_to_int...\n");
    const char *strs[] = {"123", "0", "-456", "abc"};
    for(int i = 0; i < 4; i++) {
        int val = string_to_int(strs[i]);
        printf("string_to_int('%s') = %d\n", strs[i], val);
    }
    assert(string_to_int("123") == 123);
    assert(string_to_int("0") == 0);
    assert(string_to_int("-456") == -456);
    assert(string_to_int("abc") == 0);
}

void test_string_to_double() {
    printf("Testing string_to_double...\n");
    const char *strs[] = {"123.45", "0.0", "-456.78", "abc"};
    for(int i = 0; i < 4; i++) {
        double val = string_to_double(strs[i]);
        printf("string_to_double('%s') = %.2f\n", strs[i], val);
    }
    assert(string_to_double("123.45") == 123.45);
    assert(string_to_double("0.0") == 0.0);
    assert(string_to_double("-456.78") == -456.78);
    assert(string_to_double("abc") == 0.0);
}

int main() {
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
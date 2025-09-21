/*
* Mathi C Library - sys_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mathi/sys.h"

static void print_env(const char *label, const char *var_name)
{
    char *val = mathi_get_env(var_name);
    printf("%s: %s=\"%s\"\n", label, var_name, val ? val : "NULL");
}

void test_sys_env()
{
    const char *var_name = "MATHI_TEST_VAR";

    printf("Starting system environment variable tests...\n\n");

    // Ensure variable is not set
    printf("Clearing previous value (if any)...\n");
    mathi_set_env(var_name, "", 1); // clear previous value
    print_env("After clear", var_name);
    char *val = mathi_get_env(var_name);
    assert(val != NULL); // getenv returns "" now
    assert(strlen(val) == 0);
    printf("Clear test passed!\n\n");

    // Set a variable
    printf("Setting variable to '123'...\n");
    int res = mathi_set_env(var_name, "123", 1); // overwrite
    assert(res == 1);
    print_env("After set", var_name);
    val = mathi_get_env(var_name);
    assert(val != NULL && strcmp(val, "123") == 0);
    printf("Set test passed!\n\n");

    // Test overwrite protection
    printf("Attempting to set variable to '456' with overwrite=0...\n");
    res = mathi_set_env(var_name, "456", 0); // do not overwrite
    assert(res == 1); // still returns success
    print_env("After attempted overwrite", var_name);
    val = mathi_get_env(var_name);
    assert(strcmp(val, "123") == 0); // value unchanged
    printf("Overwrite protection test passed!\n\n");

    // Test overwrite allowed
    printf("Setting variable to '456' with overwrite=1...\n");
    res = mathi_set_env(var_name, "456", 1); // overwrite
    assert(res == 1);
    print_env("After overwrite", var_name);
    val = mathi_get_env(var_name);
    assert(strcmp(val, "456") == 0);
    printf("Overwrite allowed test passed!\n\n");

    printf("All sys environment variable tests passed!\n");
}

int main()
{
    test_sys_env();
    return 0;
}
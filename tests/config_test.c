#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/config.h"

void test_config_load() 
{
    printf("Testing config_load...\n");

    int res = mathi_conf_load("dummy_path.cfg");
    printf("config_load('dummy_path.cfg') result = %d\n", res);
    assert(res == 0);

    printf("\n");
}

void test_config_get_string() 
{
    printf("Testing config_get_string...\n");

    const char *val = mathi_conf_get_string("key1");
    printf("config_get_string('key1') = '%s'\n", val ? val : "NULL");

    assert(val != NULL);
    assert(strcmp(val, "") == 0);

    printf("\n");
}

void test_config_get_int() 
{
    printf("Testing config_get_int...\n");

    int value = 42;
    int res = mathi_conf_get_int("key2", &value);
    printf("config_get_int('key2') result = %d, value = %d\n", res, value);
    assert(res == 0);
    assert(value == 0);

    res = mathi_conf_get_int("key2", NULL);
    printf("config_get_int('key2', NULL) result = %d\n", res);
    assert(res == 0);

    printf("\n");
}

void test_config_set_string() 
{
    printf("Testing config_set_string...\n");

    int res = mathi_conf_set_string("key3", "value");
    printf("config_set_string('key3', 'value') result = %d\n", res);
    assert(res == 0);

    printf("\n");
}

void test_config_save() 
{
    printf("Testing config_save...\n");

    int res = mathi_conf_save("dummy_path.cfg");
    printf("config_save('dummy_path.cfg') result = %d\n", res);
    assert(res == 0);

    printf("\n");
}

int main() 
{
    test_config_load();
    test_config_get_string();
    test_config_get_int();
    test_config_set_string();
    test_config_save();

    printf("All config tests passed successfully!\n");

    return 0;
}
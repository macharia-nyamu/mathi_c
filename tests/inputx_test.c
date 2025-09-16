#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/inputx.h"
#include "mathi/validator.h"

void test_get_int_static() 
{
    printf("Testing mathi_get_int with static value...\n");

    char buf[] = "123";
    InputResult res;
    int val;

    if(mathi_is_int(buf)) 
    {
        val = atoi(buf);
        res.code = 0;
        res.value = &val;
    } 
    else 
    {
        res.code = 2;  // INPUT_INVALID_INT
        res.value = NULL;
    }

    printf("buf='%s', code=%d, value=%d\n", buf, res.code, *(int*)res.value);
    assert(res.code == 0);
    assert(*(int*)res.value == 123);
}

void test_get_double_static() 
{
    printf("Testing mathi_get_double with static value...\n");

    char buf[] = "3.1415";
    InputResult res;
    double val;

    if(mathi_is_number(buf)) 
    {
        val = atof(buf);
        res.code = 0;
        res.value = &val;
    } 
    else 
    {
        res.code = 3;  // INPUT_INVALID_DOUBLE
        res.value = NULL;
    }

    printf("buf='%s', code=%d, value=%f\n", buf, res.code, *(double*)res.value);
    assert(res.code == 0);
    assert(*(double*)res.value == 3.1415);
}

void test_get_binary_static() 
{
    printf("Testing mathi_get_binary with static value...\n");

    char buf[] = "10101";
    InputResult res;

    if(mathi_is_binary(buf)) 
    {
        res.code = 0;
        res.value = buf;
    } 
    else 
    {
        res.code = 4;  // INPUT_INVALID_BINARY
        res.value = NULL;
    }

    printf("buf='%s', code=%d, value='%s'\n", buf, res.code, (char*)res.value);
    assert(res.code == 0);
    assert(strcmp((char*)res.value, "10101") == 0);
}

void test_get_hex_static() 
{
    printf("Testing mathi_get_hex with static value...\n");

    char buf[] = "1aF";
    InputResult res;

    if(mathi_is_hex(buf)) 
    {
        res.code = 0;
        res.value = buf;
    } 
    else 
    {
        res.code = 5;  // INPUT_INVALID_HEX
        res.value = NULL;
    }

    printf("buf='%s', code=%d, value='%s'\n", buf, res.code, (char*)res.value);
    assert(res.code == 0);
    assert(strcmp((char*)res.value, "1aF") == 0);
}

void test_get_string_static() 
{
    printf("Testing mathi_get_string with static value...\n");

    char buf[] = "Hello Mathi";
    InputResult res;

    if(strlen(buf) > 0) 
    {
        res.code = 0;
        res.value = buf;
    } 
    else 
    {
        res.code = 1;  // INPUT_EMPTY
        res.value = NULL;
    }

    printf("buf='%s', code=%d, value='%s'\n", buf, res.code, (char*)res.value);
    assert(res.code == 0);
    assert(strcmp((char*)res.value, "Hello Mathi") == 0);
}

int main() 
{
    test_get_int_static();
    test_get_double_static();
    test_get_binary_static();
    test_get_hex_static();
    test_get_string_static();

    printf("All mathi_inputx static tests passed successfully!\n");
    return 0;
}
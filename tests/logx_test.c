#include <stdio.h>
#include <assert.h>
#include "mathi/logx.h"

void test_log_info() 
{
    printf("Testing log_info...\n");
    int code = mathi_log_info("This is an info message: %d", 123);
    printf("log_info returned code = %d\n", code);
    assert(code == 0);
}

void test_log_warn() 
{
    printf("Testing log_warn...\n");
    int code = mathi_log_warn("This is a warning message: %s", "be careful");
    printf("log_warn returned code = %d\n", code);
    assert(code == 0);
}

void test_log_error() 
{
    printf("Testing log_error...\n");
    int code = mathi_log_error("This is an error message");
    printf("log_error returned code = %d\n", code);
    assert(code == 0);
}

void test_set_log_file_null() 
{
    printf("Testing set_log_file with NULL path...\n");
    int code = mathi_set_log_file(NULL);
    printf("set_log_file(NULL) returned code = %d\n", code);
    assert(code == 2); // expected failure code
}

int main() 
{
    test_log_info();
    test_log_warn();
    test_log_error();
    test_set_log_file_null();

    printf("All logx static tests passed successfully!\n");
    return 0;
}
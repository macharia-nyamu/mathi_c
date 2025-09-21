#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/filex.h"

void test_file_write_and_exists() 
{
    printf("Testing file_write and file_exists...\n");

    const char *path = "test_file.txt";
    int res = mathi_file_write(path, "Hello Mathi!", strlen("Hello Mathi!"));
    printf("file_write('%s') result = %d\n", path, res);
    assert(res);

    int exists = mathi_file_exists(path);
    printf("file_exists('%s') = %d\n", path, exists);
    assert(exists);
}

void test_file_size_and_read() 
{
    printf("Testing file_size and file_read...\n");

    const char *path = "test_file.txt";
    char buffer[1024] = {0};
    long size = mathi_file_size(path);
    printf("file_size('%s') = %ld\n", path, size);
    assert(size > 0);

    int read_res = mathi_file_read(path, buffer, sizeof(buffer));
    printf("file_read('%s') result = %d, content = '%.*s'\n", path, read_res, (int)size, buffer);
    assert(read_res);
    assert(strncmp(buffer, "Hello Mathi!", size) == 0);
}

void test_file_append() 
{
    printf("Testing file_append...\n");

    const char *path = "test_file.txt";
    int res = mathi_file_append(path, " Appended");
    printf("file_append('%s') result = %d\n", path, res);
    assert(res);

    char buffer[1024] = {0};
    mathi_file_read(path, buffer, sizeof(buffer));
    printf("file content after append = '%s'\n", buffer);
    assert(strstr(buffer, "Appended") != NULL);
}

void test_file_copy() 
{
    printf("Testing file_copy...\n");

    const char *src = "test_file.txt";
    const char *dest = "test_file_copy.txt";
    int res = mathi_file_copy(src, dest);
    printf("file_copy('%s','%s') result = %d\n", src, dest, res);
    assert(res);

    int exists = mathi_file_exists(dest);
    printf("file_exists('%s') = %d\n", dest, exists);
    assert(exists);
}

void test_file_delete() 
{
    printf("Testing file_delete...\n");

    const char *path1 = "test_file.txt";
    const char *path2 = "test_file_copy.txt";

    int res1 = mathi_file_delete(path1);
    printf("file_delete('%s') result = %d\n", path1, res1);
    assert(res1);

    int res2 = mathi_file_delete(path2);
    printf("file_delete('%s') result = %d\n", path2, res2);
    assert(res2);

    int exists1 = mathi_file_exists(path1);
    int exists2 = mathi_file_exists(path2);
    printf("file_exists('%s') = %d, file_exists('%s') = %d\n", path1, exists1, path2, exists2);
    assert(!exists1);
    assert(!exists2);
}

int main() 
{
    test_file_write_and_exists();
    test_file_size_and_read();
    test_file_append();
    test_file_copy();
    test_file_delete();

    printf("All filex tests passed successfully!\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/crypto.h"

void test_sha256_hash() 
{
    printf("\nTesting sha256_hash...\n");

    char output[64];
    int res;

    res = mathi_hash_sha256("test", output);
    printf("sha256_hash('test') result = %d, output = '%s'\n", res, output);
    assert(res == 0);
    assert(strcmp(output, "SHA256_PLACEHOLDER") == 0);

    res = mathi_hash_sha256(NULL, output);
    printf("sha256_hash(NULL) result = %d\n", res);
    assert(res == 2);

    res = mathi_hash_sha256("test", NULL);
    printf("sha256_hash('test', NULL) result = %d\n", res);
    assert(res == 2);

    printf("\n");
}

void test_md5_hash() 
{
    printf("\nTesting md5_hash...\n");

    char output[64];
    int res;

    res = mathi_hash_md5("hello", output);
    printf("md5_hash('hello') result = %d, output = '%s'\n", res, output);
    assert(res == 0);
    assert(strcmp(output, "MD5_PLACEHOLDER") == 0);

    res = mathi_hash_md5(NULL, output);
    printf("md5_hash(NULL) result = %d\n", res);
    assert(res == 2);

    res = mathi_hash_md5("hello", NULL);
    printf("md5_hash('hello', NULL) result = %d\n", res);
    assert(res == 2);

    printf("\n");
}

void test_xor_cipher() 
{
    printf("\nTesting xor_cipher...\n");

    char data[] = "ABC";
    printf("original data = '%s'\n", data);

    int res = mathi_xor_cipher(data, 0xFF);
    printf("after first xor_cipher result = %d, data = '%s'\n", res, data);
    assert(res == 0);

    res = mathi_xor_cipher(data, 0xFF);
    printf("after second xor_cipher result = %d, data = '%s'\n", res, data);
    assert(res == 0);
    assert(strcmp(data, "ABC") == 0);

    res = mathi_xor_cipher(NULL, 0xFF);
    printf("xor_cipher(NULL) result = %d\n", res);
    assert(res == 2);

    printf("\n");
}

void test_simple_checksum() 
{
    printf("\nTesting simple_checksum...\n");

    unsigned char data[] = {1, 2, 3, 4, 5};
    printf("data = [1,2,3,4,5]\n");

    int sum = mathi_checksum(data, 5);
    printf("simple_checksum(data,5) = %d\n", sum);
    assert(sum == ((1+2+3+4+5)&0xFF));

    sum = mathi_checksum(NULL, 5);
    printf("simple_checksum(NULL,5) = %d\n", sum);
    assert(sum == 2);

    printf("\n");
}

int main() 
{
    test_sha256_hash();
    test_md5_hash();
    test_xor_cipher();
    test_simple_checksum();

    printf("All crypto tests passed successfully!\n");

    return 0;
}
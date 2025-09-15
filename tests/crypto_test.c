#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/crypto.h"

void test_sha256_hash() {
    printf("Testing sha256_hash...\n");
    char output[64];
    int res;

    res = sha256_hash("test", output);
    printf("sha256_hash('test') result = %d, output = '%s'\n", res, output);
    assert(res == 0);
    assert(strcmp(output, "SHA256_PLACEHOLDER") == 0);

    res = sha256_hash(NULL, output);
    printf("sha256_hash(NULL) result = %d\n", res);
    assert(res == 2);

    res = sha256_hash("test", NULL);
    printf("sha256_hash('test', NULL) result = %d\n", res);
    assert(res == 2);
}

void test_md5_hash() {
    printf("Testing md5_hash...\n");
    char output[64];
    int res;

    res = md5_hash("hello", output);
    printf("md5_hash('hello') result = %d, output = '%s'\n", res, output);
    assert(res == 0);
    assert(strcmp(output, "MD5_PLACEHOLDER") == 0);

    res = md5_hash(NULL, output);
    printf("md5_hash(NULL) result = %d\n", res);
    assert(res == 2);

    res = md5_hash("hello", NULL);
    printf("md5_hash('hello', NULL) result = %d\n", res);
    assert(res == 2);
}

void test_xor_cipher() {
    printf("Testing xor_cipher...\n");
    char data[] = "ABC";
    printf("original data = '%s'\n", data);

    int res = xor_cipher(data, 0xFF);
    printf("after first xor_cipher result = %d, data = '%s'\n", res, data);
    assert(res == 0);

    res = xor_cipher(data, 0xFF);
    printf("after second xor_cipher result = %d, data = '%s'\n", res, data);
    assert(res == 0);
    assert(strcmp(data, "ABC") == 0);

    res = xor_cipher(NULL, 0xFF);
    printf("xor_cipher(NULL) result = %d\n", res);
    assert(res == 2);
}

void test_simple_checksum() {
    printf("Testing simple_checksum...\n");
    unsigned char data[] = {1, 2, 3, 4, 5};
    printf("data = [1,2,3,4,5]\n");

    int sum = simple_checksum(data, 5);
    printf("simple_checksum(data,5) = %d\n", sum);
    assert(sum == ((1+2+3+4+5)&0xFF));

    sum = simple_checksum(NULL, 5);
    printf("simple_checksum(NULL,5) = %d\n", sum);
    assert(sum == 2); // should return 2 for NULL
}

int main() {
    test_sha256_hash();
    test_md5_hash();
    test_xor_cipher();
    test_simple_checksum();

    printf("All crypto tests passed successfully!\n");
    return 0;
}
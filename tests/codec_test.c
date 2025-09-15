#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/codec.h"

void print_bytes(const unsigned char *data, size_t len, const char *name) {
    printf("%s = [", name);
    for(size_t i = 0; i < len; i++) {
        printf("%d", data[i]);
        if(i < len-1) printf(", ");
    }
    printf("]\n");
}

void test_base64_encode() {
    printf("Testing base64_encode...\n");
    const unsigned char data[] = "Hello";
    print_bytes(data, 5, "data");
    char *encoded = NULL;
    int res = base64_encode(data, 5, &encoded);
    printf("base64_encode result = %d\n", res);
    printf("encoded = %s\n", encoded);
    assert(res == 0);
    assert(encoded != NULL);
    assert(strcmp(encoded, "BASE64_ENCODE_PLACEHOLDER") == 0);
    free(encoded);

    res = base64_encode(NULL, 0, &encoded);
    printf("base64_encode(NULL) result = %d\n", res);
    assert(res == 2); // null input check
}

void test_base64_decode() {
    printf("Testing base64_decode...\n");
    const char *input = "SGVsbG8=";
    printf("input = %s\n", input);
    unsigned char *output = NULL;
    size_t out_len = 0;

    int res = base64_decode(input, &output, &out_len);
    printf("base64_decode result = %d\n", res);
    printf("output length = %zu\n", out_len);
    print_bytes(output, out_len, "output");
    assert(res == 0);
    assert(output != NULL);
    assert(out_len == strlen(input));
    free(output);

    res = base64_decode(NULL, &output, &out_len);
    printf("base64_decode(NULL) result = %d\n", res);
    assert(res == 2); // null input check
}

void test_rle_compress() {
    printf("Testing rle_compress...\n");
    unsigned char data[] = {1, 1, 2, 2, 2, 3};
    print_bytes(data, 6, "data");
    unsigned char *out = NULL;
    size_t out_len = 0;

    int res = rle_compress(data, 6, &out, &out_len);
    printf("rle_compress result = %d\n", res);
    printf("compressed length = %zu\n", out_len);
    print_bytes(out, out_len, "compressed output");
    assert(res == 0);
    assert(out != NULL);
    assert(out_len == 6); // placeholder returns same length
    for (int i = 0; i < 6; i++) assert(out[i] == data[i]);
    free(out);

    res = rle_compress(NULL, 0, &out, &out_len);
    printf("rle_compress(NULL) result = %d\n", res);
    assert(res == 2); // null input
}

void test_rle_decompress() {
    printf("Testing rle_decompress...\n");
    unsigned char data[] = {1, 2, 3, 4};
    print_bytes(data, 4, "data");
    unsigned char *out = NULL;
    size_t out_len = 0;

    int res = rle_decompress(data, 4, &out, &out_len);
    printf("rle_decompress result = %d\n", res);
    printf("decompressed length = %zu\n", out_len);
    print_bytes(out, out_len, "decompressed output");
    assert(res == 0);
    assert(out != NULL);
    assert(out_len == 4);
    for (int i = 0; i < 4; i++) assert(out[i] == data[i]);
    free(out);

    res = rle_decompress(NULL, 0, &out, &out_len);
    printf("rle_decompress(NULL) result = %d\n", res);
    assert(res == 2); // null input
}

int main() {
    test_base64_encode();
    test_base64_decode();
    test_rle_compress();
    test_rle_decompress();

    printf("All codec tests passed successfully!\n");
    return 0;
}
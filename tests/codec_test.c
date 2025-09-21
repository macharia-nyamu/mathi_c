/*
* Mathi C Library - Codec Test
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/codec.h"
#include "mathi/print.h"

void test_base64_encode_decode(const char *text) 
{
    printf("\nTesting Base64 encode/decode \n");

    char *encoded = NULL;
    unsigned char *decoded = NULL;
    size_t decoded_len = 0;
    int status;

    printf("Original text: \"%s\"\n", text);

    // Encode
    status = mathi_enc_base64((const unsigned char*)text, strlen(text), &encoded);
    printf("Encoded string: \"%s\" (status = %d)\n", encoded, status);
    assert(status == 0);
    assert(encoded != NULL);

    // Decode
    status = mathi_dec_base64(encoded, &decoded, &decoded_len);
    printf("Decoded length = %zu (status = %d)\n", decoded_len, status);
    mathi_prnt_bytes(decoded, decoded_len, "Decoded bytes");

    // Print decoded text as string
    char *decoded_str = malloc(decoded_len + 1);
    memcpy(decoded_str, decoded, decoded_len);
    decoded_str[decoded_len] = '\0';
    printf("Decoded text: \"%s\"\n", decoded_str);

    // Check if decoded text equals original
    assert(status == 0);
    assert(decoded_len == strlen(text));
    assert(strcmp(decoded_str, text) == 0);

    free(encoded);
    free(decoded);
    free(decoded_str);

    printf("\n");
}

void test_rle_compress_decompress() 
{
    printf("\nTesting RLE compress/decompress \n");

    unsigned char data[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4};
    unsigned char *compressed = NULL;
    unsigned char *decompressed = NULL;
    size_t out_len = 0;
    int status;

    printf("Original data: ");
    mathi_prnt_bytes(data, sizeof(data), "Data");

    // Compress
    status = mathi_rle_compress(data, sizeof(data), &compressed, &out_len);
    printf("Compressed length = %zu (status = %d)\n", out_len, status);
    mathi_prnt_bytes(compressed, out_len, "Compressed");
    assert(status == 0);

    // Decompress
    status = mathi_rle_decompress(compressed, out_len, &decompressed, &out_len);
    printf("Decompressed length = %zu (status = %d)\n", out_len, status);
    mathi_prnt_bytes(decompressed, out_len, "Decompressed");
    assert(status == 0);
    assert(memcmp(decompressed, data, sizeof(data)) == 0);

    free(compressed);
    free(decompressed);

    printf("\n");
}

int main() 
{
    const char *text = "Mathi C by Macharia Nyamū";

    test_base64_encode_decode(text);
    test_rle_compress_decompress();

    printf("All codec tests passed successfully!\n");

    return 0;
}
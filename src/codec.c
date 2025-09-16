/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/codec.h"
#include <stdlib.h>
#include <string.h>

int base64_encode(const unsigned char *data, size_t len, char **output) {
    if (!data || !output) return 2;
    *output = malloc(len * 2 + 1);
    if (!*output) return 1;
    strcpy(*output, "BASE64_ENCODE_PLACEHOLDER");
    return 0;
}

int base64_decode(const char *input, unsigned char **output, size_t *out_len) {
    if (!input || !output || !out_len) return 2;
    *out_len = strlen(input);
    *output = malloc(*out_len);
    if (!*output) return 1;
    memset(*output, 0, *out_len);
    return 0;
}

int rle_compress(const unsigned char *data, size_t len, unsigned char **out, size_t *out_len) {
    if (!data || !out || !out_len) return 2;
    *out = malloc(len * 2);
    if (!*out) return 1;
    *out_len = len;
    memcpy(*out, data, len);
    return 0;
}

int rle_decompress(const unsigned char *data, size_t len, unsigned char **out, size_t *out_len) {
    if (!data || !out || !out_len) return 2;
    *out = malloc(len);
    if (!*out) return 1;
    *out_len = len;
    memcpy(*out, data, len);
    return 0;
}

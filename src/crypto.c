/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/crypto.h"
#include <string.h>
#include <stdlib.h>

int sha256_hash(const char *input, char *output) {
    if (!input || !output) return 2;
    /* Placeholder: actual SHA256 implementation needed */
    strcpy(output, "SHA256_PLACEHOLDER");
    return 0;
}

int md5_hash(const char *input, char *output) {
    if (!input || !output) return 2;
    strcpy(output, "MD5_PLACEHOLDER");
    return 0;
}

int xor_cipher(char *data, char key) {
    if (!data) return 2;
    for (size_t i = 0; data[i]; i++) data[i] ^= key;
    return 0;
}

int simple_checksum(const unsigned char *data, size_t len) {
    if (!data) return 2;
    unsigned int sum = 0;
    for (size_t i = 0; i < len; i++) sum += data[i];
    return sum & 0xFF;
}
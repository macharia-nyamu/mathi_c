/*
 * Mathi C Library - Crypto Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Functions for hashing, XOR cipher, and checksum operations.
 */

#include "mathi/crypto.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Compute SHA-256 hash of a string (placeholder).
 * @param input Input string
 * @param output Buffer to store hash output
 * @return 0 on success, 2 on invalid input
 */
int mathi_hash_sha256(const char *input, char *output)
{
    if (!input || !output) 
        return 2;

    strcpy(output, "SHA256_PLACEHOLDER");
    return 0;
}

/**
 * @brief Compute MD5 hash of a string (placeholder).
 * @param input Input string
 * @param output Buffer to store hash output
 * @return 0 on success, 2 on invalid input
 */
int mathi_hash_md5(const char *input, char *output)
{
    if (!input || !output) 
        return 2;

    strcpy(output, "MD5_PLACEHOLDER");
    return 0;
}

/**
 * @brief Apply XOR cipher to a string with a single-byte key.
 * @param data Input string (modified in-place)
 * @param key Single-byte key
 * @return 0 on success, 2 on invalid input
 */
int mathi_xor_cipher(char *data, char key)
{
    if (!data) 
        return 2;

    for (size_t i = 0; data[i]; i++) 
        data[i] ^= key;

    return 0;
}

/**
 * @brief Compute simple checksum of a byte array (mod 256).
 * @param data Input byte array
 * @param len Length of array
 * @return Checksum value (0–255), or 2 if input is NULL
 */
int mathi_checksum(const unsigned char *data, size_t len)
{
    if (!data) 
        return 2;

    unsigned int sum = 0;
    for (size_t i = 0; i < len; i++) 
        sum += data[i];

    return sum & 0xFF;
}
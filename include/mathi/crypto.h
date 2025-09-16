/*
* Mathi C Library - Crypto Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#ifndef MATHI_CRYPTO_H
#define MATHI_CRYPTO_H

#include <stddef.h>  // for size_t

/**
 * @file mathi/crypto.h
 * @brief Basic cryptography utilities: hashing, XOR cipher, checksums.
 */

/**
 * @brief Compute SHA-256 hash (placeholder implementation).
 * @param input Null-terminated input string.
 * @param output Buffer to store resulting hash string (must be preallocated).
 * @return 0 on success, 2 on invalid input.
 */
int mathi_hash_sha256(const char *input, char *output);

/**
 * @brief Compute MD5 hash (placeholder implementation).
 * @param input Null-terminated input string.
 * @param output Buffer to store resulting hash string (must be preallocated).
 * @return 0 on success, 2 on invalid input.
 */
int mathi_hash_md5(const char *input, char *output);

/**
 * @brief XOR encrypt/decrypt a string with a single-byte key.
 * @param data Null-terminated string to process (modified in place).
 * @param key XOR key.
 * @return 0 on success, 2 on invalid input.
 */
int mathi_xor_cipher(char *data, char key);

/**
 * @brief Compute a simple checksum (sum of bytes modulo 256).
 * @param data Input byte array.
 * @param len Length of the array.
 * @return Checksum (0–255), or 2 if input is NULL.
 */
int mathi_checksum(const unsigned char *data, size_t len);

#endif // MATHI_CRYPTO_H
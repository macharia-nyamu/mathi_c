/**
 * Mathi C Library - Cryptography Utilities
 * 
 * This header provides basic cryptography and hashing functions, including
 * SHA-256, MD5, XOR cipher, and simple checksums.
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - MEMORY_ERROR
 * 2 - INVALID_INPUT
 * 3 - UNKNOWN_ERROR
 * 
 * @file crypto.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_CRYPTO_H
#define MATHI_CRYPTO_H

#include <stddef.h>

/**
 * @brief Compute the SHA-256 hash of a string.
 * @param input Null-terminated input string.
 * @param output Buffer to store the resulting hash (must be preallocated).
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int sha256_hash(const char *input, char *output);

/**
 * @brief Compute the MD5 hash of a string.
 * @param input Null-terminated input string.
 * @param output Buffer to store the resulting hash (must be preallocated).
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int md5_hash(const char *input, char *output);

/**
 * @brief Apply a simple XOR cipher to a string in-place.
 * @param data String to encrypt/decrypt.
 * @param key Single-character XOR key.
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int xor_cipher(char *data, char key);

/**
 * @brief Compute a simple checksum of data.
 * @param data Input byte array.
 * @param len Length of input data.
 * @return Checksum as an integer.
 */
int simple_checksum(const unsigned char *data, size_t len);

#endif
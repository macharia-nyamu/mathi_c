/**
 * Mathi C Library - Codec Utilities
 * 
 * This header provides encoding, decoding, and compression functions,
 * including Base64 and Run-Length Encoding (RLE).
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - MEMORY_ERROR
 * 2 - INVALID_INPUT
 * 3 - UNKNOWN_ERROR
 * 
 * @file codec.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_CODEC_H
#define MATHI_CODEC_H

#include <stddef.h>

/**
 * @brief Encode data to Base64 format.
 * @param data Input byte array.
 * @param len Length of input data.
 * @param output Pointer to store allocated output string (must be freed by caller).
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int base64_encode(const unsigned char *data, size_t len, char **output);

/**
 * @brief Decode a Base64-encoded string.
 * @param input Input Base64 string.
 * @param output Pointer to store allocated output bytes (must be freed by caller).
 * @param out_len Pointer to store length of output data.
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int base64_decode(const char *input, unsigned char **output, size_t *out_len);

/**
 * @brief Compress data using Run-Length Encoding (RLE).
 * @param data Input byte array.
 * @param len Length of input data.
 * @param out Pointer to store allocated compressed output (must be freed by caller).
 * @param out_len Pointer to store length of compressed data.
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int rle_compress(const unsigned char *data, size_t len, unsigned char **out, size_t *out_len);

/**
 * @brief Decompress RLE-compressed data.
 * @param data Input compressed byte array.
 * @param len Length of input data.
 * @param out Pointer to store allocated decompressed output (must be freed by caller).
 * @param out_len Pointer to store length of decompressed data.
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = UNKNOWN_ERROR).
 */
int rle_decompress(const unsigned char *data, size_t len, unsigned char **out, size_t *out_len);

#endif
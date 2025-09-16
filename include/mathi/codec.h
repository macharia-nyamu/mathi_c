/*
* Mathi C Library - Codec Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#ifndef MATHI_CODEC_H
#define MATHI_CODEC_H

#include <stddef.h>  // for size_t
#include <stdlib.h>  // for malloc/free
#include "stringx.h" // for mathi_string_length

/**
 * @file mathi/codec.h
 * @brief Encoding, decoding, and compression utilities (Base64, RLE).
 */

/**
 * @brief Encode data to Base64.
 * @param data Input byte array.
 * @param len Length of input data.
 * @param out Pointer to output string (allocated inside function).
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_enc_base64(const unsigned char *restrict data, size_t len, char **out);

/**
 * @brief Decode Base64 string to bytes.
 * @param in Input Base64 string.
 * @param out Pointer to output byte array (allocated inside function).
 * @param out_len Pointer to output length.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_dec_base64(const char *restrict in, unsigned char **out, size_t *out_len);

/**
 * @brief Compress data using Run-Length Encoding (RLE).
 * @param in Input byte array.
 * @param len Length of input data.
 * @param out Pointer to output byte array (allocated inside function).
 * @param out_len Pointer to output length.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_rle_compress(const unsigned char *restrict in, size_t len, unsigned char **out, size_t *out_len);

/**
 * @brief Decompress RLE-compressed data.
 * @param in Input RLE-compressed byte array.
 * @param len Length of input data.
 * @param out Pointer to output byte array (allocated inside function).
 * @param out_len Pointer to output length.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_rle_decompress(const unsigned char *restrict in, size_t len, unsigned char **out, size_t *out_len);

#endif // MATHI_CODEC_H
/*
 * Mathi C Library - Codec Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Functions for Base64 encoding/decoding and RLE compression/decompression.
 */

#include <stdlib.h>
#include "mathi/codec.h"
#include "mathi/stringx.h"

static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int mathi_base64_index(char c)
{
    for (int i = 0; i < 64; i++)
        if (base64_chars[i] == c)
            return i;

    return -1;
}

/**
 * @brief Encode data to Base64.
 * @param data Input bytes
 * @param len Length of input
 * @param out Pointer to output string (allocated inside)
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_enc_base64(const unsigned char *data, size_t len, char **out)
{
    if (!data || !out) 
        return 2;

    size_t encoded_len = ((len + 2) / 3) * 4;
    *out = malloc(encoded_len + 1);
    if (!*out) 
        return 1;

    char *p = *out;
    for (size_t i = 0; i < len; i += 3)
    {
        unsigned int triple = data[i] << 16;
        if (i + 1 < len) triple |= data[i + 1] << 8;
        if (i + 2 < len) triple |= data[i + 2];

        *p++ = base64_chars[(triple >> 18) & 0x3F];
        *p++ = base64_chars[(triple >> 12) & 0x3F];
        *p++ = (i + 1 < len) ? base64_chars[(triple >> 6) & 0x3F] : '=';
        *p++ = (i + 2 < len) ? base64_chars[triple & 0x3F] : '=';
    }

    *p = '\0';
    return 0;
}

/**
 * @brief Decode a Base64 string.
 * @param in Input Base64 string
 * @param out Pointer to output bytes (allocated inside)
 * @param out_len Pointer to store output length
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_dec_base64(const char *in, unsigned char **out, size_t *out_len)
{
    if (!in || !out || !out_len) 
        return 2;

    size_t len = mathi_string_length((char *)in);
    if (len % 4 != 0) 
        return 2;

    size_t alloc_len = (len / 4) * 3;
    if (len >= 2 && in[len - 1] == '=') alloc_len--;
    if (len >= 1 && in[len - 2] == '=') alloc_len--;

    *out = malloc(alloc_len);
    if (!*out) 
        return 1;

    size_t j = 0;
    for (size_t i = 0; i < len; i += 4)
    {
        int sextet_a = in[i] == '=' ? 0 : mathi_base64_index(in[i]);
        int sextet_b = in[i + 1] == '=' ? 0 : mathi_base64_index(in[i + 1]);
        int sextet_c = in[i + 2] == '=' ? 0 : mathi_base64_index(in[i + 2]);
        int sextet_d = in[i + 3] == '=' ? 0 : mathi_base64_index(in[i + 3]);

        unsigned int triple = (sextet_a << 18) | (sextet_b << 12) | (sextet_c << 6) | sextet_d;

        if (j < alloc_len) (*out)[j++] = (triple >> 16) & 0xFF;
        if (j < alloc_len) (*out)[j++] = (triple >> 8) & 0xFF;
        if (j < alloc_len) (*out)[j++] = triple & 0xFF;
    }

    *out_len = alloc_len;
    return 0;
}

/**
 * @brief Compress data using Run-Length Encoding (RLE).
 * @param in Input bytes
 * @param len Length of input
 * @param out Pointer to output bytes (allocated inside)
 * @param out_len Pointer to store output length
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_rle_compress(const unsigned char *in, size_t len, unsigned char **out, size_t *out_len)
{
    if (!in || !out || !out_len) 
        return 2;

    if (len == 0) 
    { 
        *out = NULL; 
        *out_len = 0; 
        return 0; 
    }

    *out = malloc(len * 2); // worst-case
    if (!*out) 
        return 1;

    size_t j = 0;
    for (size_t i = 0; i < len;)
    {
        unsigned char val = in[i];
        size_t count = 1;
        while (i + count < len && in[i + count] == val && count < 255) 
            count++;

        (*out)[j++] = val;
        (*out)[j++] = (unsigned char)count;
        i += count;
    }

    *out_len = j;
    return 0;
}

/**
 * @brief Decompress RLE-compressed data.
 * @param in Input bytes (RLE format)
 * @param len Length of input
 * @param out Pointer to output bytes (allocated inside)
 * @param out_len Pointer to store output length
 * @return 0 on success, 1 on memory error, 2 on invalid input
 */
int mathi_rle_decompress(const unsigned char *in, size_t len, unsigned char **out, size_t *out_len)
{
    if (!in || !out || !out_len) 
        return 2;

    if (len == 0) 
    { 
        *out = NULL; 
        *out_len = 0; 
        return 0; 
    }

    // Compute decompressed length
    size_t total = 0;
    for (size_t i = 0; i + 1 < len; i += 2) 
        total += in[i + 1];

    *out = malloc(total);
    if (!*out) 
        return 1;

    size_t j = 0;
    for (size_t i = 0; i + 1 < len; i += 2)
    {
        unsigned char val = in[i];
        unsigned char count = in[i + 1];
        for (unsigned char k = 0; k < count; k++) 
            (*out)[j++] = val;
    }

    *out_len = total;
    return 0;
}
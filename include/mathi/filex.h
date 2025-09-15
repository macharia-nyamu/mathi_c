/**
 * Mathi C Library - File Utilities
 * 
 * This header provides functions for basic file operations including existence checks,
 * reading, writing, appending, copying, deleting files, and working with file pointers.
 * 
 * @file filex.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_FILEX_H
#define MATHI_FILEX_H

#include <stdio.h>

/**
 * @brief Check if a file exists.
 * @param path Path to the file.
 * @return 1 if the file exists, 0 otherwise.
 */
int file_exists(const char *path);

/**
 * @brief Get the size of a file.
 * @param path Path to the file.
 * @return Size of the file in bytes, or -1 on error.
 */
long file_size(const char *path);

/**
 * @brief Read data from a file into a buffer.
 * @param path Path to the file.
 * @param buffer Buffer to store data (must be preallocated).
 * @param size Number of bytes to read.
 * @return Number of bytes read, or -1 on error.
 */
int file_read(const char *path, char *buffer, long size);

/**
 * @brief Write data to a file (overwrite).
 * @param path Path to the file.
 * @param buffer Buffer containing data to write.
 * @param size Number of bytes to write.
 * @return 0 on success, non-zero on error.
 */
int file_write(const char *path, const char *buffer, long size);

/**
 * @brief Append data to a file.
 * @param path Path to the file.
 * @param buffer Buffer containing data to append.
 * @return 0 on success, non-zero on error.
 */
int file_append(const char *path, const char *buffer);

/**
 * @brief Read a single line from a file.
 * @param fp FILE pointer.
 * @param buffer Buffer to store the line.
 * @param size Size of the buffer.
 * @return Pointer to the buffer, or NULL on error or EOF.
 */
char* file_read_line(FILE *fp, char *buffer, size_t size);

/**
 * @brief Copy a file from source to destination.
 * @param src Source file path.
 * @param dest Destination file path.
 * @return 0 on success, non-zero on error.
 */
int file_copy(const char *src, const char *dest);

/**
 * @brief Delete a file.
 * @param path Path to the file.
 * @return 0 on success, non-zero on error.
 */
int file_delete(const char *path);

/**
 * @brief Open a file with specified mode.
 * @param path Path to the file.
 * @param mode File mode string (e.g., "r", "w").
 * @return FILE pointer on success, NULL on error.
 */
FILE* filex_open(const char *path, const char *mode);

/**
 * @brief Close an open file.
 * @param f FILE pointer to close.
 */
void filex_close(FILE *f);

#endif
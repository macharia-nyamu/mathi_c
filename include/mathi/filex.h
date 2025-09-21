/*
 * Mathi C Library - File Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Provides simple file handling functions: open, close, read, write, append, copy, delete, etc.
 */

#ifndef MATHI_FILEX_H
#define MATHI_FILEX_H

#include <stdio.h>
#include <stddef.h>


/**
 * @brief Open a file with the specified mode.
 * @param path File path
 * @param mode Mode string (e.g., "r", "w", "rb")
 * @return FILE pointer on success, NULL on failure
 */
FILE* mathi_filex_open(const char *path, const char *mode);

/**
 * @brief Close a previously opened file.
 * @param f FILE pointer
 */
void mathi_filex_close(FILE *f);

/* --- File existence / size --- */

/**
 * @brief Check if a file exists.
 * @param path File path
 * @return 1 if file exists, 0 otherwise
 */
int mathi_file_exists(const char *path);

/**
 * @brief Get the size of a file in bytes.
 * @param path File path
 * @return File size in bytes, or -1 if file cannot be opened
 */
long mathi_file_size(const char *path);


/**
 * @brief Read the contents of a file into a buffer.
 * @param path File path
 * @param buffer Buffer to store file contents
 * @param size Maximum number of bytes to read
 * @return 1 on success, 0 on failure
 */
int mathi_file_read(const char *path, char *buffer, long size);

/**
 * @brief Write data to a file (overwrite).
 * @param path File path
 * @param buffer Buffer containing data
 * @param size Number of bytes to write
 * @return 1 on success, 0 on failure
 */
int mathi_file_write(const char *path, const char *buffer, long size);

/**
 * @brief Append a string to a file.
 * @param path File path
 * @param buffer Null-terminated string to append
 * @return 1 on success, 0 on failure
 */
int mathi_file_append(const char *path, const char *buffer);


/**
 * @brief Read a line from a file.
 * @param fp FILE pointer
 * @param buffer Buffer to store line
 * @param size Size of the buffer
 * @return Pointer to buffer on success, NULL on EOF or error
 */
char* mathi_file_read_line(FILE *fp, char *buffer, size_t size);


/**
 * @brief Copy a file from source to destination.
 * @param src Source file path
 * @param dest Destination file path
 * @return 1 on success, 0 on failure
 */
int mathi_file_copy(const char *src, const char *dest);

/**
 * @brief Delete a file.
 * @param path File path
 * @return 1 on success, 0 on failure
 */
int mathi_file_delete(const char *path);

#endif // MATHI_FILEX_H
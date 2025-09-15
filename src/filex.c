/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Basic File Operations --- */
FILE* filex_open(const char *path, const char *mode) { return fopen(path, mode); }
void filex_close(FILE *f) { if(f) fclose(f); }

int file_exists(const char *path) {
    FILE *f = fopen(path, "r");
    if(f) { fclose(f); return 1; }
    return 0;
}

long file_size(const char *path) {
    FILE *f = fopen(path, "rb");
    if(!f) return -1;
    fseek(f, 0, SEEK_END);
    long s = ftell(f);
    fclose(f);
    return s;
}

int file_read(const char *path, char *buffer, long size) {
    FILE *f = fopen(path, "rb");
    if(!f) return 0;
    size_t r = fread(buffer, 1, size, f);
    fclose(f);
    return r > 0;
}

int file_write(const char *path, const char *buffer, long size) {
    FILE *f = fopen(path, "wb");
    if(!f) return 0;
    size_t w = fwrite(buffer, 1, size, f);
    fclose(f);
    return w == size;
}

int file_append(const char *path, const char *buffer) {
    FILE *f = fopen(path, "ab");
    if(!f) return 0;
    size_t w = fwrite(buffer, 1, strlen(buffer), f);
    fclose(f);
    return w == strlen(buffer);
}

char* file_read_line(FILE *fp, char *buffer, size_t size) {
    if(fp && fgets(buffer, size, fp)) return buffer;
    return NULL;
}

int file_copy(const char *src, const char *dest) {
    FILE *fs = fopen(src, "rb");
    if(!fs) return 0;
    FILE *fd = fopen(dest, "wb");
    if(!fd) { fclose(fs); return 0; }
    char buf[4096];
    size_t n;
    while((n = fread(buf, 1, sizeof(buf), fs))) fwrite(buf, 1, n, fd);
    fclose(fs); fclose(fd);
    return 1;
}

int file_delete(const char *path) {
    return remove(path) == 0;
}
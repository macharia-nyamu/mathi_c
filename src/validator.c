/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/validator.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_int(const char *str) {
    if(!str || *str == '\0') return 0;
    char *endptr;
    strtol(str, &endptr, 10);
    return *endptr == '\0';
}

int is_float(const char *str) {
    if(!str || *str == '\0') return 0;
    char *endptr;
    strtof(str, &endptr);
    return *endptr == '\0';
}

int is_double(const char *str) {
    if(!str || *str == '\0') return 0;
    char *endptr;
    strtod(str, &endptr);
    return *endptr == '\0';
}

int is_number(const char *str) {
    return is_int(str) || is_float(str) || is_double(str);
}

int is_alpha(const char *str) {
    if(!str) return 0;
    while(*str) { if(!isalpha(*str)) return 0; str++; }
    return 1;
}

int is_alnum(const char *str) {
    if(!str) return 0;
    while(*str) { if(!isalnum(*str)) return 0; str++; }
    return 1;
}

int is_binary(const char *str) {
    if(!str) return 0;
    while(*str) { if(*str != '0' && *str != '1') return 0; str++; }
    return 1;
}

int is_hex(const char *str) {
    if(!str) return 0;
    while(*str) {
        char c = *str;
        if(!((c >= '0' && c <= '9') || 
             (c >= 'A' && c <= 'F') || 
             (c >= 'a' && c <= 'f'))) return 0;
        str++;
    }
    return 1;
}

int is_in_range(int value, int min, int max) {
    return value >= min && value <= max;
}
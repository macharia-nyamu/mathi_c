/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *string_reverse(char *str) {
    int len = strlen(str);
    for(int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return str;
}

int string_index_of(const char *str, char c) {
    for(int i = 0; str[i]; i++) if(str[i] == c) return i;
    return -1;
}

int string_contains(const char *str, char c) {
    return string_index_of(str, c) != -1;
}

int string_count_char(const char *str, char c) {
    int count = 0;
    for(int i = 0; str[i]; i++) if(str[i] == c) count++;
    return count;
}

char *string_to_upper(char *str) {
    for(int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    return str;
}

char *string_to_lower(char *str) {
    for(int i = 0; str[i]; i++) str[i] = tolower(str[i]);
    return str;
}

int string_length(const char *str) {
    int len = 0;
    while(str[len]) len++;
    return len;
}

char *string_concat(char *dest, const char *src) {
    int dlen = strlen(dest);
    for(int i = 0; src[i]; i++) dest[dlen + i] = src[i];
    dest[dlen + strlen(src)] = '\0';
    return dest;
}

char *string_copy(char *dest, const char *src) {
    int i = 0;
    while((dest[i] = src[i])) i++;
    return dest;
}

int string_compare(const char *a, const char *b) {
    while(*a && (*a == *b)) { a++; b++; }
    return *(unsigned char*)a - *(unsigned char*)b;
}

int string_starts_with(const char *str, const char *prefix) {
    while(*prefix) if(*prefix++ != *str++) return 0;
    return 1;
}

int string_ends_with(const char *str, const char *suffix) {
    int slen = strlen(suffix), len = strlen(str);
    if(slen > len) return 0;
    return strcmp(str + len - slen, suffix) == 0;
}

char *string_trim(char *str) {
    char *start = str;
    char *end;

    // Trim leading spaces
    while(*start && isspace((unsigned char)*start)) start++;

    // If the string is all spaces
    if(*start == 0) {
        str[0] = '\0';
        return str;
    }

    // Trim trailing spaces
    end = start + strlen(start) - 1;
    while(end > start && isspace((unsigned char)*end)) end--;

    // Null-terminate
    *(end + 1) = '\0';

    // Shift trimmed string to the original buffer start
    if(start != str) {
        memmove(str, start, strlen(start) + 1);
    }

    return str;
}

char *string_replace(char *str, char old, char newc) {
    for(int i = 0; str[i]; i++) if(str[i] == old) str[i] = newc;
    return str;
}
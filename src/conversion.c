/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int binary_to_decimal(const char *bin) {
    int res = 0;
    for(int i = 0; bin[i]; i++) {
        if(bin[i] == '1') res = res * 2 + 1;
        else if(bin[i] == '0') res *= 2;
        else return -1;
    }
    return res;
}

void decimal_to_binary(int num, char *buffer) {
    if(num == 0) { buffer[0] = '0'; buffer[1] = '\0'; return; }
    int n = num, i = 0;
    char tmp[32];
    while(n > 0) { tmp[i++] = (n % 2) + '0'; n /= 2; }
    for(int j = 0; j < i; j++) buffer[j] = tmp[i - j - 1];
    buffer[i] = '\0';
}

int hex_to_decimal(const char *hex) {
    int res = 0;
    for(int i = 0; hex[i]; i++) {
        char c = toupper(hex[i]);
        int val = (c >= '0' && c <= '9') ? c - '0' :
                  (c >= 'A' && c <= 'F') ? 10 + c - 'A' : -1;
        if(val == -1) return -1;
        res = res * 16 + val;
    }
    return res;
}

void decimal_to_hex(int num, char *buffer) {
    if(num == 0) { buffer[0] = '0'; buffer[1] = '\0'; return; }
    int i = 0;
    char tmp[32];
    while(num > 0) {
        int r = num % 16;
        tmp[i++] = (r < 10) ? r + '0' : r - 10 + 'A';
        num /= 16;
    }
    for(int j = 0; j < i; j++) buffer[j] = tmp[i - j - 1];
    buffer[i] = '\0';
}

char *int_to_string(int num, char *buffer) {
    sprintf(buffer, "%d", num);
    return buffer;
}

int string_to_int(const char *str) {
    return atoi(str);
}

double string_to_double(const char *str) {
    return atof(str);
}
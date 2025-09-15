/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathi/inputx.h"
#include "mathi/validator.h"

#define BUF_SIZE 256

static void strip_newline(char *s) {
    s[strcspn(s, "\n")] = 0;
}

InputResult get_int(const char *prompt) {
    char buf[BUF_SIZE];
    int *val = malloc(sizeof(int));
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) {
        res.code = 1;  // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) {
        res.code = 1;  // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    if(!is_int(buf)) {
        res.code = 2;  // INPUT_INVALID_INT
        res.value = NULL;
        free(val);
        return res;
    }

    *val = atoi(buf);
    res.code = 0;  // INPUT_OK
    res.value = val;
    return res;
}

InputResult get_double(const char *prompt) {
    char buf[BUF_SIZE];
    double *val = malloc(sizeof(double));
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    if(!is_number(buf)) {
        res.code = 3; // INPUT_INVALID_DOUBLE
        res.value = NULL;
        free(val);
        return res;
    }

    *val = atof(buf);
    res.code = 0; // INPUT_OK
    res.value = val;
    return res;
}

InputResult get_binary(const char *prompt) {
    char buf[BUF_SIZE];
    char *val = malloc(BUF_SIZE);
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    if(!is_binary(buf)) {
        res.code = 4; // INPUT_INVALID_BINARY
        res.value = NULL;
        free(val);
        return res;
    }

    strcpy(val, buf);
    res.code = 0; // INPUT_OK
    res.value = val;
    return res;
}

InputResult get_hex(const char *prompt) {
    char buf[BUF_SIZE];
    char *val = malloc(BUF_SIZE);
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    if(!is_hex(buf)) {
        res.code = 5; // INPUT_INVALID_HEX
        res.value = NULL;
        free(val);
        return res;
    }

    strcpy(val, buf);
    res.code = 0; // INPUT_OK
    res.value = val;
    return res;
}

InputResult get_string(const char *prompt) {
    char buf[BUF_SIZE];
    char *val = malloc(BUF_SIZE);
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strcpy(val, buf);
    res.code = 0; // INPUT_OK
    res.value = val;
    return res;
}
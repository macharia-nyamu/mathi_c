/*
* Mathi C Library - Input Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathi/inputx.h"
#include "mathi/validator.h"

#define BUF_SIZE 256  // temp buffer for input

// Remove trailing newline character from fgets input
static void strip_newline(char *s) 
{
    s[strcspn(s, "\n")] = 0;
}

InputResult mathi_get_int(const char *prompt) 
{
    char buf[BUF_SIZE];
    int *val = malloc(sizeof(int));  // dynamically allocated to return in InputResult
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) 
    {
        res.code = 1;  // INPUT_EMPTY: no input provided
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) 
    {
        res.code = 1;  // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    // Validate if input is a valid integer
    if(!mathi_is_int(buf)) 
    {
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

InputResult mathi_get_double(const char *prompt) 
{
    char buf[BUF_SIZE];
    double *val = malloc(sizeof(double));
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    // Validate if input is a valid number
    if(!mathi_is_number(buf)) 
    {
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

InputResult mathi_get_binary(const char *prompt) 
{
    char buf[BUF_SIZE];
    char *val = malloc(BUF_SIZE);
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    // Validate if input contains only '0' and '1'
    if(!mathi_is_binary(buf)) 
    {
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

InputResult mathi_get_hex(const char *prompt) 
{
    char buf[BUF_SIZE];
    char *val = malloc(BUF_SIZE);
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    // Validate if input contains only valid hex characters
    if(!mathi_is_hex(buf)) 
    {
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

InputResult mathi_get_string(const char *prompt) 
{
    char buf[BUF_SIZE];
    char *val = malloc(BUF_SIZE);
    InputResult res;

    printf("%s", prompt);
    if(!fgets(buf, sizeof(buf), stdin)) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    strip_newline(buf);
    if(strlen(buf) == 0) 
    {
        res.code = 1; // INPUT_EMPTY
        res.value = NULL;
        free(val);
        return res;
    }

    // Copy validated string to dynamically allocated memory
    strcpy(val, buf);
    res.code = 0; // INPUT_OK
    res.value = val;
    return res;
}
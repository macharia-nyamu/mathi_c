/*
* Mathi C Library - JSON Module
* mathison.c
* 
* Provides a lightweight JSON structure with basic array/object/string/number/bool/null support.
* 
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/mathison.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


// Create a new JSON object
MathiJSON* mathison_new_object() 
{
    MathiJSON *json = malloc(sizeof(MathiJSON));
    if (!json) return NULL;
    json->type = JSON_OBJECT;
    json->data.object.keys = NULL;
    json->data.object.values = NULL;
    json->data.object.count = 0;
    return json;
}

// Create a new JSON array
MathiJSON* mathison_new_array() 
{
    MathiJSON *json = malloc(sizeof(MathiJSON));
    if (!json) return NULL;
    json->type = JSON_ARRAY;
    json->data.array.items = NULL;
    json->data.array.count = 0;
    return json;
}

// Create a new JSON string
MathiJSON* mathison_new_string(const char *value) 
{
    MathiJSON *json = malloc(sizeof(MathiJSON));
    if (!json) return NULL;
    json->type = JSON_STRING;
    json->data.str = strdup(value);  // Allocate memory for string
    return json;
}

// Create a new JSON number
MathiJSON* mathison_new_number(double value) 
{
    MathiJSON *json = malloc(sizeof(MathiJSON));
    if (!json) return NULL;
    json->type = JSON_NUMBER;
    json->data.num = value;
    return json;
}

// Create a new JSON boolean
MathiJSON* mathison_new_bool(bool value) 
{
    MathiJSON *json = malloc(sizeof(MathiJSON));
    if (!json) return NULL;
    json->type = JSON_BOOL;
    json->data.boolean = value;
    return json;
}

// Create a new JSON null
MathiJSON* mathison_new_null() 
{
    MathiJSON *json = malloc(sizeof(MathiJSON));
    if (!json) return NULL;
    json->type = JSON_NULL;
    return json;
}


// Shallow copy of JSON object
int mathison_copy(MathiJSON *source, MathiJSON **dest) 
{
    if (!source || !dest) return -1;
    *dest = malloc(sizeof(MathiJSON));
    if (!*dest) return -1;
    memcpy(*dest, source, sizeof(MathiJSON));
    return 0;
}


// Free a JSON object recursively
int mathison_free(MathiJSON *json) 
{
    if (!json) return -1;

    switch(json->type) 
    {
        case JSON_STRING:
            if(json->data.str) free(json->data.str);
            break;

        case JSON_ARRAY:
            for (size_t i = 0; i < json->data.array.count; i++)
                mathison_free(json->data.array.items[i]);
            free(json->data.array.items);
            break;

        case JSON_OBJECT:
            for (size_t i = 0; i < json->data.object.count; i++) 
            {
                free(json->data.object.keys[i]);
                mathison_free(json->data.object.values[i]);
            }
            free(json->data.object.keys);
            free(json->data.object.values);
            break;

        default:
            break; // JSON_NUMBER, JSON_BOOL, JSON_NULL require no extra freeing
    }

    free(json);
    return 0;
}

// Clear the contents of an array or object without freeing the container
int mathison_clear(MathiJSON *json_obj) 
{
    if (!json_obj) return -1;

    if (json_obj->type == JSON_ARRAY) 
    {
        for (size_t i = 0; i < json_obj->data.array.count; i++)
            mathison_free(json_obj->data.array.items[i]);
        free(json_obj->data.array.items);
        json_obj->data.array.items = NULL;
        json_obj->data.array.count = 0;
    } 
    else if (json_obj->type == JSON_OBJECT) 
    {
        for (size_t i = 0; i < json_obj->data.object.count; i++) 
        {
            free(json_obj->data.object.keys[i]);
            mathison_free(json_obj->data.object.values[i]);
        }
        free(json_obj->data.object.keys);
        free(json_obj->data.object.values);
        json_obj->data.object.keys = NULL;
        json_obj->data.object.values = NULL;
        json_obj->data.object.count = 0;
    }
    return 0;
}


bool mathison_is_object(MathiJSON *json_obj) { return json_obj && json_obj->type == JSON_OBJECT; }
bool mathison_is_array(MathiJSON *json_obj) { return json_obj && json_obj->type == JSON_ARRAY; }
bool mathison_is_string(MathiJSON *json_obj) { return json_obj && json_obj->type == JSON_STRING; }
bool mathison_is_number(MathiJSON *json_obj) { return json_obj && json_obj->type == JSON_NUMBER; }
bool mathison_is_bool(MathiJSON *json_obj) { return json_obj && json_obj->type == JSON_BOOL; }
bool mathison_is_null(MathiJSON *json_obj) { return json_obj && json_obj->type == JSON_NULL; }


// Append a value to a JSON array
int mathison_append_array(MathiJSON *json_array, MathiJSON *value) 
{
    if (!json_array || json_array->type != JSON_ARRAY || !value) return -1;
    size_t n = json_array->data.array.count;
    MathiJSON **new_items = realloc(json_array->data.array.items, (n + 1) * sizeof(MathiJSON*));
    if (!new_items) return -1;
    new_items[n] = value;
    json_array->data.array.items = new_items;
    json_array->data.array.count++;
    return 0;
}

// Swap two items in a JSON array
int mathison_swap_array_items(MathiJSON *json_array, size_t i, size_t j) 
{
    if (!json_array || json_array->type != JSON_ARRAY) return -1;
    if (i >= json_array->data.array.count || j >= json_array->data.array.count) return -1;
    MathiJSON *tmp = json_array->data.array.items[i];
    json_array->data.array.items[i] = json_array->data.array.items[j];
    json_array->data.array.items[j] = tmp;
    return 0;
}

// Access an array element by index
MathiJSON* mathison_array_get(MathiJSON *json_array, size_t index) 
{
    if (!json_array || json_array->type != JSON_ARRAY || index >= json_array->data.array.count) return NULL;
    return json_array->data.array.items[index];
}

// Count elements in a JSON array
size_t mathison_array_count(MathiJSON *json_array) 
{
    if (!json_array || json_array->type != JSON_ARRAY) return 0;
    return json_array->data.array.count;
}


// Set or append a key/value pair in a JSON object
int mathison_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value) 
{
    if (!json_obj || json_obj->type != JSON_OBJECT || !key || !value) return -1;

    // Replace value if key exists
    for (size_t i = 0; i < json_obj->data.object.count; i++) 
    {
        if (strcmp(json_obj->data.object.keys[i], key) == 0) 
        {
            mathison_free(json_obj->data.object.values[i]);
            json_obj->data.object.values[i] = value;
            return 0;
        }
    }

    // Key doesn't exist, append
    size_t n = json_obj->data.object.count;
    char **new_keys = realloc(json_obj->data.object.keys, (n + 1) * sizeof(char*));
    MathiJSON **new_values = realloc(json_obj->data.object.values, (n + 1) * sizeof(MathiJSON*));
    if (!new_keys || !new_values) return -1;

    new_keys[n] = strdup(key);
    new_values[n] = value;

    json_obj->data.object.keys = new_keys;
    json_obj->data.object.values = new_values;
    json_obj->data.object.count++;
    return 0;
}

// Retrieve value by key
int mathison_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value) 
{
    if (!json_obj || json_obj->type != JSON_OBJECT || !key || !value) return -1;
    for (size_t i = 0; i < json_obj->data.object.count; i++) 
    {
        if (strcmp(json_obj->data.object.keys[i], key) == 0) 
        {
            *value = json_obj->data.object.values[i];
            return 0;
        }
    }
    return -1;
}

// Remove a key/value pair from object
int mathison_remove_key(MathiJSON *json_obj, const char *key) 
{
    if (!json_obj || json_obj->type != JSON_OBJECT || !key) return -1;
    for (size_t i = 0; i < json_obj->data.object.count; i++) 
    {
        if (strcmp(json_obj->data.object.keys[i], key) == 0) 
        {
            free(json_obj->data.object.keys[i]);
            mathison_free(json_obj->data.object.values[i]);
            for (size_t j = i; j < json_obj->data.object.count - 1; j++) 
            {
                json_obj->data.object.keys[j] = json_obj->data.object.keys[j+1];
                json_obj->data.object.values[j] = json_obj->data.object.values[j+1];
            }
            json_obj->data.object.count--;
            if (json_obj->data.object.count == 0) 
            {
                free(json_obj->data.object.keys);
                free(json_obj->data.object.values);
                json_obj->data.object.keys = NULL;
                json_obj->data.object.values = NULL;
            } 
            else 
            {
                json_obj->data.object.keys = realloc(json_obj->data.object.keys, json_obj->data.object.count * sizeof(char*));
                json_obj->data.object.values = realloc(json_obj->data.object.values, json_obj->data.object.count * sizeof(MathiJSON*));
            }
            return 0;
        }
    }
    return -1;
}

// Check if a key exists
bool mathison_has_key(MathiJSON *json_obj, const char *key) {
    if (!json_obj || json_obj->type != JSON_OBJECT || !key) return false;
    for (size_t i = 0; i < json_obj->data.object.count; i++)
        if (strcmp(json_obj->data.object.keys[i], key) == 0) return true;
    return false;
}

int mathison_parse(const char *str, MathiJSON **json_obj, const char **endptr)
{
    if (!str || !json_obj) return -1;

    while (isspace(*str)) str++; // skip whitespace

    if (*str == '"') { // string
        str++;
        const char *start = str;
        size_t len = 0;
        while (*str && *str != '"') { len++; str++; }
        if (*str != '"') return -1;
        char *s = malloc(len + 1);
        if (!s) return -1;
        strncpy(s, start, len);
        s[len] = '\0';
        *json_obj = mathison_new_string(s);
        free(s);
        if (endptr) *endptr = str + 1;
        return *json_obj ? 0 : -1;
    }
    else if (isdigit(*str) || *str == '-' || *str == '+') {
        char *endptr_num;
        double val = strtod(str, &endptr_num);
        if (endptr_num == str) return -1;
        *json_obj = mathison_new_number(val);
        if (endptr) *endptr = endptr_num;
        return *json_obj ? 0 : -1;
    }
    else if (strncmp(str, "true", 4) == 0) {
        *json_obj = mathison_new_bool(true);
        if (endptr) *endptr = str + 4;
        return *json_obj ? 0 : -1;
    }
    else if (strncmp(str, "false", 5) == 0) {
        *json_obj = mathison_new_bool(false);
        if (endptr) *endptr = str + 5;
        return *json_obj ? 0 : -1;
    }
    else if (strncmp(str, "null", 4) == 0) {
        *json_obj = mathison_new_null();
        if (endptr) *endptr = str + 4;
        return *json_obj ? 0 : -1;
    }
    else if (*str == '[') { // array
        str++;
        MathiJSON *arr = mathison_new_array();
        if (!arr) return -1;

        while (*str) {
            while (isspace(*str)) str++;
            if (*str == ']') { str++; break; }

            MathiJSON *item = NULL;
            const char *next = NULL;
            if (mathison_parse(str, &item, &next) != 0) { mathison_free(arr); return -1; }
            mathison_append_array(arr, item);
            str = next;
            while (isspace(*str)) str++;
            if (*str == ',') str++;
        }

        *json_obj = arr;
        if (endptr) *endptr = str;
        return 0;
    }
    else if (*str == '{') { // object
        str++;
        MathiJSON *obj = mathison_new_object();
        if (!obj) return -1;

        while (*str) {
            while (isspace(*str)) str++;
            if (*str == '}') { str++; break; }

            if (*str != '"') { mathison_free(obj); return -1; }
            str++;
            const char *key_start = str;
            size_t key_len = 0;
            while (*str && *str != '"') { key_len++; str++; }
            if (*str != '"') { mathison_free(obj); return -1; }
            char key[key_len + 1];
            strncpy(key, key_start, key_len);
            key[key_len] = '\0';
            str++; // skip closing quote

            while (isspace(*str)) str++;
            if (*str != ':') { mathison_free(obj); return -1; }
            str++; // skip ':'

            MathiJSON *value = NULL;
            const char *next = NULL;
            if (mathison_parse(str, &value, &next) != 0) { mathison_free(obj); return -1; }
            mathison_set_value(obj, key, value);
            str = next;

            while (isspace(*str)) str++;
            if (*str == ',') str++;
        }

        *json_obj = obj;
        if (endptr) *endptr = str;
        return 0;
    }

    return -1; // unsupported
}

static void serialize_helper(MathiJSON *json, char **buf, size_t *len, size_t *cap) 
{
    if (!json || !buf || !len || !cap) return;

    #define APPEND(s) \
        do { \
            size_t slen = strlen(s); \
            if (*len + slen + 1 > *cap) { \
                *cap = (*len + slen + 1) * 2; \
                *buf = realloc(*buf, *cap); \
            } \
            strcpy(*buf + *len, s); \
            *len += slen; \
        } while(0)

    char numbuf[64];

    switch(json->type) 
    {
        case JSON_STRING:
            APPEND("\"");
            APPEND(json->data.str);
            APPEND("\"");
            break;

        case JSON_NUMBER:
            snprintf(numbuf, sizeof(numbuf), "%g", json->data.num);
            APPEND(numbuf);
            break;

        case JSON_BOOL:
            APPEND(json->data.boolean ? "true" : "false");
            break;

        case JSON_NULL:
            APPEND("null");
            break;

        case JSON_ARRAY:
            APPEND("[");
            for (size_t i = 0; i < json->data.array.count; i++) 
            {
                if (i > 0) APPEND(",");
                serialize_helper(json->data.array.items[i], buf, len, cap);
            }
            APPEND("]");
            break;

        case JSON_OBJECT:
            APPEND("{");
            for (size_t i = 0; i < json->data.object.count; i++) 
            {
                if (i > 0) APPEND(",");
                APPEND("\"");
                APPEND(json->data.object.keys[i]);
                APPEND("\":");
                serialize_helper(json->data.object.values[i], buf, len, cap);
            }
            APPEND("}");
            break;
    }

    #undef APPEND
}

// Public serialize function
int mathison_serialize(MathiJSON *json_obj, char **output) 
{
    if (!json_obj || !output) return -1;
    size_t len = 0, cap = 128;
    *output = malloc(cap);
    if (!*output) return -1;
    (*output)[0] = '\0';

    serialize_helper(json_obj, output, &len, &cap);
    return 0;
}

// Prepend value to array
int mathison_prepend_array(MathiJSON *json_array, MathiJSON *value) 
{
    if (!json_array || json_array->type != JSON_ARRAY || !value) return -1;
    size_t n = json_array->data.array.count;
    MathiJSON **new_items = realloc(json_array->data.array.items, (n + 1) * sizeof(MathiJSON*));
    if (!new_items) return -1;
    for (size_t i = n; i > 0; i--) new_items[i] = new_items[i-1]; // shift right
    new_items[0] = value;
    json_array->data.array.items = new_items;
    json_array->data.array.count++;
    return 0;
}

// Insert value at index
int mathison_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value) 
{
    if (!json_array || json_array->type != JSON_ARRAY || !value) return -1;
    size_t n = json_array->data.array.count;
    if (index > n) return -1;
    MathiJSON **new_items = realloc(json_array->data.array.items, (n + 1) * sizeof(MathiJSON*));
    if (!new_items) return -1;
    for (size_t i = n; i > index; i--) new_items[i] = new_items[i-1];
    new_items[index] = value;
    json_array->data.array.items = new_items;
    json_array->data.array.count++;
    return 0;
}

// Remove array element at index
int mathison_remove_array_index(MathiJSON *json_array, size_t index) 
{
    if (!json_array || json_array->type != JSON_ARRAY) return -1;
    if (index >= json_array->data.array.count) return -1;
    mathison_free(json_array->data.array.items[index]);
    for (size_t i = index; i < json_array->data.array.count - 1; i++)
        json_array->data.array.items[i] = json_array->data.array.items[i+1];
    json_array->data.array.count--;
    if (json_array->data.array.count == 0) 
    {
        free(json_array->data.array.items);
        json_array->data.array.items = NULL;
    } 
    else 
    {
        json_array->data.array.items = realloc(json_array->data.array.items, json_array->data.array.count * sizeof(MathiJSON*));
    }
    return 0;
}

// Concatenate source array into target array
int mathison_array_concat(MathiJSON *target_array, MathiJSON *source_array) 
{
    if (!target_array || target_array->type != JSON_ARRAY) return -1;
    if (!source_array || source_array->type != JSON_ARRAY) return -1;

    for (size_t i = 0; i < source_array->data.array.count; i++) 
    {
        MathiJSON *copy_item = NULL;
        if (mathison_copy(source_array->data.array.items[i], &copy_item) != 0) return -1;
        if (mathison_append_array(target_array, copy_item) != 0) 
        {
            mathison_free(copy_item);
            return -1;
        }
    }
    return 0;
}

// Validate JSON type
int mathison_validate_type(MathiJSON *json_obj, int expected_type) 
{ 
    return json_obj && json_obj->type == expected_type; 
}
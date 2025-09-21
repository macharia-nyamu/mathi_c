/*
 * Mathi C Library - JSON Module
 * mathison.h
 * 
 * Provides JSON manipulation utilities for C:
 * creation, parsing, serialization, arrays, objects, strings, numbers, booleans, and nulls.
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root.
 */

#ifndef MATHI_MATHISON_H
#define MATHI_MATHISON_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @enum MathiJSONType
 * @brief Enumeration of possible JSON types.
 */
typedef enum {
    JSON_NULL,    /**< Null value */
    JSON_BOOL,    /**< Boolean value */
    JSON_NUMBER,  /**< Numeric value */
    JSON_STRING,  /**< String value */
    JSON_ARRAY,   /**< Array of JSON values */
    JSON_OBJECT   /**< Object with key-value pairs */
} MathiJSONType;

/**
 * @struct MathiJSON
 * @brief Representation of a JSON value.
 */
typedef struct MathiJSON MathiJSON;

struct MathiJSON {
    MathiJSONType type; /**< Type of the JSON value */
    union {
        struct {           /**< JSON object */
            char **keys;        /**< Array of keys */
            MathiJSON **values; /**< Array of corresponding values */
            size_t count;       /**< Number of key-value pairs */
        } object;
        struct {           /**< JSON array */
            MathiJSON **items; /**< Array of items */
            size_t count;      /**< Number of items */
        } array;
        char *str;         /**< JSON string value */
        double num;        /**< JSON numeric value */
        bool boolean;      /**< JSON boolean value */
    } data;
};

/* ----------------------------------------
   Creation functions
---------------------------------------- */

/**
 * @brief Create a new empty JSON object.
 */
MathiJSON* mathison_new_object(void);

/**
 * @brief Create a new empty JSON array.
 */
MathiJSON* mathison_new_array(void);

/**
 * @brief Create a new JSON string.
 * @param value Null-terminated string to store.
 */
MathiJSON* mathison_new_string(const char *value);

/**
 * @brief Create a new JSON number.
 */
MathiJSON* mathison_new_number(double value);

/**
 * @brief Create a new JSON boolean.
 */
MathiJSON* mathison_new_bool(bool value);

/**
 * @brief Create a new JSON null.
 */
MathiJSON* mathison_new_null(void);

/* ----------------------------------------
   Memory management
---------------------------------------- */

/**
 * @brief Deep copy a JSON object.
 */
int mathison_copy(MathiJSON *source, MathiJSON **dest);

/**
 * @brief Free a JSON object and all its children recursively.
 */
int mathison_free(MathiJSON *json_obj);

/**
 * @brief Clear contents of a JSON array or object without freeing the container.
 */
int mathison_clear(MathiJSON *json_obj);

/* ----------------------------------------
   Type checking
---------------------------------------- */

bool mathison_is_object(MathiJSON *json_obj);
bool mathison_is_array(MathiJSON *json_obj);
bool mathison_is_string(MathiJSON *json_obj);
bool mathison_is_number(MathiJSON *json_obj);
bool mathison_is_bool(MathiJSON *json_obj);
bool mathison_is_null(MathiJSON *json_obj);

/**
 * @brief Validate JSON type against expected type.
 */
int mathison_validate_type(MathiJSON *json_obj, int expected_type);

/* ----------------------------------------
   Array utilities
---------------------------------------- */

int mathison_append_array(MathiJSON *json_array, MathiJSON *value);
int mathison_prepend_array(MathiJSON *json_array, MathiJSON *value);
int mathison_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value);
int mathison_remove_array_index(MathiJSON *json_array, size_t index);
int mathison_swap_array_items(MathiJSON *json_array, size_t i, size_t j);
MathiJSON* mathison_array_get(MathiJSON *json_array, size_t index);
size_t mathison_array_count(MathiJSON *json_array);
int mathison_array_concat(MathiJSON *target_array, MathiJSON *source_array);

/* ----------------------------------------
   Object utilities
---------------------------------------- */

int mathison_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value);
int mathison_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value);
int mathison_remove_key(MathiJSON *json_obj, const char *key);
bool mathison_has_key(MathiJSON *json_obj, const char *key);

/* ----------------------------------------
   Parsing and serialization
---------------------------------------- */

/**
 * @brief Parse a JSON string into a MathiJSON object.
 * @param str Input JSON string.
 * @param json_obj Output JSON object pointer.
 * @param endptr Optional pointer to character after parsed value.
 * Supports nested arrays and objects.
 */
int mathison_parse(const char *str, MathiJSON **json_obj, const char **endptr);

/**
 * @brief Serialize a JSON object into a string.
 * Allocates memory for the output string; user must free it.
 */
int mathison_serialize(MathiJSON *json_obj, char **output);

#endif // MATHI_MATHISON_H
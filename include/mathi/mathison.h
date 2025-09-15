/*
 * Mathi C Library - JSON Module
 * Mathison.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * @file mathison.h
 * @brief Provides functions for creating, manipulating, validating, and serializing JSON objects.
 */

#ifndef MATHISON_H
#define MATHISON_H

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- JSON Types --- */
typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JSONType;

/**
 * @struct MathiJSON
 * @brief Represents a JSON value (object, array, string, number, boolean, or null)
 */
typedef struct MathiJSON {
    JSONType type;
    union {
        double num;                  /**< number value */
        bool boolean;                /**< boolean value */
        char *str;                   /**< string value */
        struct {                      /**< array value */
            struct MathiJSON **items;
            size_t count;
        } array;
        struct {                      /**< object value */
            char **keys;
            struct MathiJSON **values;
            size_t count;
        } object;
    } data;
} MathiJSON;

/* --- Creation / Initialization --- */
MathiJSON* json_new_object();
MathiJSON* json_new_array();
MathiJSON* json_new_string(const char *value);
MathiJSON* json_new_number(double value);
MathiJSON* json_new_bool(bool value);
MathiJSON* json_new_null();
int json_copy(MathiJSON *source, MathiJSON **dest);
int json_deep_copy(MathiJSON *source, MathiJSON **dest);

/* --- Memory Management / Cleanup --- */
int json_free(MathiJSON *json);
int json_clear(MathiJSON *json_obj);

/* --- Parsing / Serialization --- */
int json_parse(const char *str, MathiJSON **json_obj);
int json_serialize(MathiJSON *json_obj, char **output);

/* --- Type Checks --- */
int json_validate_type(MathiJSON *json_obj, int expected_type);
bool json_is_object(MathiJSON *json_obj);
bool json_is_array(MathiJSON *json_obj);
bool json_is_string(MathiJSON *json_obj);
bool json_is_number(MathiJSON *json_obj);
bool json_is_bool(MathiJSON *json_obj);
bool json_is_null(MathiJSON *json_obj);

/* --- Object Manipulation --- */
int json_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value);
int json_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value);
int json_remove_key(MathiJSON *json_obj, const char *key);
bool json_has_key(MathiJSON *json_obj, const char *key);
int json_object_count(MathiJSON *json_obj);
int json_merge(MathiJSON *target, MathiJSON *source);
int json_deep_merge(MathiJSON *target, MathiJSON *source);

/* --- Array Manipulation --- */
int json_append_array(MathiJSON *json_array, MathiJSON *value);
int json_prepend_array(MathiJSON *json_array, MathiJSON *value);
int json_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value);
int json_remove_array_index(MathiJSON *json_array, size_t index);
MathiJSON* json_array_get(MathiJSON *json_array, size_t index);
size_t json_array_count(MathiJSON *json_array);
int json_swap_array_items(MathiJSON *json_array, size_t i, size_t j);
int json_array_concat(MathiJSON *target_array, MathiJSON *source_array);

/* --- Validation / Schema --- */
int json_array_all_type(MathiJSON *json_array, int expected_type);
int json_array_min_length(MathiJSON *json_array, size_t min_len);
int json_array_max_length(MathiJSON *json_array, size_t max_len);
int json_array_index_valid(MathiJSON *json_array, size_t index);
int json_array_values_unique(MathiJSON *json_array);
int json_array_sorted(MathiJSON *json_array, bool ascending);
int json_array_nested_validate(MathiJSON *json_array, size_t index, int expected_type);
int json_object_has_key(MathiJSON *json_obj, const char *key);
int json_object_all_values_type(MathiJSON *json_obj, int expected_type);
int json_object_key_count(MathiJSON *json_obj, size_t expected_count);
int json_object_values_consistent(MathiJSON *json_obj, int expected_type);
int json_has_required_keys(MathiJSON *json_obj, const char **keys, size_t n_keys);
int json_number_in_range(MathiJSON *json_num, double min, double max);
int json_string_length(MathiJSON *json_str, size_t min_len, size_t max_len);
int json_string_matches(MathiJSON *json_str, const char *pattern);
int json_nested_validate(MathiJSON *json_obj, const char *key, int expected_type);
int json_validate_schema(MathiJSON *json_obj, MathiJSON *schema);
int json_validate_array_schema(MathiJSON *json_array, MathiJSON *schema);
int json_is_empty(MathiJSON *json_obj);

/* --- Path / Advanced Access --- */
int json_get_path(MathiJSON *json_obj, const char *path, MathiJSON **value);
int json_set_path(MathiJSON *json_obj, const char *path, MathiJSON *value);
MathiJSON* json_find_key(MathiJSON *json_obj, const char *key);
int json_filter_array(MathiJSON *json_array, bool (*predicate)(MathiJSON*));
int json_map_array(MathiJSON *json_array, MathiJSON* (*func)(MathiJSON*));

/* --- Conversions / Extractors --- */
int json_to_string(MathiJSON *json_obj, char **output);
int json_to_number(MathiJSON *json_obj, double *output);
int json_to_bool(MathiJSON *json_obj, bool *output);

#ifdef __cplusplus
}
#endif

#endif // MATHISON_H
/*
 * Mathi C Library - JSON Module
 * mathison.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_MATHISON_H
#define MATHI_MATHISON_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @file mathi/mathison.h
 * @brief JSON manipulation utilities (creation, parsing, arrays, objects) for Mathi C Library.
 */


/**
 * @enum MathiJSONType
 * @brief Enumeration of possible JSON types.
 */
typedef enum {
    JSON_NULL,    /**< Null type */
    JSON_BOOL,    /**< Boolean type */
    JSON_NUMBER,  /**< Numeric type */
    JSON_STRING,  /**< String type */
    JSON_ARRAY,   /**< Array type */
    JSON_OBJECT   /**< Object type */
} MathiJSONType;

/**
 * @struct MathiJSON
 * @brief Representation of a JSON value.
 */
typedef struct MathiJSON MathiJSON;

struct MathiJSON {
    MathiJSONType type; /**< Type of JSON value */
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


/**
 * @brief Create a new JSON object.
 * @return Pointer to a new MathiJSON object of type JSON_OBJECT.
 */
MathiJSON* mathison_new_object(void);

/**
 * @brief Create a new JSON array.
 * @return Pointer to a new MathiJSON object of type JSON_ARRAY.
 */
MathiJSON* mathison_new_array(void);

/**
 * @brief Create a new JSON string.
 * @param value String value to store.
 * @return Pointer to a new MathiJSON object of type JSON_STRING.
 */
MathiJSON* mathison_new_string(const char *value);

/**
 * @brief Create a new JSON number.
 * @param value Numeric value to store.
 * @return Pointer to a new MathiJSON object of type JSON_NUMBER.
 */
MathiJSON* mathison_new_number(double value);

/**
 * @brief Create a new JSON boolean.
 * @param value Boolean value to store.
 * @return Pointer to a new MathiJSON object of type JSON_BOOL.
 */
MathiJSON* mathison_new_bool(bool value);

/**
 * @brief Create a new JSON null value.
 * @return Pointer to a new MathiJSON object of type JSON_NULL.
 */
MathiJSON* mathison_new_null(void);


/**
 * @brief Copy a JSON object.
 * @param source Source JSON object.
 * @param dest Pointer to destination JSON pointer.
 * @return 0 on success, -1 on failure.
 */
int mathison_copy(MathiJSON *source, MathiJSON **dest);

/**
 * @brief Free a JSON object and all its children.
 * @param json_obj JSON object to free.
 * @return 0 on success, -1 on failure.
 */
int mathison_free(MathiJSON *json_obj);

/**
 * @brief Clear contents of a JSON object/array without freeing the main structure.
 * @param json_obj JSON object or array to clear.
 * @return 0 on success, -1 on failure.
 */
int mathison_clear(MathiJSON *json_obj);


/**
 * @brief Check if a JSON object is of type JSON_OBJECT.
 */
bool mathison_is_object(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_ARRAY.
 */
bool mathison_is_array(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_STRING.
 */
bool mathison_is_string(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_NUMBER.
 */
bool mathison_is_number(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_BOOL.
 */
bool mathison_is_bool(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_NULL.
 */
bool mathison_is_null(MathiJSON *json_obj);

/**
 * @brief Validate JSON type against expected type.
 * @param json_obj JSON object to check.
 * @param expected_type Expected MathiJSONType.
 * @return Non-zero if matches, zero otherwise.
 */
int mathison_validate_type(MathiJSON *json_obj, int expected_type);


/**
 * @brief Append an item to a JSON array.
 */
int mathison_append_array(MathiJSON *json_array, MathiJSON *value);

/**
 * @brief Prepend an item to a JSON array.
 */
int mathison_prepend_array(MathiJSON *json_array, MathiJSON *value);

/**
 * @brief Insert an item at a specific index in a JSON array.
 */
int mathison_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value);

/**
 * @brief Remove an item at a specific index from a JSON array.
 */
int mathison_remove_array_index(MathiJSON *json_array, size_t index);

/**
 * @brief Swap two items in a JSON array.
 */
int mathison_swap_array_items(MathiJSON *json_array, size_t i, size_t j);

/**
 * @brief Get an item from a JSON array by index.
 */
MathiJSON* mathison_array_get(MathiJSON *json_array, size_t index);

/**
 * @brief Get number of items in a JSON array.
 */
size_t mathison_array_count(MathiJSON *json_array);

/**
 * @brief Concatenate two JSON arrays.
 */
int mathison_array_concat(MathiJSON *target_array, MathiJSON *source_array);


/**
 * @brief Set a key-value pair in a JSON object.
 */
int mathison_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value);

/**
 * @brief Get a value by key from a JSON object.
 */
int mathison_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value);

/**
 * @brief Remove a key-value pair from a JSON object.
 */
int mathison_remove_key(MathiJSON *json_obj, const char *key);

/**
 * @brief Check if a key exists in a JSON object.
 */
bool mathison_has_key(MathiJSON *json_obj, const char *key);


/**
 * @brief Parse a string into a JSON object.
 */
int mathison_parse(const char *str, MathiJSON **json_obj);

/**
 * @brief Serialize a JSON object (currently supports strings only).
 */
int mathison_serialize(MathiJSON *json_obj, char **output);

#endif // MATHI_MATHISON_H
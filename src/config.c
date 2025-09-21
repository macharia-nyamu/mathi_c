/*
 * Mathi C Library - Configuration Utilities
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Functions for loading, retrieving, and saving configuration values.
 */

#include "mathi/config.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_CONFIG_ENTRIES 100
#define MAX_KEY_LEN 64
#define MAX_VALUE_LEN 256

static char keys[MAX_CONFIG_ENTRIES][MAX_KEY_LEN];
static char values[MAX_CONFIG_ENTRIES][MAX_VALUE_LEN];
static int config_count = 0;

/**
 * @brief Load configuration from a file.
 * @param file_path Path to configuration file
 * @return 0 on success, non-zero on error
 */
int mathi_conf_load(const char *file_path)
{
    FILE *f = fopen(file_path, "r");
    if (!f) return 1;

    char line[512];
    while (fgets(line, sizeof(line), f))
    {
        char *eq = strchr(line, '=');
        if (!eq) continue;

        *eq = '\0';
        char *k = line;
        char *v = eq + 1;

        // trim newline
        char *nl = strchr(v, '\n');
        if (nl) *nl = '\0';

        mathi_conf_set_string(k, v);
    }

    fclose(f);
    return 0;
}

/**
 * @brief Retrieve a string value from configuration.
 * @param key Configuration key
 * @return Pointer to string value (empty string if not found)
 */
const char* mathi_conf_get_string(const char *key)
{
    for (int i = 0; i < config_count; i++)
    {
        if (strcmp(keys[i], key) == 0)
            return values[i];
    }
    return "";
}

/**
 * @brief Retrieve an integer value from configuration.
 * @param key Configuration key
 * @param value Pointer to store integer value
 * @return 0 on success, non-zero on error
 */
int mathi_conf_get_int(const char *key, int *value)
{
    const char *str = mathi_conf_get_string(key);
    if (!str || str[0] == '\0') return 1;

    if (value) *value = atoi(str);
    return 0;
}

/**
 * @brief Set a string value in configuration.
 * @param key Configuration key
 * @param value String value to set
 * @return 0 on success, non-zero on error
 */
int mathi_conf_set_string(const char *key, const char *value)
{
    for (int i = 0; i < config_count; i++)
    {
        if (strcmp(keys[i], key) == 0)
        {
            strncpy(values[i], value, MAX_VALUE_LEN - 1);
            values[i][MAX_VALUE_LEN - 1] = '\0';
            return 0;
        }
    }

    if (config_count >= MAX_CONFIG_ENTRIES) return 1;

    strncpy(keys[config_count], key, MAX_KEY_LEN - 1);
    keys[config_count][MAX_KEY_LEN - 1] = '\0';

    strncpy(values[config_count], value, MAX_VALUE_LEN - 1);
    values[config_count][MAX_VALUE_LEN - 1] = '\0';

    config_count++;
    return 0;
}

/**
 * @brief Save configuration to a file.
 * @param file_path Path to save configuration file
 * @return 0 on success, non-zero on error
 */
int mathi_conf_save(const char *file_path)
{
    FILE *f = fopen(file_path, "w");
    if (!f) return 1;

    for (int i = 0; i < config_count; i++)
    {
        fprintf(f, "%s=%s\n", keys[i], values[i]);
    }

    fclose(f);
    return 0;
}
#include "mathi/config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static MathiJSON *config_root = NULL;

/* --- Load configuration file --- */
int mathi_conf_load(const char *file_path) {
    FILE *f = fopen(file_path, "r");
    if (!f) return 1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *buf = malloc(size + 1);
    if (!buf) { fclose(f); return 1; }

    fread(buf, 1, size, f);
    buf[size] = '\0';
    fclose(f);

    MathiJSON *parsed = NULL;
    if (mathison_parse(buf, &parsed, NULL) != 0) {
        free(buf);
        return 1;
    }

    if (config_root) mathison_free(config_root);
    config_root = parsed;

    free(buf);
    return 0;
}

/* --- Save configuration file --- */
int mathi_conf_save(const char *file_path) {
    if (!config_root) return 1;

    char *serialized = NULL;
    if (mathison_serialize(config_root, &serialized) != 0) return 1;

    FILE *f = fopen(file_path, "w");
    if (!f) { free(serialized); return 1; }

    fprintf(f, "%s\n", serialized);
    fclose(f);
    free(serialized);
    return 0;
}

/* --- Generic get/set helpers --- */
static int set_value_generic(const char *key, MathiJSON *value) {
    if (!config_root) config_root = mathison_new_object();
    return mathison_set_value(config_root, key, value);
}

static int get_value_generic(const char *key, MathiJSON **out) {
    if (!config_root) return 1;
    return mathison_get_value(config_root, key, out);
}

/* --- String --- */
const char* mathi_conf_get_string(const char *key) {
    MathiJSON *val = NULL;
    if (get_value_generic(key, &val) == 0 && mathison_is_string(val))
        return val->data.str;
    return "";
}

int mathi_conf_set_string(const char *key, const char *value) {
    MathiJSON *val = mathison_new_string(value);
    return set_value_generic(key, val);
}

/* --- Int --- */
int mathi_conf_get_int(const char *key, int *value) {
    MathiJSON *val = NULL;
    if (get_value_generic(key, &val) == 0 && mathison_is_number(val)) {
        if (value) *value = (int)val->data.num;
        return 0;
    }
    return 1;
}

int mathi_conf_set_int(const char *key, int value) {
    MathiJSON *val = mathison_new_number(value);
    return set_value_generic(key, val);
}

/* --- Bool --- */
int mathi_conf_get_bool(const char *key, bool *value) {
    MathiJSON *val = NULL;
    if (get_value_generic(key, &val) == 0 && mathison_is_bool(val)) {
        if (value) *value = val->data.boolean;
        return 0;
    }
    return 1;
}

int mathi_conf_set_bool(const char *key, bool value) {
    MathiJSON *val = mathison_new_bool(value);
    return set_value_generic(key, val);
}

/* --- Double --- */
int mathi_conf_get_double(const char *key, double *value) {
    MathiJSON *val = NULL;
    if (get_value_generic(key, &val) == 0 && mathison_is_number(val)) {
        if (value) *value = val->data.num;
        return 0;
    }
    return 1;
}

int mathi_conf_set_double(const char *key, double value) {
    MathiJSON *val = mathison_new_number(value);
    return set_value_generic(key, val);
}

/* --- Array --- */
int mathi_conf_get_array(const char *key, MathiJSON **array) {
    MathiJSON *val = NULL;
    if (get_value_generic(key, &val) == 0 && mathison_is_array(val)) {
        if (array) *array = val;
        return 0;
    }
    return 1;
}

int mathi_conf_set_array(const char *key, MathiJSON *array) {
    if (!array || !mathison_is_array(array)) return 1;
    return set_value_generic(key, array);
}

/* --- Object --- */
int mathi_conf_get_object(const char *key, MathiJSON **object) {
    MathiJSON *val = NULL;
    if (get_value_generic(key, &val) == 0 && mathison_is_object(val)) {
        if (object) *object = val;
        return 0;
    }
    return 1;
}

int mathi_conf_set_object(const char *key, MathiJSON *object) {
    if (!object || !mathison_is_object(object)) return 1;
    return set_value_generic(key, object);
}

/* --- Remove key --- */
int mathi_conf_remove_key(const char *key) {
    if (!config_root) return 1;
    return mathison_remove_key(config_root, key);
}

/* --- Key existence --- */
bool mathi_conf_has_key(const char *key) {
    if (!config_root) return false;
    return mathison_has_key(config_root, key);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/config.h"
#include "mathi/mathison.h"

void test_config_strings() {
    printf("Testing string get/set...\n");
    int res = mathi_conf_set_string("key_str", "hello");
    assert(res == 0);

    const char *val = mathi_conf_get_string("key_str");
    printf("key_str = '%s'\n", val);
    assert(val && strcmp(val, "hello") == 0);
    printf("\n");
}

void test_config_ints() {
    printf("Testing int get/set...\n");
    int res = mathi_conf_set_int("key_int", 123);
    assert(res == 0);

    int value = 0;
    res = mathi_conf_get_int("key_int", &value);
    printf("key_int = %d\n", value);
    assert(res == 0 && value == 123);
    printf("\n");
}

void test_config_bools() {
    printf("Testing bool get/set...\n");
    int res = mathi_conf_set_bool("key_bool", true);
    assert(res == 0);

    bool bval = false;
    res = mathi_conf_get_bool("key_bool", &bval);
    printf("key_bool = %s\n", bval ? "true" : "false");
    assert(res == 0 && bval == true);
    printf("\n");
}

void test_config_doubles() {
    printf("Testing double get/set...\n");
    int res = mathi_conf_set_double("key_double", 3.14159);
    assert(res == 0);

    double dval = 0.0;
    res = mathi_conf_get_double("key_double", &dval);
    printf("key_double = %f\n", dval);
    assert(res == 0 && dval == 3.14159);
    printf("\n");
}

void test_config_arrays() {
    printf("Testing array get/set...\n");
    MathiJSON *arr = mathison_new_array();
    mathison_append_array(arr, mathison_new_number(1));
    mathison_append_array(arr, mathison_new_number(2));
    mathison_append_array(arr, mathison_new_number(3));

    int res = mathi_conf_set_array("key_array", arr);
    assert(res == 0);

    MathiJSON *out_arr = NULL;
    res = mathi_conf_get_array("key_array", &out_arr);
    assert(res == 0 && out_arr && mathison_array_count(out_arr) == 3);
    printf("key_array count = %zu\n", mathison_array_count(out_arr));

    mathison_free(out_arr);
    printf("\n");
}

void test_config_objects() {
    printf("Testing object get/set...\n");
    MathiJSON *obj = mathison_new_object();
    mathison_set_value(obj, "name", mathison_new_string("Macharia"));
    mathison_set_value(obj, "age", mathison_new_number(30));

    int res = mathi_conf_set_object("key_obj", obj);
    assert(res == 0);

    MathiJSON *out_obj = NULL;
    res = mathi_conf_get_object("key_obj", &out_obj);
    assert(res == 0 && out_obj && mathison_has_key(out_obj, "name"));

    MathiJSON *name_val = NULL;
    mathison_get_value(out_obj, "name", &name_val);
    if (name_val) printf("key_obj.name = %s\n", name_val->data.str);

    mathison_free(out_obj);
    printf("\n");
}

void test_config_remove_and_has() {
    printf("Testing remove_key and has_key...\n");
    mathi_conf_set_string("temp_key", "temp");
    assert(mathi_conf_has_key("temp_key") == true);

    mathi_conf_remove_key("temp_key");
    assert(mathi_conf_has_key("temp_key") == false);
    printf("\n");
}

int main() {
    test_config_strings();
    test_config_ints();
    test_config_bools();
    test_config_doubles();
    test_config_arrays();
    test_config_objects();
    test_config_remove_and_has();

    printf("All config tests passed successfully!\n");
    return 0;
}
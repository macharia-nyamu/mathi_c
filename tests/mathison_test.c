#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathi/mathison.h"
#include "mathi/config.h"

void test_json_creation_and_types() 
{
    printf("Test: MathiJSON Creation & Type Checks...\n");

    MathiJSON *obj = mathison_new_object();
    MathiJSON *arr = mathison_new_array();
    MathiJSON *str = mathison_new_string("hello");
    MathiJSON *num = mathison_new_number(3.14);
    MathiJSON *btrue = mathison_new_bool(1);
    MathiJSON *bfalse = mathison_new_bool(0);
    MathiJSON *nullv = mathison_new_null();

    printf("Is object? %d\n", mathison_is_object(obj));
    printf("Is array? %d\n", mathison_is_array(arr));
    printf("Is string? %d, value='%s'\n", mathison_is_string(str), str->data.str);
    printf("Is number? %d, value=%.2f\n", mathison_is_number(num), num->data.num);
    printf("Is bool? true=%d, false=%d\n", btrue->data.boolean, bfalse->data.boolean);
    printf("Is null? %d\n", mathison_is_null(nullv));

    mathison_free(obj);
    mathison_free(arr);
    mathison_free(str);
    mathison_free(num);
    mathison_free(btrue);
    mathison_free(bfalse);
    mathison_free(nullv);
}

void test_config_basic_types()
{
    printf("\nTest: Config - Basic Types...\n");

    mathi_conf_set_string("app_name", "Mathi Library");
    mathi_conf_set_int("max_users", 100);
    mathi_conf_set_bool("debug_mode", 1);
    mathi_conf_set_double("version", 1.23);

    const char *app_name = mathi_conf_get_string("app_name");
    int max_users;
    mathi_conf_get_int("max_users", &max_users);
    bool debug_mode;
    mathi_conf_get_bool("debug_mode", &debug_mode);
    double version;
    mathi_conf_get_double("version", &version);

    printf("app_name = %s\n", app_name);
    printf("max_users = %d\n", max_users);
    printf("debug_mode = %d\n", debug_mode);
    printf("version = %.2f\n", version);
}

void test_config_arrays_and_objects()
{
    printf("\nTest: Config - Arrays & Objects...\n");

    // Create an array
    MathiJSON *arr = mathison_new_array();
    mathison_append_array(arr, mathison_new_string("first"));
    mathison_append_array(arr, mathison_new_string("second"));
    mathison_append_array(arr, mathison_new_number(42));
    mathi_conf_set_array("my_array", arr);

    // Retrieve and print array
    MathiJSON *retrieved_arr = NULL;
    if (mathi_conf_get_array("my_array", &retrieved_arr) == 0) 
    {
        printf("Array contents:\n");
        for (size_t i = 0; i < mathison_array_count(retrieved_arr); i++) 
        {
            MathiJSON *e = mathison_array_get(retrieved_arr, i);
            if (mathison_is_string(e)) printf("  %zu: %s\n", i, e->data.str);
            if (mathison_is_number(e)) printf("  %zu: %.2f\n", i, e->data.num);
        }
    }

    // Create an object
    MathiJSON *obj = mathison_new_object();
    mathison_set_value(obj, "username", mathison_new_string("macharia"));
    mathison_set_value(obj, "score", mathison_new_number(99));
    mathi_conf_set_object("player", obj);

    // Retrieve and print object
    MathiJSON *retrieved_obj = NULL;
    if (mathi_conf_get_object("player", &retrieved_obj) == 0) 
    {
        MathiJSON *username = NULL;
        MathiJSON *score = NULL;
        mathison_get_value(retrieved_obj, "username", &username);
        mathison_get_value(retrieved_obj, "score", &score);

        printf("Object contents:\n");
        if (username) printf("  username: %s\n", username->data.str);
        if (score) printf("  score: %.2f\n", score->data.num);
    }
}

void test_config_save_and_load()
{
    printf("\nTest: Config - Save & Load...\n");

    const char *file = "test_config.json";
    if (mathi_conf_save(file) == 0) 
        printf("Saved configuration to '%s'\n", file);
    
    // Clear and reload
    mathi_conf_remove_key("app_name");
    mathi_conf_remove_key("max_users");
    mathi_conf_remove_key("debug_mode");
    mathi_conf_remove_key("version");
    mathi_conf_remove_key("my_array");
    mathi_conf_remove_key("player");

    if (mathi_conf_load(file) == 0) 
        printf("Reloaded configuration from '%s'\n", file);

    printf("After reload, app_name = %s\n", mathi_conf_get_string("app_name"));
}

int main() 
{
    test_json_creation_and_types();
    test_config_basic_types();
    test_config_arrays_and_objects();
    test_config_save_and_load();

    printf("\nAll MathiJSON + Config tests completed successfully!\n");
    return 0;
}
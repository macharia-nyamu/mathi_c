#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/mathison.h"

void test_json_creation() {
    printf("Testing JSON creation...\n");

    MathiJSON *obj = json_new_object();
    MathiJSON *arr = json_new_array();
    MathiJSON *str = json_new_string("hello");
    MathiJSON *num = json_new_number(3.14);
    MathiJSON *btrue = json_new_bool(1);
    MathiJSON *bfalse = json_new_bool(0);
    MathiJSON *nullv = json_new_null();

    printf("obj is object? %d\n", json_is_object(obj));
    printf("arr is array? %d\n", json_is_array(arr));
    printf("str is string? %d, value='%s'\n", json_is_string(str), str->data.str);
    printf("num is number? %d, value=%.2f\n", json_is_number(num), num->data.num);
    printf("btrue is bool? %d, value=%d\n", json_is_bool(btrue), btrue->data.boolean);
    printf("bfalse is bool? %d, value=%d\n", json_is_bool(bfalse), bfalse->data.boolean);
    printf("nullv is null? %d\n", json_is_null(nullv));

    assert(json_is_object(obj));
    assert(json_is_array(arr));
    assert(json_is_string(str));
    assert(json_is_number(num));
    assert(json_is_bool(btrue));
    assert(json_is_bool(bfalse));
    assert(json_is_null(nullv));

    json_free(obj);
    json_free(arr);
    json_free(str);
    json_free(num);
    json_free(btrue);
    json_free(bfalse);
    json_free(nullv);
}

void test_json_copy() {
    printf("Testing JSON copy...\n");

    MathiJSON *num = json_new_number(42.0);
    MathiJSON *copy = NULL;

    int code = json_copy(num, &copy);
    printf("json_copy returned code=%d, copy value=%.2f\n", code, copy->data.num);
    assert(code == 0);
    assert(json_is_number(copy));
    assert(copy->data.num == 42.0);

    json_free(num);
    json_free(copy);
}

void test_json_serialize() {
    printf("Testing JSON serialization...\n");

    MathiJSON *str = json_new_string("mathi");
    char *output = NULL;

    int code = json_serialize(str, &output);
    printf("json_serialize returned code=%d, output='%s'\n", code, output);
    assert(code == 0);
    assert(output != NULL);
    assert(strcmp(output, "\"mathi\"") == 0);

    free(output);
    json_free(str);
}

void test_json_array_swap() {
    printf("Testing JSON array swap...\n");

    MathiJSON *arr = json_new_array();
    MathiJSON *a = json_new_number(1.0);
    MathiJSON *b = json_new_number(2.0);

    json_append_array(arr, a);
    json_append_array(arr, b);

    json_swap_array_items(arr, 0, 1);
    printf("Array after swap: %.1f, %.1f\n",
           arr->data.array.items[0]->data.num,
           arr->data.array.items[1]->data.num);
    assert(arr->data.array.items[0]->data.num == 2.0);
    assert(arr->data.array.items[1]->data.num == 1.0);

    json_free(arr); // frees a and b as well
}

void test_json_object_operations() {
    printf("Testing JSON object operations...\n");

    MathiJSON *obj = json_new_object();
    MathiJSON *val = json_new_string("value");

    assert(json_set_value(obj, "key", val) == 0);

    MathiJSON *get_val = NULL;
    assert(json_get_value(obj, "key", &get_val) == 0);
    printf("Object key 'key' value: '%s'\n", get_val->data.str);
    assert(strcmp(get_val->data.str, "value") == 0);

    printf("Has key before removal: %d\n", json_has_key(obj, "key"));
    assert(json_has_key(obj, "key") == true);
    assert(json_remove_key(obj, "key") == 0);
    printf("Has key after removal: %d\n", json_has_key(obj, "key"));
    assert(json_has_key(obj, "key") == false);

    json_free(obj);
}

void test_json_parse() {
    printf("Testing JSON parse (simple values)...\n");

    MathiJSON *jstr = NULL;
    MathiJSON *jnum = NULL;
    MathiJSON *jtrue = NULL;
    MathiJSON *jfalse = NULL;
    MathiJSON *jnull = NULL;

    assert(json_parse("\"hello\"", &jstr) == 0 && json_is_string(jstr));
    printf("Parsed string: '%s'\n", jstr->data.str);
    assert(strcmp(jstr->data.str, "hello") == 0);

    assert(json_parse("123.45", &jnum) == 0 && json_is_number(jnum));
    printf("Parsed number: %.2f\n", jnum->data.num);
    assert(jnum->data.num == 123.45);

    assert(json_parse("true", &jtrue) == 0 && json_is_bool(jtrue));
    printf("Parsed boolean true: %d\n", jtrue->data.boolean);
    assert(jtrue->data.boolean == true);

    assert(json_parse("false", &jfalse) == 0 && json_is_bool(jfalse));
    printf("Parsed boolean false: %d\n", jfalse->data.boolean);
    assert(jfalse->data.boolean == false);

    assert(json_parse("null", &jnull) == 0 && json_is_null(jnull));
    printf("Parsed null: is_null=%d\n", json_is_null(jnull));

    json_free(jstr);
    json_free(jnum);
    json_free(jtrue);
    json_free(jfalse);
    json_free(jnull);
}

int main() {
    test_json_creation();
    test_json_copy();
    test_json_serialize();
    test_json_array_swap();
    test_json_object_operations();
    test_json_parse();

    printf("All mathison tests passed successfully!\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathi/mathison.h"

void test_creation_and_types() 
{
    printf("Test: Creation & Type Checks...\n");

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

void test_strings_and_serialization() 
{
    printf("Test: Strings & Serialization...\n");

    MathiJSON *str = mathison_new_string("Mathi C Library");
    char *out = NULL;

    if (mathison_serialize(str, &out) == 0) 
    {
        printf("Serialized string: %s\n", out);
        free(out);
    }

    printf("Raw string: %s\n", str->data.str);
    mathison_free(str);
}

void test_objects_operations() 
{
    printf("Test: Object Operations...\n");

    MathiJSON *obj = mathison_new_object();
    MathiJSON *val1 = mathison_new_string("value1");
    MathiJSON *val2 = mathison_new_number(42);

    mathison_set_value(obj, "key1", val1);
    mathison_set_value(obj, "key2", val2);

    MathiJSON *retrieved = NULL;
    if (mathison_get_value(obj, "key1", &retrieved) == 0) 
    {
        printf("Object key1 value: %s\n", retrieved->data.str);
    }

    if (mathison_get_value(obj, "key2", &retrieved) == 0) 
    {
        printf("Object key2 value: %.2f\n", retrieved->data.num);
    }

    printf("Has key1? %d\n", mathison_has_key(obj, "key1"));
    mathison_remove_key(obj, "key1");
    printf("Has key1 after removal? %d\n", mathison_has_key(obj, "key1"));

    mathison_free(obj);
}

void test_arrays_and_swaps() 
{
    printf("Test: Array Operations & Swap...\n");

    MathiJSON *arr = mathison_new_array();
    MathiJSON *a = mathison_new_string("first");
    MathiJSON *b = mathison_new_string("second");
    MathiJSON *c = mathison_new_number(3.14);

    mathison_append_array(arr, a);
    mathison_append_array(arr, b);
    mathison_append_array(arr, c);

    printf("Original Array:\n");
    for (size_t i = 0; i < mathison_array_count(arr); i++) 
    {
        MathiJSON *elem = mathison_array_get(arr, i);
        if (mathison_is_string(elem)) printf("  %zu: %s\n", i, elem->data.str);
        if (mathison_is_number(elem)) printf("  %zu: %.2f\n", i, elem->data.num);
    }

    mathison_swap_array_items(arr, 0, 2);
    printf("Array after swap 0 and 2:\n");
    for (size_t i = 0; i < mathison_array_count(arr); i++) 
    {
        MathiJSON *elem = mathison_array_get(arr, i);
        if (mathison_is_string(elem)) printf("  %zu: %s\n", i, elem->data.str);
        if (mathison_is_number(elem)) printf("  %zu: %.2f\n", i, elem->data.num);
    }

    mathison_free(arr);
}

void test_parse_basic() 
{
    printf("Test: Parse Basic JSON...\n");

    MathiJSON *jstr = NULL, *jnum = NULL, *jtrue = NULL, *jfalse = NULL, *jnull = NULL;

    mathison_parse("\"Hello\"", &jstr);
    mathison_parse("123.45", &jnum);
    mathison_parse("true", &jtrue);
    mathison_parse("false", &jfalse);
    mathison_parse("null", &jnull);

    printf("Parsed string: %s\n", jstr->data.str);
    printf("Parsed number: %.2f\n", jnum->data.num);
    printf("Parsed boolean true: %d\n", jtrue->data.boolean);
    printf("Parsed boolean false: %d\n", jfalse->data.boolean);
    printf("Parsed null is null? %d\n", mathison_is_null(jnull));

    mathison_free(jstr);
    mathison_free(jnum);
    mathison_free(jtrue);
    mathison_free(jfalse);
    mathison_free(jnull);
}

int main() 
{
    test_creation_and_types();
    test_strings_and_serialization();
    test_objects_operations();
    test_arrays_and_swaps();
    test_parse_basic();

    printf("\nAll MathiJSON tests completed successfully!\n");
    return 0;
}
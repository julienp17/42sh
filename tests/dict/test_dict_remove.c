/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for dict_remove
*/

#include <criterion/criterion.h>
#include "dict.h"
#include "my.h"

Test(dict_remove, empty_dict)
{
    dict_t *dict = NULL;
    int status = 0;

    status = dict_remove(&dict, "KEY");
    cr_assert_eq(status, -1);
    cr_assert_null(dict);
}

Test(dict_remove, first_and_only_value)
{
    dict_t *dict = NULL;
    int status = 0;

    dict_add(&dict, my_strdup("KEY"), my_strdup("value"));
    status = dict_remove(&dict, "KEY");
    cr_assert_eq(status, 0);
    cr_assert_null(dict);
}

Test(dict_remove, middle_value)
{
    dict_t *dict = NULL;
    int status = 0;

    dict_set(&dict, my_strdup("KEY"), my_strdup("value"));
    dict_set(&dict, my_strdup("HOTEL"), my_strdup("trivago"));
    dict_set(&dict, my_strdup("EMPTY"), NULL);
    status = dict_remove(&dict, "HOTEL");
    cr_assert_eq(status, 0);
    cr_assert_not_null(dict);
    cr_assert_str_eq(dict->key, "KEY");
    cr_assert_str_eq(dict->value, "value");
    cr_assert_not_null(dict->next);
    cr_assert_str_eq(dict->next->key, "EMPTY");
    cr_assert_null(dict->next->value);
    cr_assert_null(dict->next->next);
}

Test(dict_remove, total_remove)
{
    dict_t *dict = NULL;
    int status = 0;

    dict_set(&dict, my_strdup("KEY"), my_strdup("value"));
    dict_set(&dict, my_strdup("HOTEL"), my_strdup("trivago"));
    status = dict_remove(&dict, "KEY");
    cr_assert_eq(status, 0);
    cr_assert_not_null(dict);
    cr_assert_str_eq(dict->key, "HOTEL");
    cr_assert_str_eq(dict->value, "trivago");
    cr_assert_null(dict->next);
    status = dict_remove(&dict, "HOTEL");
    cr_assert_null(dict);
}

Test(dict_remove, last_value)
{
    dict_t *dict = NULL;
    int status = 0;

    dict_add(&dict, my_strdup("KEY"), my_strdup("value"));
    dict_add(&dict, my_strdup("HOTEL"), my_strdup("trivago"));
    dict_add(&dict, my_strdup("EMPTY"), NULL);
    status = dict_remove(&dict, "EMPTY");
    cr_assert_eq(status, 0);
    cr_assert_not_null(dict);
    cr_assert_str_eq(dict->key, "KEY");
    cr_assert_str_eq(dict->value, "value");
    cr_assert_not_null(dict->next);
    cr_assert_str_eq(dict->next->key, "HOTEL");
    cr_assert_str_eq(dict->next->value, "trivago");
    cr_assert_null(dict->next->next);
}
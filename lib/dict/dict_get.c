/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** dict_get
*/

#include <stddef.h>
#include "dict.h"
#include "my.h"

void *dict_get(dict_t *dict, char const *key)
{
    dict_t *current_element = NULL;

    current_element = dict;
    while (current_element && my_strcmp(current_element->key, key) != 0)
        current_element = current_element->next;
    return (current_element == NULL ? NULL : current_element->value);
}
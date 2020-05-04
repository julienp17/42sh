/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Returns true if dictionnary has key, false otherwise
*/

#include <stdbool.h>
#include <stddef.h>
#include "dict.h"
#include "my.h"

bool dict_has_key(dict_t *dict, char const *key)
{
    dict_t *current_element = NULL;

    if (dict == NULL)
        return (false);
    current_element = dict;
    while (current_element && my_strcmp(current_element->key, key) != 0)
        current_element = current_element->next;
    return (current_element != NULL);
}
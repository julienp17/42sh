/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** dict_destroy
*/

#include <stdlib.h>
#include "dict.h"

int dict_clear(dict_t *dict)
{
    dict_t *current_element = NULL;
    dict_t *to_remove = NULL;

    if (dict == NULL)
        return (0);
    while (current_element) {
        to_remove = current_element;
        current_element = current_element->next;
        free(to_remove->key);
        free(to_remove->value);
        free(to_remove);
    }
    return (0);
}
/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Destroys a directory structure
*/

#include <stdlib.h>
#include "dict.h"

void dict_destroy(dict_t *dict)
{
    dict_t *to_remove = NULL;

    while (dict) {
        to_remove = dict;
        dict = dict->next;
        if (to_remove->key)
            free(to_remove->key);
        if (to_remove->value)
            free(to_remove->value);
        free(to_remove);
    }
}
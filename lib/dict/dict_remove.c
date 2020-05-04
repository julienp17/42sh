/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Remove an entry in a dictionnary
*/

#include <stdlib.h>
#include "dict.h"
#include "my.h"

int dict_remove(dict_t **dict, char const *key)
{
    dict_t *previous_element = NULL;
    dict_t *current_element = NULL;

    if ((*dict) == NULL)
        return (-1);
    current_element = (*dict);
    while (current_element && my_strcmp(current_element->key, key) != 0) {
        previous_element = current_element;
        current_element = current_element->next;
    }
    if (current_element == NULL)
        return (-1);
    if (previous_element == NULL)
        (*dict) = (*dict)->next;
    else
        previous_element->next = current_element->next;
    free(current_element->key);
    free(current_element->value);
    free(current_element);
    return (0);
}
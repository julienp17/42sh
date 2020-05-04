/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** dict_to_strarr
*/

#include <stdlib.h>
#include "dict.h"
#include "my.h"

char **dict_to_strarr(dict_t *dict)
{
    dict_t *current_element = NULL;
    char **arr = NULL;
    unsigned int i = 0;

    for (current_element = dict ; current_element ; i++)
        current_element = current_element->next;
    arr = malloc(sizeof(char *) * (i + 1));
    if (arr == NULL) {
        my_puterr("Coudln't allocate memory for dict_to_strarr\n");
        return (NULL);
    }
    i = 0;
    for (current_element = dict ; current_element ; i++) {
        arr[i] = my_strdupcat(current_element->key, "=");
        if (current_element->value)
            arr[i] = my_strdupcat(arr[i], current_element->value);
        current_element = current_element->next;
    }
    arr[i] = NULL;
    return (arr);
}
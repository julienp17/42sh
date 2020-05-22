/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Create a dictionnary from an array of strings
*/

#include <stdlib.h>
#include "dict.h"
#include "my.h"

dict_t *dict_from_strarr(char **str_arr, char const sep)
{
    dict_t *dict = NULL;
    char *key = NULL;
    char *value = NULL;
    unsigned int sep_index = 0;

    for (unsigned int i = 0 ; str_arr && str_arr[i] ; i++) {
        sep_index = my_count_until_sep(str_arr[i], sep);
        value = my_strdup(str_arr[i] + sep_index + 1);
        key = my_strdup(str_arr[i]);
        key[sep_index] = '\0';
        dict_set(&dict, key, value);
    }
    return (dict);
}
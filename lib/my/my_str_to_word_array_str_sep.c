/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static char **parse_to_word_array(char const *str, char const *sep);

static unsigned int my_count_str_sep(char const *str, char const *sep)
{
    unsigned int count = 0;
    unsigned int sep_length = my_strlen(sep) - 1;

    for (unsigned int i = 0; str[i]; i++)
        if (my_strncmp(str + i, sep, sep_length) == 0)
            count = count + 1;
    return (count / 2);
}

static unsigned int my_count_until_str_sep(char const *str, char const *sep)
{
    unsigned int count = 0;
    unsigned int sep_length = my_strlen(sep) - 1;

    for (int i = 0; str[i] && my_strncmp(str + i, sep, sep_length) != 0; i++)
        count++;
    return (count);
}

char **my_str_to_word_array_str_sep(char const *str, char const *sep)
{
    char **arr = NULL;

    arr = parse_to_word_array(str, sep);
    for (unsigned int i = 0 ; arr[i] ; i++)
        arr[i] = my_clean_str(arr[i]);
    my_strarr_remove_empty(arr);
    return (arr);
}

static char **parse_to_word_array(char const *str, char const *sep)
{
    unsigned int nb_rows = my_count_str_sep(str, sep);
    unsigned int nb_cols = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    char **arr = malloc(sizeof(char *) * nb_rows);

    for (i = 0 ; i < nb_rows + 1; i = i + 1, k = k + 1) {
        nb_cols = my_count_until_str_sep(str + k, sep);
        arr[i] = malloc(sizeof(char) * (nb_cols + 1));
        for (j = 0 ; j < nb_cols ; j = j + 1, k = k + 1)
            arr[i][j] = str[k];
        arr[i][j] = '\0';
        k = k + my_strlen(sep) - 1;
    }
    arr[i] = NULL;
    return (arr);
}
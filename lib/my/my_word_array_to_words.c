/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Always further
*/

#include <stdlib.h>
#include "my.h"

char ***my_word_array_to_words(char **arr, char const *sep)
{
    unsigned int nb_rows = my_strarr_count(arr, sep) + 1;
    unsigned int nb_cols = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    char ***words = malloc(sizeof(char **) * (nb_rows + 1));

    for (i = 0 ; i < nb_rows ; i++, k++) {
        nb_cols = my_strarr_count_until_sep(arr + k, sep);
        words[i] = malloc(sizeof(char *) * (nb_cols + 1));
        for (j = 0 ; j < nb_cols ; j++, k++)
            words[i][j] = my_strdup(arr[k]);
        words[i][j] = NULL;
    }
    words[i] = NULL;
    return (words);
}
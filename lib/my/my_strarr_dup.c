/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Duplicate a string array
*/

#include <stdlib.h>

char *my_strdup(char const *src);

char **my_strarr_dup(char **arr)
{
    char **dup_arr = NULL;
    unsigned int i = 0;

    while (arr[i])
        i++;
    dup_arr = malloc(sizeof(char *) * (i + 1));
    for (i = 0 ; arr[i] ; i++)
        dup_arr[i] = my_strdup(arr[i]);
    dup_arr[i] = NULL;
    return (dup_arr);
}
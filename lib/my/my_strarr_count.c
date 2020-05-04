/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strarr_count
*/

#include "my.h"

unsigned int my_strarr_count(char **arr, char const *to_count)
{
    unsigned int count = 0;

    for (unsigned int i = 0 ; arr[i] ; i++)
        if (my_strcmp(arr[i], to_count) == 0)
            count++;
    return (count);
}
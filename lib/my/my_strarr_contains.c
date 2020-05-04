/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strarr_contains
*/

#include <stdbool.h>
#include "my.h"

bool my_strarr_contains(char **arr, char const *str)
{
    for (unsigned int i = 0 ; arr[i] ; i++)
        if (my_strcmp(arr[i], str) == 0)
            return (true);
    return (false);
}
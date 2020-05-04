/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_isalphanum
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"

bool my_str_isalphanum(char const *str)
{
    if (str == NULL || str[0] == '\0')
        return (false);
    for (unsigned int i = 0 ; str[i] ; i++)
        if (!my_is_alpha(str[i]) && !my_is_num(str[i]))
            return (false);
    return (true);
}
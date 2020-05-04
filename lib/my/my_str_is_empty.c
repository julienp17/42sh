/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Returns true if given string is only spaces or empty
*/

#include <stdbool.h>

bool my_str_is_empty(char const *str)
{
    for (unsigned int i = 0 ; str[i] ; i++)
        if (str[i] != ' ')
            return (false);
    return (true);
}
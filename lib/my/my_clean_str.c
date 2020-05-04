/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Returns the given string without duplicate whitespaces
*/

#include <stdbool.h>
#include "my.h"

static bool is_unclean(char const c);

char *my_clean_str(char *str)
{
    int j = 0;

    while (str[0] && is_unclean(str[0]))
        my_str_rotate(str, 0);
    for (int i = my_strlen(str) - 1 ; i > 0 && is_unclean(str[i]) ; i--)
        str[i] = '\0';
    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
        if (i != 0 && is_unclean(str[i]) && is_unclean(str[i - 1]));
        else {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    return (str);
}

static bool is_unclean(char const c)
{
    return (c == ' ' || c == '\t');
}
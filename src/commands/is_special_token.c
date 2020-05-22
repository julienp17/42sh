/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Return true if string is special char, false otherwise
*/

#include <stdbool.h>
#include <stddef.h>
#include "my.h"

bool is_special_char(char const c)
{
    char const special_chars[] = "><;|&";

    for (unsigned int i = 0 ; special_chars[i] ; i++)
        if (special_chars[i] == c)
            return (true);
    return (false);
}

bool is_redirection_token(char const *str)
{
    char const *redirection_tokens[] = {
        ">", "<", ">>", "<<", NULL
    };

    for (unsigned int i = 0 ; redirection_tokens[i] ; i++)
        if (my_strcmp(redirection_tokens[i], str) == 0)
            return (true);
    return (false);
}

bool is_sep_token(char const *str)
{
    char const *sep_tokens[] = {
        "&&", "||", "|", ";", NULL
    };

    for (unsigned int i = 0 ; sep_tokens[i] ; i++)
        if (my_strcmp(sep_tokens[i], str) == 0)
            return (true);
    return (false);
}

bool is_special_token(char const *str)
{
    return (is_redirection_token(str) || is_sep_token(str));
}
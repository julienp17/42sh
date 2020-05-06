/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_char_is_alpha
*/

#include <stdbool.h>

bool my_char_is_alpha(char const c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
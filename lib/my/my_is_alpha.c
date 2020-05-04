/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_is_alpha
*/

#include <stdbool.h>

bool my_is_alpha(char const c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
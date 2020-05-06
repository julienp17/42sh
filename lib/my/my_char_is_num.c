/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_char_is_num
*/

#include <stdbool.h>

bool my_char_is_num(char const c)
{
    return (c >= '0' && c <= '9');
}
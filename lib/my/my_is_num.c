/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_is_num
*/

#include <stdbool.h>

bool my_is_num(char const c)
{
    return (c >= '0' && c <= '9');
}
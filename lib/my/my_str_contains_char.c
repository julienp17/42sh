/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_str_contains_char
*/

#include <stdbool.h>

bool my_str_contains_char(char const *str, char const to_find)
{
    for (unsigned int i = 0 ; str[i] ; i++) {
        if (str[i] == to_find)
            return (true);
    }
    return (false);
}
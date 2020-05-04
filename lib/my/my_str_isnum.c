/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** Returns 1 if the given string is numeric, 0 otherwise
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    unsigned int i = 0;

    if (str[0] == '-' && str[1])
        i = i + 1;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i = i + 1;
    }
    return (true);
}
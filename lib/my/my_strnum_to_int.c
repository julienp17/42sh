/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** Converts a numerical string into an integer
*/

#include <stdbool.h>

int my_strlen(char const *str);

int my_strnum_to_int(char *str)
{
    unsigned int i = 0;
    unsigned int len = my_strlen(str);
    int nb = 0;
    bool is_neg = false;

    if (str[0] == '-') {
        is_neg = true;
        i = i + 1;
    }
    while (i < len) {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (is_neg ? -nb : nb);
}
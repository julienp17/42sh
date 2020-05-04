/*
** EPITECH PROJECT, 2019
** C Pool EvalExpr
** File description:
** Converts an integer into a numerical string
*/

#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include "my.h"

static bool check_is_neg(int *nb);

char *my_int_to_strnum(int nb)
{
    int i = 0;
    bool is_neg = false;
    char *strnum = malloc(sizeof(char) * (my_intlen(nb) + 2));

    if (nb == 0)
        return ("0");
    if (nb == INT_MIN)
        return ("-2147483648");
    is_neg = check_is_neg(&nb);
    for (; nb != 0 ; i = i + 1) {
        strnum[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    if (is_neg)
        strnum[i++] = '-';
    strnum[i] = '\0';
    return (my_revstr(strnum));
}

static bool check_is_neg(int *nb)
{
    if (*nb < 0) {
        *nb = *nb * -1;
        return (true);
    }
    return (false);
}
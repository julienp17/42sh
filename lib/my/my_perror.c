/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Implemntation of perror
*/

#include <string.h>
#include "my.h"

void my_perror(char const *str, char const *opt, int const errnum)
{
    my_puterr(str);
    my_puterr(": ");
    if (opt) {
        my_puterr(opt);
        my_puterr(": ");
    }
    my_puterr(strerror(errnum));
    my_puterr(".\n");
}
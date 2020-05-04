/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Implementation of exit shell builtin
*/

#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "my.h"

int my_exit(int ac, char **av, dict_t *env)
{
    (void)av;
    (void)env;
    if (ac > 2 || (ac == 2 && !my_str_isnum(av[1]))) {
        my_puterr("exit: Expression Syntax.\n");
        return (EXIT_FAILURE);
    }
    if (isatty(0))
        my_putstr("exit\n");
    if (av[1])
        exit(my_strnum_to_int(av[1]));
    exit(0);
}
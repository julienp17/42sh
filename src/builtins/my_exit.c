/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Implementation of exit shell builtin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"

int my_exit(int ac, char **av, shell_t *shell)
{
    if (ac > 2 || (ac == 2 && !my_str_isnum(av[1]))) {
        my_puterr("exit: Expression Syntax.\n");
        return (EXIT_FAILURE);
    }
    shell->exit = true;
    if (av[1])
        return (my_strnum_to_int(av[1]));
    return (0);
}
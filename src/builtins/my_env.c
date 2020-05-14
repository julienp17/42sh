/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Implementation of the environment shell builtin
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

int my_env(int ac, char **av, shell_t *shell)
{
    if (ac > 1) {
        fprintf(stderr, "env: ‘%s‘: No such file or directory\n", av[1]);
        return (EXIT_FAILURE);
    }
    dict_print(shell->env);
    return (EXIT_SUCCESS);
}
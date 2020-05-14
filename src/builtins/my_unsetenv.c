/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Remove an environment variable
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

int my_unsetenv(int ac, char **av, shell_t *shell)
{
    if (ac == 1) {
        my_puterr("unsetenv: Too few arguments.\n");
        return (EXIT_FAILURE);
    }
    for (unsigned int i = 1 ; av[i] ; i++)
        dict_remove(&(shell->env), av[i]);
    return (EXIT_SUCCESS);
}
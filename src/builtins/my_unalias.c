/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Remove an alias
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

int my_unalias(int ac, char **av, shell_t *shell)
{
    if (ac == 1) {
        my_puterr("unalias: Too few arguments.\n");
        return (EXIT_FAILURE);
    }
    for (unsigned int i = 1 ; av[i] ; i++)
        dict_remove(&(shell->alias), av[i]);
    return (EXIT_SUCCESS);
}
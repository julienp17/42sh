/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Remove an environment variable
*/

#include <stdlib.h>
#include "dict.h"
#include "my.h"

int my_unsetenv(int ac, char **av, dict_t *env)
{
    if (ac == 1) {
        my_puterr("unsetenv: Too few arguments.\n");
        return (EXIT_FAILURE);
    }
    for (unsigned int i = 1 ; av[i] ; i++)
        dict_remove(&env, av[i]);
    return (EXIT_SUCCESS);
}
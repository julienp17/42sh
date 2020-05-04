/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Implementation of the environment shell builtin
*/

#include <errno.h>
#include <stdlib.h>
#include "my.h"
#include "dict.h"

static void print_env_error(char *arg);

int my_env(int ac, char **av, dict_t *env)
{
    if (ac > 1) {
        print_env_error(av[1]);
        return (EXIT_FAILURE);
    }
    dict_print(env);
    return (EXIT_SUCCESS);
}

static void print_env_error(char *arg)
{
    my_puterr("env: ‘");
    my_puterr(arg);
    my_puterr("’: No such file or directory\n");
}
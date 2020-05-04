/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Implementation of the change directory shell builtin
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "dict.h"

static char *get_path(int ac, char **av, dict_t *env);
static int change_directory(int ac, char **av, dict_t *env);

int my_cd(int ac, char **av, dict_t *env)
{
    char *cwd = NULL;

    if (ac > 2) {
        my_puterr("cd: Too many arguments.\n");
        return (EXIT_FAILURE);
    }
    cwd = getcwd(NULL, 0);
    if (change_directory(ac, av, env) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (ac == 2 && my_strcmp(av[1], "-") == 0) {
        my_putstr(getcwd(NULL, 0));
        my_putchar('\n');
    }
    dict_set(&env, "PWD", getcwd(NULL, 0));
    dict_set(&env, "OLDPWD", cwd);
    return (EXIT_SUCCESS);
}

static int change_directory(int ac, char **av, dict_t *env)
{
    char *path = NULL;

    path = get_path(ac, av, env);
    if (path == NULL)
        return (EXIT_FAILURE);
    if (chdir(path) == -1) {
        my_perror(path, NULL, errno);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static char *get_path(int ac, char **av, dict_t *env)
{
    char *path = NULL;

    if (ac == 1) {
        path = dict_get(env, "HOME");
        if (path == NULL)
            my_puterr("cd: No home directory.\n");
        return (path);
    }
    if (my_strcmp(av[1], "-") == 0) {
        path = dict_get(env, "OLDPWD");
        if (path == NULL)
            return ("");
    } else {
        path = av[1];
    }
    return (path);
}
/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Set an environment variable
*/

#include <stdlib.h>
#include "dict.h"
#include "my.h"

static bool check_key(char const *key);

int my_setenv(int ac, char **av, dict_t *env)
{
    char *key = NULL;
    char *value = NULL;

    if (ac == 1) {
        dict_print(env);
        return (EXIT_SUCCESS);
    } else if (ac > 3) {
        my_puterr("setenv: Too many arguments.\n");
        return (EXIT_FAILURE);
    }
    key = av[1];
    if (!check_key(key))
        return (EXIT_FAILURE);
    value = (av[2] == NULL) ? NULL : my_strdup(av[2]);
    dict_set(&env, key, value);
    return (EXIT_SUCCESS);
}

static bool check_key(char const *key)
{
    if (!my_char_is_alpha(key[0])) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return (false);
    }
    if (!my_str_isalphanum(key)) {
        my_puterr("setenv: Variable name must contain alphanumeric");
        my_puterr(" characters.\n");
        return (false);
    }
    return (true);
}
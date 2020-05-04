/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for my_env builtin
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include "my.h"

Test(my_env, too_much_arguments, .init = cr_redirect_stderr)
{
    int ac = 2;
    char *av[] = {"env", "a", NULL};
    dict_t *env = NULL;
    int status = 0;

    status = my_env(ac, av, env);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("env: ‘a’: No such file or directory\n");
}

Test(my_env, basic_usage, .init = cr_redirect_stdout)
{
    int ac = 1;
    char *av[] = {"env", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("EDITOR"), my_strdup("vim"));
    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    dict_set(&env, my_strdup("toto"), NULL);
    status = my_env(ac, av, env);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_stdout_eq_str("EDITOR=vim\nUSER=julien\ntoto=\n");
}
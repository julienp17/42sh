/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for my_unsetenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include "my.h"

Test(unsetenv, too_few_arguments, .init = cr_redirect_stderr)
{
    int ac = 1;
    char *av[] = {"unsetenv", NULL};
    dict_t *env = NULL;
    int status = 0;

    status = my_unsetenv(ac, av, env);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("unsetenv: Too few arguments.\n");
}

Test(unsetenv, unknown_key)
{
    int ac = 2;
    char *av[] = {"unsetenv", "toto", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("EDITOR"), my_strdup("vim"));
    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    status = my_unsetenv(ac, av, env);
    cr_assert_eq(status, 0);
    cr_assert_not_null(env);
    cr_assert_str_eq(env->key, "EDITOR");
    cr_assert_str_eq(env->value, "vim");
    cr_assert_not_null(env->next);
    cr_assert_str_eq(env->next->key, "USER");
    cr_assert_str_eq(env->next->value, "julien");
    cr_assert_null(env->next->next);
    dict_destroy(env);
}
/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for my_setenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include "my.h"

Test(my_setenv, too_much_arguments, .init = cr_redirect_stderr)
{
    int ac = 4;
    char *av[] = {"setenv", "toto", "tata", "tutu", NULL};
    dict_t *env = NULL;
    int status = 0;

    status = my_setenv(ac, av, env);
    cr_assert_eq(status, 1);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(my_setenv, no_args, .init = cr_redirect_stdout)
{
    int ac = 1;
    char *av[] = {"setenv", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("EDITOR"), my_strdup("vim"));
    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    dict_set(&env, my_strdup("toto"), NULL);
    status = my_setenv(ac, av, env);
    cr_assert_eq(status, 0);
    cr_assert_stdout_eq_str("EDITOR=vim\nUSER=julien\ntoto=\n");
    dict_destroy(env);
}

Test(my_setenv, no_value, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"setenv", "toto", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    status = my_setenv(ac, av, env);
    cr_assert_eq(status, 0);
    cr_assert_not_null(env->next);
    cr_assert_str_eq(env->next->key, "toto");
    cr_assert_null(env->next->value);
    dict_destroy(env);
}

Test(my_setenv, with_value_not_existing, .init = cr_redirect_stdout)
{
    int ac = 3;
    char *av[] = {"setenv", "toto", "tata", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    status = my_setenv(ac, av, env);
    cr_assert_eq(status, 0);
    cr_assert_not_null(env->next);
    cr_assert_str_eq(env->next->key, "toto");
    cr_assert_str_eq(env->next->value, "tata");
    dict_destroy(env);
}

Test(my_setenv, with_value_existing_with_value, .init = cr_redirect_stdout)
{
    int ac = 3;
    char *av[] = {"setenv", "toto", "tata", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    dict_set(&env, my_strdup("toto"), my_strdup("tutu"));
    status = my_setenv(ac, av, env);
    cr_assert_eq(status, 0);
    cr_assert_not_null(env->next);
    cr_assert_str_eq(env->next->key, "toto");
    cr_assert_str_eq(env->next->value, "tata");
    dict_destroy(env);
}

Test(my_setenv, with_value_existing_without_value, .init = cr_redirect_stdout)
{
    int ac = 3;
    char *av[] = {"setenv", "toto", "tata", NULL};
    dict_t *env = NULL;
    int status = 0;

    dict_set(&env, my_strdup("USER"), my_strdup("julien"));
    dict_set(&env, my_strdup("toto"), NULL);
    status = my_setenv(ac, av, env);
    cr_assert_eq(status, 0);
    cr_assert_not_null(env->next);
    cr_assert_str_eq(env->next->key, "toto");
    cr_assert_str_eq(env->next->value, "tata");
    dict_destroy(env);
}
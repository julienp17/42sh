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
    int status = 0;

    status = my_setenv(ac, av, NULL);
    cr_assert_eq(status, 1);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(my_setenv, no_args, .init = cr_redirect_stdout)
{
    int ac = 1;
    char *av[] = {"setenv", NULL};
    char *env[] = {
        "EDITOR=vim",
        "USER=julien",
        "toto=",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_setenv(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_stdout_eq_str("EDITOR=vim\nUSER=julien\ntoto=\n");
}

Test(my_setenv, no_value, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"setenv", "toto", NULL};
    char *env[] = {
        "USER=julien",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_setenv(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_not_null(shell->env->next);
    cr_assert_str_eq(shell->env->next->key, "toto");
    cr_assert_null(shell->env->next->value);
}

Test(my_setenv, with_value_not_existing, .init = cr_redirect_stdout)
{
    int ac = 3;
    char *av[] = {"setenv", "toto", "tata", NULL};
    char *env[] = {
        "USER=julien",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_setenv(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_not_null(shell->env->next);
    cr_assert_str_eq(shell->env->next->key, "toto");
    cr_assert_str_eq(shell->env->next->value, "tata");
}

Test(my_setenv, with_value_existing_with_value, .init = cr_redirect_stdout)
{
    int ac = 3;
    char *av[] = {"setenv", "toto", "tata", NULL};
    char *env[] = {
        "USER=julien",
        "toto=tutu",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_setenv(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_not_null(shell->env->next);
    cr_assert_str_eq(shell->env->next->key, "toto");
    cr_assert_str_eq(shell->env->next->value, "tata");
}

Test(my_setenv, with_value_existing_without_value, .init = cr_redirect_stdout)
{
    int ac = 3;
    char *av[] = {"setenv", "toto", "tata", NULL};
    char *env[] = {
        "USER=julien",
        "toto=",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_setenv(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_not_null(shell->env->next);
    cr_assert_str_eq(shell->env->next->key, "toto");
    cr_assert_str_eq(shell->env->next->value, "tata");
}
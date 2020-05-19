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
    int status = 0;

    status = my_unsetenv(ac, av, NULL);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("unsetenv: Too few arguments.\n");
}

Test(unsetenv, unknown_key)
{
    int ac = 2;
    char *av[] = {"unsetenv", "toto", NULL};
    char *env[] = {
        "EDITOR=vim",
        "USER=julien",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_unsetenv(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_not_null(shell->env);
    cr_assert_str_eq(shell->env->key, "EDITOR");
    cr_assert_str_eq(shell->env->value, "vim");
    cr_assert_not_null(shell->env->next);
    cr_assert_str_eq(shell->env->next->key, "USER");
    cr_assert_str_eq(shell->env->next->value, "julien");
    cr_assert_null(shell->env->next->next);
}
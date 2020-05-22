/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests to get the right builtin
*/

#include <criterion/criterion.h>
#include "builtins.h"

Test(get_builtin, cd)
{
    char const command[] = "cd";
    int (*builtin)(int, char **, shell_t *) = NULL;

    builtin = get_builtin(command);
    cr_assert_eq(builtin, &my_cd);
}

Test(get_builtin, exit)
{
    char const command[] = "exit";
    int (*builtin)(int, char **, shell_t *) = NULL;

    builtin = get_builtin(command);
    cr_assert_eq(builtin, &my_exit);
}

Test(get_builtin, env)
{
    char const command[] = "env";
    int (*builtin)(int, char **, shell_t *) = NULL;

    builtin = get_builtin(command);
    cr_assert_eq(builtin, &my_env);
}

Test(get_builtin, setenv)
{
    char const command[] = "setenv";
    int (*builtin)(int, char **, shell_t *) = NULL;

    builtin = get_builtin(command);
    cr_assert_eq(builtin, &my_setenv);
}

Test(get_builtin, unsetenv)
{
    char const command[] = "unsetenv";
    int (*builtin)(int, char **, shell_t *) = NULL;

    builtin = get_builtin(command);
    cr_assert_eq(builtin, &my_unsetenv);
}

Test(get_builtin, not_a_builtin)
{
    char const command[] = "ls";
    int (*builtin)(int, char **, shell_t *) = NULL;

    builtin = get_builtin(command);
    cr_assert_null(builtin);
}
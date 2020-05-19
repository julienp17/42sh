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
    int status = 0;

    status = my_env(ac, av, NULL);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("env: ‘a‘: No such file or directory\n");
}

Test(my_env, basic_usage, .init = cr_redirect_stdout)
{
    int ac = 1;
    char *av[] = {"env", NULL};
    char *env[] = {
        "EDITOR=vim",
        "USER=julien",
        "toto=",
        NULL
    };
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(env);
    status = my_env(ac, av, shell);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_stdout_eq_str("EDITOR=vim\nUSER=julien\ntoto=\n");
}
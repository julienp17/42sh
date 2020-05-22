/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for run binary
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "dict.h"
#include "my.h"

Test(run_binary, not_exising_null_env, .init = cr_redirect_stderr)
{
    int ac = 1;
    char *av[] = {"a", NULL};
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(NULL);
    status = run_binary(ac, av, shell);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("a: Command not found.\n");
}

Test(run_binary, echo_hello_null_env, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"echo", "hello", NULL};
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(NULL);
    status = run_binary(ac, av, shell);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_stdout_eq_str("hello\n");
}
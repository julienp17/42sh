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

Test(run_binary, not_exising, .init = cr_redirect_stderr)
{
    int ac = 1;
    char *av[] = {"a", NULL};
    dict_t *env = NULL;
    char key[] = "PATH";
    char value[] = "/usr/bin:/bin";
    int status = 0;

    dict_set(&env, key, my_strdup(value));
    status = run_binary(ac, av, env);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("a: Command not found.\n");
    dict_destroy(env);
}

Test(run_binary, echo_hello, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"echo", "hello", NULL};
    dict_t *env = NULL;
    char key[] = "PATH";
    char value[] = "/usr/bin:/bin";
    int status = 0;

    dict_set(&env, key, my_strdup(value));
    status = run_binary(ac, av, env);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_stdout_eq_str("hello\n");
    dict_destroy(env);
}
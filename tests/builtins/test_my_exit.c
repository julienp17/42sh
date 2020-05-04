/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for my_exit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"

Test(my_exit, too_much_arguments, .init = cr_redirect_stderr)
{
    int ac = 3;
    char *av[] = {"exit", "1", "a", NULL};
    dict_t *env = NULL;
    int status = 0;

    status = my_exit(ac, av, env);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("exit: Expression Syntax.\n");
}

Test(my_exit, incorrect_argument, .init = cr_redirect_stderr)
{
    int ac = 2;
    char *av[] = {"exit", "a", NULL};
    dict_t *env = NULL;
    int status = 0;

    status = my_exit(ac, av, env);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("exit: Expression Syntax.\n");
}
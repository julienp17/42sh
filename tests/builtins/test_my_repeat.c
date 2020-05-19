/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Unit tests for my_repeat
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include "my.h"

Test(my_repeat, normal_execution, .init = cr_redirect_stdout)
{
    int ac = 4;
    char *av[] = {"repeat", "2", "echo", "bonjour", NULL};
    shell_t *shell = NULL;
    char const expected_stdout[] = "bonjour\nbonjour\n";
    int status = 0;

    shell = shell_create(NULL);
    status = my_repeat(ac, av, shell);
    cr_assert_eq(status, EXIT_SUCCESS);
    cr_assert_stdout_eq_str(expected_stdout);
}

Test(my_repeat, only_repeat_as_arg, .init = cr_redirect_stderr)
{
    int ac = 1;
    char *av[] = {"repeat", NULL};
    char const err_msg[] = "repeat: Too few arguments.\n";
    int status = 0;

    status = my_repeat(ac, av, NULL);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str(err_msg);
}

Test(my_repeat, only_repeat_and_nb_as_args, .init = cr_redirect_stderr)
{
    int ac = 2;
    char *av[] = {"repeat", "5", NULL};
    char const err_msg[] = "repeat: Too few arguments.\n";
    int status = 0;

    status = my_repeat(ac, av, NULL);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str(err_msg);
}

Test(my_repeat, only_repeat_and_incorrect_nb_as_args,.init = cr_redirect_stderr)
{
    int ac = 2;
    char *av[] = {"repeat", "a", NULL};
    char const err_msg[] = "repeat: Too few arguments.\n";
    int status = 0;

    status = my_repeat(ac, av, NULL);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str(err_msg);
}

Test(my_repeat, incorrect_nb, .init = cr_redirect_stderr)
{
    int ac = 4;
    char *av[] = {"repeat", "a", "echo", "bonjour", NULL};
    char const err_msg[] = "repeat: Badly formed number.\n";
    int status = 0;

    status = my_repeat(ac, av, NULL);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str(err_msg);
}
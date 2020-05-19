/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Unit tests for my_alais
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include "my.h"

Test(my_alias, normal_alias, .init = cr_redirect_stdout)
{
    int ac = 4;
    char *av[] = {"alias", "ls", "echo", "test", NULL};
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(NULL);
    status = my_alias(ac, av, shell);
    cr_assert_eq(status, EXIT_SUCCESS);
    execute_command("ls", shell);
    cr_assert_stdout_eq_str("test\n");
}

Test(my_alias, no_argument_no_alias)
{
    int ac = 1;
    char *av[] = {"alias", NULL};
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(NULL);
    status = my_alias(ac, av, shell);
    cr_assert_eq(status, EXIT_SUCCESS);
}

Test(my_alias, one_arg_no_value, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"alias", "ls", NULL};
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(NULL);
    status = my_alias(ac, av, shell);
    cr_assert_eq(status, EXIT_SUCCESS);
}

Test(my_alias, too_dangerous, .init = cr_redirect_stderr)
{
    int ac = 3;
    char *av[] = {"alias", "alias", "alias", NULL};
    shell_t *shell = NULL;
    int status = 0;

    shell = shell_create(NULL);
    status = my_alias(ac, av, shell);
    cr_assert_eq(status, EXIT_FAILURE);
    cr_assert_stderr_eq_str("alias: Too dangerous to alias that.\n");
}
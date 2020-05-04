/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Unit tests for reformat_command_line
*/

#include <criterion/criterion.h>
#include "my_shell.h"
#include "my.h"

Test(reformat_command_line, no_need_to_refactor)
{
    char const expected[] = "ls -a";
    char *command_line = "ls -a";

    command_line = reformat_command_line(my_strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_command_line, many_tabs_and_spaces1)
{
    char const expected[] = "ls -a";
    char *command_line = "     \t   ls \t -a   ";

    command_line = reformat_command_line(my_strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_command_line, spaces_before_and_after)
{
    char const expected[] = "ls -a";
    char *command_line = " ls -a ";

    command_line = reformat_command_line(my_strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_command_line, tabs_before_and_after)
{
    char const expected[] = "ls -a";
    char *command_line = "\tls\t-a\t";

    command_line = reformat_command_line(my_strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_command_line, special_characters1)
{
    char const expected[] = "; ; ; ;";
    char *command_line = ";;;;";

    command_line = reformat_command_line(my_strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_command_line, special_characters2)
{
    char const expected[] = "exit 84 | cat /etc/resolv.conf";
    char *command_line = "exit 84|cat /etc/resolv.conf";

    command_line = reformat_command_line(my_strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}
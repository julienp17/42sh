/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Unit tests for reformat_inhibitor
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"
#include "my.h"

Test(reformat_inhibitor, no_need_to_refactor)
{
    char const expected[] = "ls -a";
    char *command_line = "ls -a";

    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, one_backslash)
{
    char const expected[] = "echo tata";
    char *command_line = "echo t\\ata";

    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, spaces_within)
{
    char const expected[] = " echo tata ";
    char *command_line = " echo t\\ata ";

    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, many_backslashs)
{
    char const expected[] = "echo tata";
    char *command_line = "e\\c\\h\\o t\\a\\t\\a";

    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, backslash_first)
{
    char const expected[] = "echo epitech | nice";
    char *command_line = "\\echo epitech | nice";

    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, stdin_one_backslash)
{
    char const expected[] = "echo epitech | nice";
    char *command_line = "echo epitech\\";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, "| nice");
    fclose(f_stdin);
    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, stdin_only_one_backslash)
{
    char const expected[] = " echo epitech | nice";
    char *command_line = "\\";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, "echo epitech | nice");
    fclose(f_stdin);
    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, stdin_no_character)
{
    char const expected[] = "echo t ";
    char *command_line = "echo t\\";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, "\x00a");
    fclose(f_stdin);
    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, stdin_newline)
{
    char const expected[] = "echo t ";
    char *command_line = "echo t\\";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, "\n");
    fclose(f_stdin);
    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, stdin_with_EOF_after)
{
    char const expected[] = "echo t";
    char *command_line = "echo t\\";
    FILE *f_stdin = cr_get_redirected_stdin();

    fclose(f_stdin);
    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}

Test(reformat_inhibitor, stdin_with_only_EOF)
{
    char const expected[] = {0};
    char *command_line = "\\";
    FILE *f_stdin = cr_get_redirected_stdin();

    fclose(f_stdin);
    command_line = reformat_inhibitor(strdup(command_line));
    cr_assert_str_eq(command_line, expected);
}
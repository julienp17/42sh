/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** test_syntax_is_correct
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"

Test(syntax_is_correct, correct_syntax_1)
{
    char const command[] = "ls";
    bool actual = false;
    bool expected = true;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
}

Test(syntax_is_correct, correct_syntax_2)
{
    char const command[] = "cat /dev/random > toto";
    bool actual = false;
    bool expected = true;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
}

Test(syntax_is_correct, correct_syntax_3)
{
    char const command[] = "echo hello";
    bool actual = false;
    bool expected = true;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
}

Test(syntax_is_correct, correct_syntax_4)
{
    char const command[] = "> toto ls";
    bool actual = false;
    bool expected = true;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
}

Test(syntax_is_correct, ambiguous_single_output_redirect_1,
    .init = cr_redirect_stderr)
{
    char const command[] = "ls > toto > tata";
    char const err_msg[] = "Ambiguous output redirect.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}

Test(syntax_is_correct, ambiguous_single_output_redirect_2,
    .init = cr_redirect_stderr)
{
    char const command[] = "ls > toto > tata > tutu";
    char const err_msg[] = "Ambiguous output redirect.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}

Test(syntax_is_correct, ambiguous_single_output_redirect_3,
    .init = cr_redirect_stderr)
{
    char const command[] = "> toto ls > tata";
    char const err_msg[] = "Ambiguous output redirect.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}

Test(syntax_is_correct, ambiguous_single_input_redirect_1,
    .init = cr_redirect_stderr)
{
    char const command[] = "< toto cat < tata";
    char const err_msg[] = "Ambiguous input redirect.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}

Test(syntax_is_correct, ambiguous_single_input_redirect_2,
    .init = cr_redirect_stderr)
{
    char const command[] = "cat < toto < tata";
    char const err_msg[] = "Ambiguous input redirect.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}

Test(syntax_is_correct, ambiguous_single_input_redirect_3,
    .init = cr_redirect_stderr)
{
    char const command[] = "< tutu cat < toto < tata";
    char const err_msg[] = "Ambiguous input redirect.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}

Test(syntax_is_correct, null_pipe_1,
    .init = cr_redirect_stderr)
{
    char const command[] = "ls | ls | ls |";
    char const err_msg[] = "Invalid null command.\n";
    bool actual = false;
    bool expected = false;

    actual = syntax_is_correct(command);
    cr_assert_eq(actual, expected);
    cr_assert_stderr_eq_str(err_msg);
}
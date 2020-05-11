/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for the prompt
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "shell.h"

Test(prompt, ls)
{
    char *command_line = NULL;
    char command[] = "ls";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, command);
    fclose(f_stdin);
    command_line = prompt();
    cr_assert_str_eq(command_line, command);
}

Test(prompt, ls_with_args)
{
    char *command_line = NULL;
    char command[] = "ls -l -Rt";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, command);
    fclose(f_stdin);
    command_line = prompt();
    cr_assert_str_eq(command_line, command);
}

Test(prompt, empty)
{
    char *command_line = NULL;
    char command[] = "";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, command);
    fclose(f_stdin);
    command_line = prompt();
    cr_assert_null(command_line);
}
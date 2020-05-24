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
    shell_t *shell = NULL;
    char command[] = "ls";
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, command);
    fclose(f_stdin);
    shell = shell_create(NULL);
    command_line = prompt(&(shell->history));
    cr_assert_str_eq(command_line, command);
    cr_assert_str_eq(shell->history->line, command);
    cr_assert_null(shell->history->prev);
    cr_assert_null(shell->history->next);
}

Test(prompt, ls_with_args)
{
    char *command_line = NULL;
    char command[] = "ls -l -Rt";
    shell_t *shell = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, command);
    fclose(f_stdin);
    shell = shell_create(NULL);
    command_line = prompt(&(shell->history));
    cr_assert_str_eq(command_line, command);
    cr_assert_str_eq(shell->history->line, command);
    cr_assert_null(shell->history->prev);
    cr_assert_null(shell->history->next);
}

Test(prompt, empty)
{
    char *command_line = NULL;
    char command[] = "";
    shell_t *shell = NULL;
    FILE *f_stdin = cr_get_redirected_stdin();

    fprintf(f_stdin, command);
    fclose(f_stdin);
    shell = shell_create(NULL);
    command_line = prompt(&(shell->history));
    cr_assert_null(command_line);
    cr_assert_null(shell->history);
}
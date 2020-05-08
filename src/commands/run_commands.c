/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Parse the command line into several smaller segments
*/

#include "my_shell.h"
#include "my.h"

static int run_separators(char const *command, dict_t *env);
static int run_and_commands(char const *command, dict_t *env);
static int run_or_commands(char const *command, dict_t *env);
static int run_command(char const *command, dict_t *env);

int run_commands(char const *command_line, dict_t *env)
{
    int status = 0;

    if (my_str_is_empty(command_line))
        return (EXIT_SUCCESS);
    status = run_separators(command_line, env);
    return (status);
}

static int run_separators(char const *command, dict_t *env)
{
    int status = EXIT_SUCCESS;
    char **sep_commands = NULL;

    sep_commands = my_str_to_word_array(command, COMMAND_SEP);
    for (uint i = 0 ; sep_commands[i] ; i++)
        status = run_and_commands(sep_commands[i], env);
    my_strarr_free(sep_commands);
    return (status);
}

static int run_and_commands(char const *command, dict_t *env)
{
    int status = EXIT_SUCCESS;
    char **and_commands = NULL;

    and_commands = my_str_to_word_array_str_sep(command, "&&");
    for (uint i = 0 ; status == EXIT_SUCCESS && and_commands[i] ; i++)
        status = run_or_commands(and_commands[i], env);
    my_strarr_free(and_commands);
    return (status);
}

static int run_or_commands(char const *command, dict_t *env)
{
    int status = EXIT_FAILURE;
    char **or_commands = NULL;

    or_commands = my_str_to_word_array_str_sep(command, "||");
    for (uint i = 0 ; status == EXIT_FAILURE && or_commands[i] ; i++)
        status = run_command(or_commands[i], env);
    my_strarr_free(or_commands);
    return (status);
}

static int run_command(char const *command, dict_t *env)
{
    int status = EXIT_SUCCESS;

    if (my_str_contains_char(command, PIPE_CHAR))
        status = run_pipes(command, env);
    else
        status = execute_command(command, env);
    return (status);
}
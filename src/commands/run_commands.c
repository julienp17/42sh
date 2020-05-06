/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Run a command from the console line interface
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "builtins.h"
#include "dict.h"
#include "my_shell.h"

int run_commands(char const *command_line, dict_t *env)
{
    int status = 0;
    char **commands = NULL;

    if (my_str_is_empty(command_line))
        return (EXIT_SUCCESS);
    commands = parse_command(command_line, COMMAND_SEP);
    for (unsigned int i = 0 ; commands[i] ; i++)
        status = run_command(commands[i], env);
    my_strarr_free(commands);
    return (status);
}

int run_command(char const *command, dict_t *env)
{
    int status = 0;

    if (my_str_is_empty(command))
        return (EXIT_SUCCESS);
    if (my_str_contains_char(command, PIPE_CHAR))
        status = run_pipes(command, env);
    else
        status = execute_command(command, env);
    return (status);
}

int execute_command(char const *command, dict_t *env)
{
    int ac = 0;
    char **av = NULL;
    int (*execute)(int, char **, dict_t *) = NULL;
    int status = 0;

    av = my_str_to_word_array(command, ' ');
    if (syntax_is_correct(av) == false)
        return (EXIT_FAILURE);
    for (ac = 0 ; av[ac] ; ac++);
    execute = get_builtin(av[0]);
    if (execute == NULL)
        execute = &run_binary;
    status = execute(ac, av, env);
    my_strarr_free(av);
    return (status);
}
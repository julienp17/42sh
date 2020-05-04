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

int run_commands(char *command_line, dict_t *env)
{
    int status = 0;
    char **commands = NULL;

    command_line = reformat_command_line(command_line);
    if (command_line == NULL || my_str_is_empty(command_line))
        return ((command_line == NULL) ? EXIT_FAILURE : EXIT_SUCCESS);
    commands = my_str_to_word_array(command_line, COMMAND_SEP);
    if (commands == NULL)
        return (EXIT_FAILURE);
    for (unsigned int i = 0 ; commands[i] ; i++)
        status = run_command(commands[i], env);
    return (status);
}

int run_command(char *command, dict_t *env)
{
    char **args = NULL;
    int status = 0;

    command = my_clean_str(command);
    if (my_str_is_empty(command))
        return (EXIT_SUCCESS);
    args = my_str_to_word_array(command, ' ');
    if (args == NULL || !syntax_is_correct(args))
        return (EXIT_FAILURE);
    if (my_strarr_contains(args, "|"))
        status = run_pipes(args, env);
    else
        status = execute_command(args, env);
    my_free_2d_array(args);
    return (status);
}

int execute_command(char **av, dict_t *env)
{
    int ac = 0;
    int (*execute)(int, char **, dict_t *) = NULL;
    int status = 0;

    for (ac = 0 ; av[ac] ; ac++);
    execute = get_builtin(av[0]);
    if (execute == NULL)
        execute = &run_binary;
    status = execute(ac, av, env);
    return (status);
}
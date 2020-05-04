/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** My shell
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"
#include "dict.h"
#include "my.h"

int my_shell(char **env)
{
    dict_t *dict_env = NULL;
    int status = EXIT_SUCCESS;
    int exit_code = EXIT_SUCCESS;

    dict_env = dict_from_strarr(env, ENV_SEP);
    while (status != MY_EXIT_QUIT) {
        exit_code = status;
        status = my_shell_loop(dict_env);
    }
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    dict_destroy(dict_env);
    return (exit_code);
}

int my_shell_loop(dict_t *env)
{
    char *command_line = NULL;
    int status = 0;

    command_line = prompt();
    if (command_line == NULL)
        return (MY_EXIT_QUIT);
    status = run_commands(command_line, env);
    free(command_line);
    return (status);
}
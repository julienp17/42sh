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
    shell_t *shell = NULL;
    int exit_code = EXIT_SUCCESS;

    shell = shell_create(env);
    if (shell == NULL)
        return (EXIT_FAILURE);
    while (shell->status != MY_EXIT_QUIT) {
        exit_code = shell->status;
        shell->status = my_shell_loop(shell->env);
    }
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    shell_destroy(shell);
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
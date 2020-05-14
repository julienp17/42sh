/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** My shell
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "dict.h"
#include "my.h"

int my_shell(char **env)
{
    shell_t *shell = NULL;
    int exit_code = EXIT_SUCCESS;

    shell = shell_create(env);
    if (shell == NULL)
        return (EXIT_FAILURE);
    while (shell->exit == false)
        shell->status = my_shell_loop(shell);
    if (isatty(STDIN_FILENO))
        my_putstr("exit\n");
    shell_destroy(shell);
    return (exit_code);
}

int my_shell_loop(shell_t *shell)
{
    char *command_line = NULL;
    int status = 0;

    command_line = prompt();
    if (command_line == NULL) {
        shell->exit = true;
        return (shell->status);
    }
    status = run_commands(command_line, shell->env);
    free(command_line);
    return (status);
}
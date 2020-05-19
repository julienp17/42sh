/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Shows the full path of (shell) commands.
*/

#include "builtins.h"

static int print_command_path(char const *command, dict_t *env);

int my_which(int ac, char **av, shell_t *shell)
{
    int status = 0;

    if (ac == 1) {
        fprintf(stderr, "which: Too few arguments.\n");
        return (EXIT_FAILURE);
    }
    for (unsigned int i = 1 ; av[i] ; i++)
        if (print_command_path(av[i], shell->env) == EXIT_FAILURE)
            status = EXIT_FAILURE;
    return (status);
}

static int print_command_path(char const *command, dict_t *env)
{
    char *path = NULL;

    if (get_builtin(command) != NULL) {
        printf("%s: shell built-in command.\n", command);
        return (EXIT_SUCCESS);
    }
    path = get_binary_path(command, env);
    if (path) {
        printf("%s\n", path);
    } else {
        printf("%s: Command not found.\n", command);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
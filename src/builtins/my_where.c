/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Reports all known instances of command
*/

#include "builtins.h"
#include "my.h"

static int print_command_path(char const *command, dict_t *env);

int my_where(int ac, char **av, shell_t *shell)
{
    int status = EXIT_SUCCESS;

    if (ac == 1) {
        fprintf(stderr, "where: Too few arguments.\n");
        return (EXIT_FAILURE);
    }
    for (unsigned int i = 1 ; av[i] ; i++)
        if (print_command_path(av[i], shell->env) == EXIT_FAILURE)
            status = EXIT_FAILURE;
    return (status);
}

static int print_command_path(char const *command, dict_t *env)
{
    int status = EXIT_FAILURE;
    char *current_path = NULL;
    char **paths = NULL;

    if (get_builtin(command) != NULL) {
        printf("%s is a shell built-in\n", command);
        return (EXIT_SUCCESS);
    }
    paths = get_paths(env);
    for (int i = 0 ; paths[i] ; i++) {
        current_path = my_strdupcat(paths[i], "/");
        current_path = my_strdupcat(current_path, command);
        if (access(current_path, X_OK) == 0) {
            printf("%s\n", current_path);
            status = EXIT_SUCCESS;
        }
    }
    return (status);
}
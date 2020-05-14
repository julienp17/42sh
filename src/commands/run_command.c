/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Execute a single command, without 'seps', 'and', 'or' operator
*/

#include "my.h"
#include "builtins.h"
#include "shell.h"

int run_command(char const *command, shell_t *shell)
{
    int status = EXIT_SUCCESS;

    if (my_str_contains_char(command, PIPE_SEP))
        status = run_pipes(command, shell);
    else
        status = execute_command(command, shell);
    return (status);
}

int execute_command(char const *command, shell_t *shell)
{
    int ac = 0;
    char **av = NULL;
    int (*execute)(int, char **, shell_t *) = NULL;
    int status = 0;

    av = my_str_to_word_array(command, ' ');
    if (syntax_is_correct(av) == false)
        return (EXIT_FAILURE);
    for (ac = 0 ; av[ac] ; ac++);
    execute = get_builtin(av[0]);
    if (execute == NULL)
        execute = &run_binary;
    status = execute(ac, av, shell);
    my_strarr_free(av);
    return (status);
}
/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** check_syntax
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "my_shell.h"

static bool redirection_symbols_are_correct(char **args);
static bool pipes_are_correct(char **args);
static bool pipe_is_incorrect(char **args, int i);

bool syntax_is_correct(char **args)
{
    if (!pipes_are_correct(args))
        return (false);
    return (redirection_symbols_are_correct(args));
}

static bool redirection_symbols_are_correct(char **args)
{
    char const *redirect_symbols[] = {
        ">", ">>", "<<", "<", NULL
    };
    unsigned int redirect_count = 0;
    unsigned int nb_args = 0;

    nb_args = my_strarr_len(args);
    for (unsigned int i = 0 ; redirect_symbols[i] ; i++) {
        redirect_count = my_strarr_count(args, redirect_symbols[i]);
        if (redirect_count > 1) {
            my_puterr("Ambiguous ");
            my_puterr((redirect_symbols[i][0] == '>') ? "output" : "input");
            my_puterr(" redirect.\n");
            return (false);
        } else if (my_strcmp(args[nb_args - 1], redirect_symbols[i]) == 0) {
            my_puterr("Missing name for redirect.\n");
            return (false);
        }
    }
    return (true);
}

static bool pipes_are_correct(char **args)
{
    for (int i = 0 ; args[i] ; i++) {
        if (my_strcmp(args[i], "|") == 0 && pipe_is_incorrect(args, i)) {
            my_puterr("Invalid null command.\n");
            return (false);
        }
    }
    return (true);
}

static bool pipe_is_incorrect(char **args, int i)
{
    return (
        i == 0
        || is_special_token(args[i - 1])
        || args[i + 1] == NULL
        || is_special_token(args[i + 1])
    );
}
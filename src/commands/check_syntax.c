/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** check_syntax
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

static bool redirection_symbols_are_correct(char **args);
static bool tokens_are_correct(char **tokens);
static bool token_is_incorrect(char **tokens, int i);

bool syntax_is_correct(char const *command)
{
    char **tokens = NULL;

    tokens = my_str_to_word_array(command, ' ');
    if (tokens_are_correct(tokens) == false)
        return (false);
    if (redirection_symbols_are_correct(tokens) == false)
        return (false);
    my_strarr_free(tokens);
    return (true);
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

static bool tokens_are_correct(char **args)
{
    for (int i = 0 ; args[i] ; i++) {
        if (is_sep_token(args[i]) && token_is_incorrect(args, i)) {
            my_puterr("Invalid null command.\n");
            return (false);
        }
    }
    return (true);
}

static bool token_is_incorrect(char **args, int i)
{
    return (
        i == 0
        || is_special_token(args[i - 1])
        || args[i + 1] == NULL
        || is_special_token(args[i + 1])
    );
}
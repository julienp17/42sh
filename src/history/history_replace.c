/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Substitute a command by its history number
*/

#include "shell.h"
#include "my.h"

static int replace_token(char **token, history_t *history);

int history_replace(char **prompt, history_t *history)
{
    char **tokens = NULL;
    int status = EXIT_SUCCESS;

    if (my_count_char((*prompt), HISTORY_CHAR) == 0)
        return (EXIT_SUCCESS);
    tokens = my_str_to_word_array((*prompt), ' ');
    for (uint i = 0 ; tokens[i] && status == EXIT_SUCCESS ; i++)
        status = replace_token(&(tokens[i]), history);
    if (status == EXIT_SUCCESS) {
        (*prompt) = my_word_array_to_str(tokens, ' ');
        printf("%s\n", (*prompt));
    } else {
        (*prompt)[0] = '\0';
    }
    my_strarr_free(tokens);
    return (status);
}

static int replace_token(char **token, history_t *history)
{
    int nb = 0;
    int i = 1;
    history_t *entry = NULL;

    if ((*token)[0] != HISTORY_CHAR)
        return (EXIT_SUCCESS);
    nb = atoi((*token) + 1);
    if (nb == 0 || !my_str_isnum((*token + 1))) {
        printf("%s: Event not found.\n", (*token + 1));
        return (EXIT_FAILURE);
    }
    if (nb < 0)
        nb = history_len(history) + nb + 1;
    for (entry = history ; entry && i < nb ; entry = entry->next, i++);
    if (entry) {
        (*token) = my_strdup(entry->line);
    } else {
        printf("%s: Event not found.\n", (*token) + 1);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Replace a command by an alias if it is found
*/

#include "shell.h"
#include "my.h"

char *alias_replace(char const *command, dict_t *alias)
{
    char *new_command = NULL;
    char *substitute = NULL;
    char **tokens = NULL;

    tokens = my_str_to_word_array(command, ' ');
    substitute = dict_get(alias, tokens[0]);
    if (substitute == NULL) {
        new_command = my_strdup(command);
    } else {
        tokens[0] = my_strdup(substitute);
        new_command = my_word_array_to_str(tokens, ' ');
    }
    my_strarr_free(tokens);
    return (new_command);
}
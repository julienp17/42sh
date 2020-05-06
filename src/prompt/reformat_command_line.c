/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Reformat the command line to avoid bad tokenzination
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "my_shell.h"

static unsigned int get_expected_len(char const *command_line);
static char *get_reformatted_command_line(char const *command_line,
                                            unsigned int expected_len);
static char *fill_new_cmd(char const *command_line, char *new_command_line);

char *reformat_command_line(char *command_line)
{
    char *new_command_line = NULL;
    unsigned int expected_len = 0;

    command_line = my_clean_str(command_line);
    if (my_str_is_empty(command_line))
        return (command_line);
    expected_len = get_expected_len(command_line);
    if (my_strlen(command_line) == expected_len)
        return (command_line);
    new_command_line = get_reformatted_command_line(command_line, expected_len);
    if (new_command_line == NULL)
        return (NULL);
    new_command_line = my_clean_str(new_command_line);
    return (new_command_line);
}

unsigned int get_expected_len(char const *command_line)
{
    unsigned int expected_len = 0;

    for (unsigned int i = 0 ; command_line[i] ; i++, expected_len++) {
        if (is_special_char(command_line[i])) {
            expected_len += (i != 0 && command_line[i - 1] != ' ');
            expected_len += (command_line[i + 1] == command_line[i]);
            i += (command_line[i] == command_line[i + 1]);
            expected_len += (command_line[i + 1] != ' ');
        }
    }
    return (expected_len);
}

static char *get_reformatted_command_line(char const *command_line,
                                            unsigned int expected_len)
{
    char *new_command_line = NULL;

    new_command_line = malloc(sizeof(char) * (expected_len + 1));
    if (new_command_line == NULL) {
        my_puterr("Couldn't allocate memory for reformatted command line.\n");
        return (NULL);
    }
    new_command_line[expected_len] = '\0';
    new_command_line = fill_new_cmd(command_line, new_command_line);
    return (new_command_line);
}

static char *fill_new_cmd(char const *command_line, char *new_command_line)
{
    unsigned int j = 0;

    for (unsigned int i = 0 ; command_line[i] ; i++, j++) {
        if (is_special_char(command_line[i])) {
            if (i != 0 && command_line[i - 1] != ' ')
                new_command_line[j++] = ' ';
            new_command_line[j] = command_line[i];
            if (command_line[i] == command_line[i + 1]) {
                i++;
                new_command_line[++j] = command_line[i];
            }
            if (command_line[i + 1] != ' ')
                new_command_line[++j] = ' ';
        } else {
            new_command_line[j] = command_line[i];
        }
    }
    return (new_command_line);
}
/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** reformat_inhibitor_found_in_command_line
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"
#include "get_next_line.h"

static char *str_inhibit(char *prompt);
static char *get_user_input(char *prompt);

static bool is_inhibitor(char *prompt)
{
    int i = 0;

    for (i = 0; prompt[i]; i++)
        if (prompt[i] == '\\')
            return (true);
    return (false);
}

char *reformat_inhibitor(char *prompt)
{
    int i = 0;

    for (i = 0; prompt[i] != '\\' && prompt[i]; i++);
    if (prompt[i] == '\\' && prompt[i + 1] != 0)
        prompt = str_inhibit(prompt);
    else if (prompt[i] == '\\' && prompt[i + 1] == 0)
        prompt = get_user_input(prompt);
    if (is_inhibitor(prompt) == true)
        prompt = reformat_inhibitor(prompt);
    return (prompt);
}

static char *get_user_input(char * prompt)
{
    char *str = NULL;
    int i = 0;

    write(1, "? ", 2);
    str = get_next_line(STDIN_FILENO);
    if (str == NULL)
        return (str_inhibit(prompt));
    for (i = 0; prompt[i] != '\\' && prompt[i]; i++);
    prompt[i] = ' ';
    my_strcat(prompt, str);
    return (prompt);
}

static char *str_inhibit(char *prompt)
{
    int i = 0;

    for (i = 0; prompt[i] != '\\' && prompt[i]; i++);
    for (i++; prompt[i]; i++)
        prompt[i - 1] = prompt[i];
    prompt[i - 1] = 0;
    return (prompt);
}
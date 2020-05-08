/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Displays the prompt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_shell.h"
#include "get_next_line.h"

static void display_prompt(void);

char *prompt(void)
{
    char *prompt = NULL;

    if (isatty(STDIN_FILENO))
        display_prompt();
    prompt = get_next_line(STDIN_FILENO);
    if (prompt == NULL)
        return (NULL);
    prompt = reformat_command_line(prompt);
    return (prompt);
}

static void display_prompt(void)
{
    char *current_dir = NULL;

    current_dir = getcwd(NULL, 0);
    if (current_dir == NULL) {
        my_puterr("Couldn't get current directory.\n");
        exit(84);
    }
    printf("\x1b[1;33m[42sh] \x1b[38;5;27m[%s] \x1b[32m$\x1b[0m ", current_dir);
    fflush(stdout);
    free(current_dir);
}
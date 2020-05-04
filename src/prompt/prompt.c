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
#include "get_next_line.h"

static void display_prompt(void);

char *prompt(void)
{
    if (isatty(STDIN_FILENO))
        display_prompt();
    return (get_next_line(STDIN_FILENO));
}

static void display_prompt(void)
{
    char *current_dir = NULL;

    current_dir = getcwd(NULL, 0);
    if (current_dir == NULL) {
        my_puterr("Couldn't get current directory.\n");
        exit(84);
    }
    my_putstr("\x1b[1;33m[my_sh] \x1b[38;5;27m[");
    my_putstr(current_dir);
    my_putstr("] \x1b[32m$\x1b[0m ");
    free(current_dir);
}
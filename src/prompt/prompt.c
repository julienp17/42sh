/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Displays the prompt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "shell.h"
#include "get_next_line.h"

static void display_prompt(void);
static void add_to_history(history_t **history, char const *prompt);

char *prompt(history_t **history)
{
    char *prompt = NULL;

    if (isatty(STDIN_FILENO))
        display_prompt();
    prompt = get_next_line(STDIN_FILENO);
    if (prompt == NULL)
        return (NULL);
    prompt = reformat_command_line(prompt);
    if (!my_str_is_empty(prompt))
        add_to_history(history, my_strdup(prompt));
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

static void add_to_history(history_t **history, char const *prompt)
{
    time_t cur_time;
    char *timestamp = NULL;

    cur_time = time(NULL);
    timestamp = ctime(&cur_time);
    if (timestamp == NULL) {
        my_puterr("42sh: Couldn't get file timestamp.\n");
        return;
    }
    timestamp += 11;
    timestamp[5] = '\0';
    history_push(history, my_strdup(prompt), timestamp);
}
/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Redirect a stream
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "shell.h"
#include "get_next_line.h"
#include "my.h"

static int get_redirection_index(char **args);
static int redirect_output(char **args, int index);
static int redirect_input(char **args, int index);

int redirect(char **args)
{
    int index = 0;
    int (*redirect_fun)(char **, int) = NULL;
    int status = 0;

    index = get_redirection_index(args);
    if (index < 0)
        return (-1);
    redirect_fun = (args[index][0] == '>') ? &redirect_output : &redirect_input;
    status = redirect_fun(args, index);
    my_strarr_rotate(args, index);
    my_strarr_rotate(args, index);
    return (status);
}

static int redirect_output(char **args, int index)
{
    int o_flags = O_CREAT | O_WRONLY;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int redirect_fd = 0;
    int status = EXIT_SUCCESS;

    if (my_strcmp(args[index], ">") == 0)
        o_flags |= O_TRUNC;
    else if (my_strcmp(args[index], ">>") == 0)
        o_flags |= O_APPEND;
    redirect_fd = open(args[index + 1], o_flags, mode);
    if (redirect_fd < 0 || dup2(redirect_fd, STDOUT_FILENO) < 0) {
        perror((redirect_fd < 0) ? "open" : "dup");
        status = EXIT_FAILURE;
    }
    return (status);
}

static int redirect_input(char **args, int index)
{
    int redirect_fd = 0;
    int status = EXIT_SUCCESS;

    if (my_strcmp(args[index], "<") == 0) {
        redirect_fd = open(args[index + 1], O_RDONLY);
        if (redirect_fd < 0 || dup2(redirect_fd, STDIN_FILENO) < 0) {
            perror((redirect_fd < 0) ? args[index + 1] : "dup");
            status = EXIT_FAILURE;
        }
    } else if (my_strcmp(args[index], "<<") == 0) {
        status = redirect_here_document(args[index + 1]);
    }
    return (status);
}

static int get_redirection_index(char **args)
{
    char const *redirect_symbols[] = {
        ">", ">>", "<<", "<", NULL
    };

    for (unsigned int i = 0 ; args[i] ; i++)
        for (unsigned int j = 0 ; redirect_symbols[j] ; j++)
            if (my_strcmp(args[i], redirect_symbols[j]) == 0)
                return (i);
    return (-1);
}
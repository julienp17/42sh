/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Redirect as in a here document
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "my_shell.h"
#include "get_next_line.h"

static int prompt_child(char const *here, int pipefd[2]);
static int prompt_line(char const *here, int pipe_write, bool *should_continue);
static int parent_wait_here(pid_t child_pid, int pipefd[2]);

int redirect_here_document(char const *here)
{
    int pipefd[2] = {0, 0};
    pid_t pid = 0;
    int status = 0;

    if (pipe(pipefd) < 0) {
        perror("pipe");
        return (EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return (EXIT_FAILURE);
    } else if (pid == 0) {
        prompt_child(here, pipefd);
    } else {
        status = parent_wait_here(pid, pipefd);
    }
    return (status);
}

static int prompt_child(char const *here, int pipefd[2])
{
    int status = EXIT_SUCCESS;
    bool should_continue = true;

    if (close(pipefd[READ]) < 0) {
        perror("close");
        status = EXIT_FAILURE;
    }
    while (status == EXIT_SUCCESS && should_continue)
        status = prompt_line(here, pipefd[WRITE], &should_continue);
    if (close(pipefd[WRITE]) < 0) {
        perror("close");
        status = EXIT_FAILURE;
    }
    _exit(status);
}

static int prompt_line(char const *here, int pipe_write, bool *should_continue)
{
    char *line = "";
    int status = EXIT_SUCCESS;

    my_putstr(HERE_DOC_PROMPT);
    line = get_next_line(STDIN_FILENO);
    (*should_continue) = (line != NULL && my_strcmp(line, here) != 0);
    if ((*should_continue) && write(pipe_write, line, my_strlen(line)) < 0) {
        perror("write");
        status = EXIT_FAILURE;
    }
    free(line);
    if ((*should_continue) && write(pipe_write, "\n", 1) < 0) {
        perror("write");
        status = EXIT_FAILURE;
    }
    return (status);
}

static int parent_wait_here(pid_t child_pid, int pipefd[2])
{
    int status = 0;

    if (close(pipefd[WRITE]) < 0) {
        perror("close");
        status = EXIT_FAILURE;
    }
    status = wait_parent(child_pid);
    if (status == EXIT_FAILURE)
        return (EXIT_FAILURE);
    if (dup2(pipefd[READ], STDIN_FILENO) < 0) {
        perror("dup");
        return (EXIT_FAILURE);
    }
    return (status);
}
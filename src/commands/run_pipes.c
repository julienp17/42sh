/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Run commands with pipes
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "dict.h"
#include "my.h"
#include "builtins.h"
#include "my_shell.h"

static int execute_pipes(char ***commands, dict_t *env);
static int execute_piped(char ***commands, int i, dict_t *env, int pipe_fd[4]);
static int redirect_io(char ***commands, int i, int pipe_fd[4]);
static int swap_pipes_parent(char ***commands, int i, int pipe_fd[4]);

int run_pipes(char **command_tokens, dict_t *env)
{
    char ***commands = NULL;
    int status = 0;

    commands = my_word_array_to_words(command_tokens, "|");
    if (commands == NULL)
        return (EXIT_FAILURE);
    status = execute_pipes(commands, env);
    my_free_3d_array(commands);
    return (status);
}

static int execute_pipes(char ***commands, dict_t *env)
{
    int pipe_fd[4] = {0, 0, 0, 0};
    int status = EXIT_SUCCESS;
    int i = 0;

    for (i = 0 ; status == EXIT_SUCCESS && commands[i] ; i++)
        status = execute_piped(commands, i, env, pipe_fd);
    while (i > 0 && status != -1) {
        if (wait(&status) < 0) {
            perror("wait");
            status = -1;
        }
        i--;
    }
    return (status);
}

static int execute_piped(char ***commands, int i, dict_t *env, int pipe_fd[4])
{
    pid_t pid = 0;
    int status = 0;

    if (commands[i + 1] != NULL && pipe(pipe_fd + 2) < 0) {
        perror("pipe");
        return (EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return (EXIT_FAILURE);
    } else if (pid == 0) {
        if (redirect_io(commands, i, pipe_fd) == EXIT_FAILURE)
            _exit(EXIT_FAILURE);
        _exit(execute_command(commands[i], env));
    }
    status = swap_pipes_parent(commands, i, pipe_fd);
    return (status);
}

static int redirect_io(char ***commands, int i, int pipe_fd[4])
{
    if (i != 0) {
        if (dup2(pipe_fd[READ], STDIN_FILENO) < 0) {
            perror("dup2");
            return (EXIT_FAILURE);
        }
        if (close(pipe_fd[READ]) < 0 || close(pipe_fd[WRITE]) < 0) {
            perror("close");
            return (EXIT_FAILURE);
        }
    }
    if (commands[i + 1] != NULL) {
        if (dup2(pipe_fd[2 + WRITE], STDOUT_FILENO) < 0) {
            perror("dup2");
            return (EXIT_FAILURE);
        }
        if (close(pipe_fd[2 + READ]) < 0 || close(pipe_fd[2 + WRITE]) < 0) {
            perror("close");
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

static int swap_pipes_parent(char ***commands, int i, int pipe_fd[4])
{
    if (i != 0) {
        if (close(pipe_fd[READ]) < 0 || close(pipe_fd[WRITE]) < 0) {
            perror("close");
            return (EXIT_FAILURE);
        }
    }
    if (commands[i + 1] != NULL) {
        pipe_fd[READ]  = pipe_fd[2 + READ];
        pipe_fd[WRITE] = pipe_fd[2 + WRITE];
    }
    return (EXIT_SUCCESS);
}
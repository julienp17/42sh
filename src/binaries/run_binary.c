/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Executes a binary file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "dict.h"
#include "my.h"
#include "shell.h"

static int execute_binary(char **args, dict_t *env);

int run_binary(int ac, char **av, dict_t *env)
{
    char *binary = NULL;
    int status = 0;

    (void)ac;
    binary = get_binary_path(av[0], env);
    if (binary == NULL) {
        my_puterr(av[0]);
        my_puterr(": Command not found.\n");
        return (EXIT_FAILURE);
    }
    av[0] = my_strdup(binary);
    free(binary);
    status = execute_binary(av, env);
    return (status);
}

static int execute_binary(char **args, dict_t *env)
{
    pid_t pid = 0;
    int status = 0;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return (EXIT_FAILURE);
    } else if (pid == 0) {
        execute_child(args, env);
    } else {
        status = wait_parent(pid);
    }
    return (status);
}

void execute_child(char **args, dict_t *env)
{
    char **env_arr = NULL;

    if (redirect(args) == EXIT_FAILURE)
        _exit(EXIT_FAILURE);
    env_arr = dict_to_strarr(env);
    execve(args[0], args, env_arr);
    if (errno == ENOEXEC) {
        my_puterr(args[0]);
        my_puterr(": Exec format error. Wrong Architecture.\n");
    } else if (errno == EACCES) {
        my_puterr(args[0]);
        my_puterr(": Permission denied.\n");
    } else {
        perror(args[0]);
    }
    my_strarr_free(env_arr);
    _exit(EXIT_FAILURE);
}

int wait_parent(pid_t child_pid)
{
    int status = 0;

    do {
        if (waitpid(child_pid, &status, WUNTRACED) == -1) {
            perror("waitpid");
            return (EXIT_FAILURE);
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            my_puterr("Segmentation fault");
        else if (WTERMSIG(status) == SIGFPE)
            my_puterr("Floating exception");
        my_puterr("\n");
        return (status);
    }
    return (WEXITSTATUS(status));
}
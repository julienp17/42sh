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

int run_binary(int ac, char **av, shell_t *shell)
{
    pid_t pid = 0;
    int status = 0;

    (void)ac;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        return (EXIT_FAILURE);
    } else if (pid == 0) {
        execute_child(av, shell->env);
    } else {
        status = wait_parent(pid);
    }
    return (status);
}

void execute_child(char **av, dict_t *env)
{
    char **env_arr = NULL;
    char *binary_path = NULL;

    if (redirect(av) == EXIT_FAILURE)
        _exit(EXIT_FAILURE);
    binary_path = get_binary_path(av[0], env);
    if (binary_path == NULL) {
        fprintf(stderr, "%s: Command not found.\n", av[0]);
        _exit(EXIT_FAILURE);
    }
    env_arr = dict_to_strarr(env);
    execve(binary_path, av, env_arr);
    if (errno == ENOEXEC)
        fprintf(stderr, "%s: Exec format error. Wrong Architecture.\n", av[0]);
    else if (errno == EACCES)
        fprintf(stderr, "%s: Permission denied.\n", av[0]);
    else
        perror(av[0]);
    free(binary_path);
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
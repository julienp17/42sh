/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Header file for shell builtins functions prototype
*/

#ifndef SHELL_BUILTINS_H_
    #define SHELL_BUILTINS_H_

    #include <stdbool.h>
    #include "shell.h"

    typedef struct builtin {
        char *name;
        int (*command)(int ac, char **av, shell_t *shell);
    } builtin_t;

    int (*get_builtin(char const *command))(int, char **, shell_t *);

    int my_cd(int ac, char **av, shell_t *shell);
    int my_exit(int ac, char **av, shell_t *shell);
    int my_env(int ac, char **av, shell_t *shell);
    int my_setenv(int ac, char **av, shell_t *shell);
    int my_unsetenv(int ac, char **av, shell_t *shell);
    int my_alias(int ac, char **av, shell_t *alias);
#endif
/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Header file for shell builtins functions prototype
*/

#ifndef SHELL_BUILTINS_H_
    #define SHELL_BUILTINS_H_

    #include <stdbool.h>
    #include "dict.h"

    typedef struct builtin {
        char *name;
        int (*command)(int ac, char **av, dict_t *env);
    } builtin_t;

    bool is_builtin(char const *command);
    int (*get_builtin(char const *command))(int, char **, dict_t *);

    int my_cd(int ac, char **av, dict_t *env);
    int my_exit(int ac, char **av, dict_t *env);
    int my_env(int ac, char **av, dict_t *env);
    int my_setenv(int ac, char **av, dict_t *env);
    int my_unsetenv(int ac, char **av, dict_t *env);
#endif
/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Returns true if command is a shell builtin, false otherwise
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "builtins.h"

int (*get_builtin(char const *command))(int, char **, shell_t *)
{
    int (*builtin)(int, char **, shell_t *) = NULL;
    builtin_t builtins[] = {
        {"cd", &my_cd}, {"exit", &my_exit},
        {"env", &my_env}, {"setenv", &my_setenv}, {"unsetenv", &my_unsetenv},
        {"", NULL}
    };

    for (unsigned int i = 0 ; builtins[i].command && builtin == NULL ; i++)
        if (my_strcmp(builtins[i].name, command) == 0)
            builtin = builtins[i].command;
    return (builtin);
}
/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Free a shell structure
*/

#include "shell.h"

void shell_destroy(shell_t *shell)
{
    dict_destroy(shell->env);
    dict_destroy(shell->alias);
    free(shell);
}
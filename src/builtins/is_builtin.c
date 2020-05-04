/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Returns true if the given command is a builtin, false otherwise
*/

#include <stdbool.h>
#include <stdlib.h>
#include "builtins.h"

bool is_builtin(char const *command)
{
    return (get_builtin(command) != NULL);
}
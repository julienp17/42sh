/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Returns a newly allocated shell structure
*/

#include "my.h"
#include "shell.h"

shell_t *shell_create(char **env)
{
    shell_t *shell = NULL;

    shell = malloc(sizeof(shell_t));
    if (shell == NULL) {
        my_puterr("Couldn't allocate memory for shell structure.\n");
        return (NULL);
    }
    shell->status = EXIT_SUCCESS;
    shell->env = dict_from_strarr(env, ENV_SEP);
    shell->alias = NULL;
    return (shell);
}
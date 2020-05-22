/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_term_from_env
*/

#include "shell.h"
#include "my.h"

char *get_term_from_env(dict_t *env)
{
    char *term = dict_get(env, "SHELL");

    if (term == NULL) {
        my_puterr("Couldn't get TERM from env.\n");
    }
    return term;
}
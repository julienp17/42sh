/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** Returns the full path of the given binary
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "dict.h"
#include "my.h"
#include "shell.h"

static bool is_relative_path(char const *command);
static char **get_paths(dict_t *env);

char *get_binary_path(char const *command, dict_t *env)
{
    char *current_path = "";
    char **paths = NULL;

    if (is_relative_path(command))
        return (access(command, X_OK) == 0 ? my_strdup(command) : NULL);
    paths = get_paths(env);
    if (paths == NULL)
        return (NULL);
    for (int i = 0 ; paths[i] && access(current_path, X_OK) != 0 ; i++) {
        current_path = my_strdupcat(paths[i], "/");
        current_path = my_strdupcat(current_path, command);
    }
    my_strarr_free(paths);
    return (access(current_path, X_OK) == 0 ? current_path : NULL);
}

static bool is_relative_path(char const *command)
{
    return (
        command[0] == '/'
        || (command[0] == '.' && command[1] == '/')
        || (command[0] == '.' && command[1] == '.' && command[2] == '/')
    );
}

static char **get_paths(dict_t *env)
{
    char *path = NULL;
    char **paths = NULL;

    if (env == NULL) {
        path = my_strdup(DEFAULT_PATH);
    } else {
        path = dict_get(env, "PATH");
        if (path)
            path = my_strdup(path);
        else
            path = my_strdup(DEFAULT_PATH);
    }
    paths = my_str_to_word_array(path, PATH_SEP);
    free(path);
    return (paths);
}
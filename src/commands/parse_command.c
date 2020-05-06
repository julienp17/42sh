/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Returns the arguments of a command
*/

#include <stdlib.h>
#include "my.h"

char **parse_command(char const *command, char const sep)
{
    char **args = NULL;

    args = my_str_to_word_array(command, sep);
    for (unsigned int i = 0 ; args[i] ; i++)
        args[i] = my_clean_str(args[i]);
    my_strarr_remove_empty(args);
    return (args);
}
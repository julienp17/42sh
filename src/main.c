/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Main file for minishell1
*/

#include <stdlib.h>
#include "shell.h"
#include "my.h"

int main(int ac, char **av, char **env)
{
    int status = 0;

    (void)ac;
    (void)av;
    status = my_shell(env);
    return (status);
}
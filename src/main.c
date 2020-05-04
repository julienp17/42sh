/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Main file for minishell1
*/

#include <stdlib.h>
#include "my_shell.h"
#include "my.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    my_shell(env);
    return (0);
}
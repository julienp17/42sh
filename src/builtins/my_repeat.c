/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Repeat a command multiple times
*/

#include "shell.h"
#include "my.h"

int my_repeat(int ac, char **av, shell_t *shell)
{
    char *command = NULL;
    int nb_repeat = 0;
    int status = 0;

    if (ac < 3) {
        fprintf(stderr, "repeat: Too few arguments.\n");
        return (EXIT_FAILURE);
    } else if (my_str_isnum(av[1]) == false) {
        fprintf(stderr, "repeat: Badly formed number.\n");
        return (EXIT_FAILURE);
    }
    nb_repeat = atoi(av[1]);
    command = my_word_array_to_str(av + 2, ' ');
    for (int i = 0 ; i < nb_repeat ; i++)
        status = run_command(command, shell);
    free(command);
    return (status);
}
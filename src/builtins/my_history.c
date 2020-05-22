/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Print the history
*/

#include "builtins.h"
#include "my.h"

static void print_history(history_t *history, int nb);

int my_history(int ac, char **av, shell_t *shell)
{
    int nb = 0;

    if (ac == 1) {
        print_history(shell->history, -1);
    } else if (ac == 2) {
        if (!my_str_isnum(av[1])) {
            printf("history: Badly formed number.\n");
            return (EXIT_FAILURE);
        }
        nb = atoi(av[1]);
        if (nb < 0) {
            printf("history: Number must be positive.\n");
            return (EXIT_FAILURE);
        }
        print_history(shell->history, nb);
    } else {
        printf("history: Too many arguments.");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static void print_history(history_t *history, int nb)
{
    history_t *cur_entry = NULL;
    unsigned int len = 0;
    unsigned int i = 1;

    cur_entry = history;
    len = history_len(history);
    if (nb < 0)
        nb = (int)len;
    else if (nb == 0)
        nb = 1;
    if (nb < (int)len) {
        while (i < len - nb + 1) {
            i++;
            cur_entry = cur_entry->next;
        }
    }
    while (cur_entry) {
        printf("%5d  %s   %s\n", i, cur_entry->timestamp, cur_entry->line);
        i++;
        cur_entry = cur_entry->next;
    }
}
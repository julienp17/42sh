/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Set an alias
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"

static void print_alias(dict_t *alias);

int my_alias(int ac, char **av, shell_t *shell)
{
    char *key = NULL;
    char *value = NULL;

    if (ac == 1) {
        print_alias(shell->alias);
        return (EXIT_SUCCESS);
    } else if (ac == 2) {
        key = av[1];
        value = dict_get(shell->alias, key);
        if (value)
            printf("%s\n", value);
    } else {
        key = av[1];
        value = my_word_array_to_str(av + 2, ' ');
        dict_set(&(shell->alias), key, value);
    }
    return (EXIT_SUCCESS);
}

static void print_alias(dict_t *alias)
{
    dict_t *current = NULL;

    current = alias;
    while (current) {
        printf("%s\t", (char *)current->key);
        if (my_count_char(current->value, ' ') > 0)
            printf("(");
        printf("%s", (char *)current->value);
        if (my_count_char(current->value, ' ') > 0)
                printf(")");
        printf("\n");
        current = current->next;
    }
}
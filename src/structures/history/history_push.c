/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Push a new command at the end of history
*/

#include <stdlib.h>
#include "history.h"

void history_push(history_t **head, char *line, char *timestamp)
{
    history_t *new_entry = NULL;
    history_t *current_entry = NULL;

    new_entry = malloc(sizeof(*new_entry));
    new_entry->line = line;
    new_entry->timestamp = timestamp;
    new_entry->prev = NULL;
    new_entry->next = NULL;
    if ((*head) == NULL)
        (*head) = new_entry;
    else {
        current_entry = (*head);
        while (current_entry->next != NULL)
            current_entry = current_entry->next;
        new_entry->prev = current_entry;
        current_entry->next = new_entry;
    }
}

unsigned int history_len(history_t *head)
{
    unsigned int len = 0;
    history_t *cur_entry = NULL;

    for (cur_entry = head ; cur_entry ; cur_entry = cur_entry->next, len++);
    return (len);
}
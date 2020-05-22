/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** dll
*/

#ifndef DOUBLE_LINKED_LIST_H_
    #define DOUBLE_LINKED_LIST_H_

    typedef struct history {
        char *line;
        char *timestamp;
        struct history *prev;
        struct history *next;
    } history_t;

    void history_push(history_t **head, char *line, char *timestamp);
    unsigned int history_len(history_t *head);
#endif
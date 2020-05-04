/*
** EPITECH PROJECT, 2020
** Dictionnary data structure
** File description:
** Print every element of a directory
*/

#include <stddef.h>
#include "dict.h"
#include "my.h"

void dict_print(dict_t *dict)
{
    dict_t *current_element = NULL;

    current_element = dict;
    while (current_element) {
        my_putstr(current_element->key);
        my_putchar('=');
        if (current_element->value)
            my_putstr(current_element->value);
        my_putchar('\n');
        current_element = current_element->next;
    }
}
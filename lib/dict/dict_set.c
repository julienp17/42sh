/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Modify an existing value, or add if it doesn't exist
*/

#include <stdlib.h>
#include "dict.h"
#include "my.h"

static int dict_modify(dict_t *dict, char const *key, void *value);
static int dict_add(dict_t **dict, char const *key, void *value);
static dict_t *dict_create_entry(char *key, void *value);

int dict_set(dict_t **dict, char const *key, void *value)
{
    if (dict_has_key((*dict), key))
        return (dict_modify((*dict), key, value));
    return (dict_add(dict, key, value));
}

static int dict_modify(dict_t *dict, char const *key, void *value)
{
    dict_t *current_element = NULL;

    if (dict == NULL)
        return (-1);
    current_element = dict;
    while (current_element && my_strcmp(current_element->key, key) != 0)
        current_element = current_element->next;
    current_element->value = value;
    return (0);
}

static int dict_add(dict_t **dict, char const *key, void *value)
{
    dict_t *new_element = NULL;
    dict_t *current_element = NULL;

    new_element = dict_create_entry(my_strdup(key), value);
    if (new_element == NULL)
        return (-1);
    if ((*dict) == NULL) {
        (*dict) = new_element;
    } else {
        current_element = (*dict);
        while (current_element->next != NULL)
            current_element = current_element->next;
        current_element->next = new_element;
    }
    return (0);
}

static dict_t *dict_create_entry(char *key, void *value)
{
    dict_t *dict_entry = NULL;

    dict_entry = malloc(sizeof(dict_t));
    if (dict_entry == NULL) {
        my_puterr("dict: Couldn't allocate memory for new element.\n");
        return (NULL);
    }
    dict_entry->key = key;
    dict_entry->value = value;
    dict_entry->next = NULL;
    return (dict_entry);
}


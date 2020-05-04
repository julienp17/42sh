/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Dict data structure
*/

#ifndef DICT_H_
    #define DICT_H_

    #include <stdbool.h>

    typedef struct dictionary {
        char *key;
        void *value;
        struct dictionary *next;
    } dict_t;

    void dict_destroy(dict_t *dict);
    dict_t *dict_from_strarr(char **str_arr, char const sep);
    char **dict_to_strarr(dict_t *dict);

    void *dict_get(dict_t *dict, char const *key);
    int dict_set(dict_t **dict, char const *key, void *value);

    int dict_clear(dict_t *dict);
    void dict_print(dict_t *dict);
    bool dict_has_key(dict_t *dict, char const *key);
    int dict_remove(dict_t **dict, char const *key);
#endif
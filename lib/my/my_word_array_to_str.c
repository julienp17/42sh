/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** my_word_array_to_str
*/

#include <stdlib.h>
#include "my.h"

char *my_word_array_to_str(char **arr, char const sep)
{
    unsigned int i = 0;
    unsigned int len = 0;
    char *str = NULL;

    for (i = 0 ; arr[i] ; i++)
        len += my_strlen(arr[i]);
    str = malloc(sizeof(char) * (len + i + 1));
    if (str == NULL) {
        my_puterr("Coudn't allocate memory for my_word_array_to_str.\n");
        return (NULL);
    }
    str[0] = '\0';
    len = 0;
    for (i = 0 ; arr[i] ; i++) {
        str = my_strcat(str, arr[i]);
        len += my_strlen(arr[i]);
        if (arr[i + 1] != NULL) {
            str[len + i] = sep;
            str[len + i + 1] = '\0';
        }
    }
    return (str);
}
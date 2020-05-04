/*
** EPITECH PROJECT, 2019
** C Pool Day 08
** File description:
** Duplicates a string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    unsigned int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

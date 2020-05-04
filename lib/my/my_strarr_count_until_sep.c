/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Count the number of characters in an array of strings until sep is found
*/

#include "my.h"

unsigned int my_strarr_count_until_sep(char **str_arr, char const *sep)
{
    unsigned int count = 0;

    for (unsigned int i = 0 ; str_arr[i] && my_strcmp(str_arr[i], sep)!= 0; i++)
        count++;
    return (count);
}
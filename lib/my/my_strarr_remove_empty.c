/*
** EPITECH PROJECT, 2020
** Remove all empty lines in a string array
** File description:
** my_str_arr_remove_empty
*/

#include "my.h"

void my_strarr_remove_empty(char **arr)
{
    for (int i = 0 ; arr[i] ; i++)
        if (my_str_is_empty(arr[i]))
            my_strarr_rotate(arr, i--);
}
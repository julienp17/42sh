/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_free_2d_array
*/

#include <stdlib.h>

void my_free_2d_array(char **arr)
{
    for (unsigned int i = 0 ; arr[i] ; i++)
        free(arr[i]);
    free(arr);
}
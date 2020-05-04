/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_free_3d_array
*/

#include <stdlib.h>

void my_free_3d_array(char ***arr)
{
    for (unsigned int i = 0 ; arr[i] ; i++) {
        for (unsigned int j = 0 ; arr[i][j] ; j++)
            free(arr[i][j]);
        free(arr[i]);
    }
    free(arr);
}
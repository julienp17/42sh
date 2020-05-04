/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    unsigned int i = 0;

    dest[0] = '\0';
    for (i = 0 ; src[i] ; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
/*
** EPITECH PROJECT, 2020
** asm
** File description:
** my_str_rotate
*/

void my_str_rotate(char *str, int index)
{
    for (int i = index ; str[i] ; i++)
        str[i] = str[i + 1];
}
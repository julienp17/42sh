/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** Print a string to standard output.
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    for (int i = 0 ; str[i] ; i = i + 1)
        my_putchar(str[i]);
}

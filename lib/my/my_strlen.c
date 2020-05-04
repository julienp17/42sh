/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_strlen
*/

unsigned int my_strlen(char const *str)
{
    unsigned int len = 0;

    while (str[len])
        len++;
    return (len);
}
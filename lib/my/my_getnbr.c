/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int is_neg = 0;

    while (str[0] == ' ')
        str++;
    if (str[0] == '-') {
        is_neg = 1;
        str++;
    }
    while (str[0] && (str[0] >= '0' && str[0] <= '9')) {
        nb = nb * 10 + str[0] - '0';
        str++;
    }
    return (is_neg ? -nb : nb);
}
/*
** EPITECH PROJECT, 2019
** C Pool Day 06
** File description:
** Checks if two strings are identical on n
*/

int my_strncmp(char const *s1, char const *s2, unsigned int n)
{
    unsigned int i = 0;

    while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i = i + 1;
    if (s1[i] && !s2[i])
        return (1);
    else if (!s1[i] && s2[i])
        return (-1);
    return (s1[i] - s2[i]);
}

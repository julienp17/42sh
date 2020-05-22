/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** line_formating
*/

#include <curses.h>
#include "line_formating.h"
#include "shell.h"
#include "my.h"

//static char *add_char_to_str(char *str, char c);
//static char *remove_char_to_str(char *str);

char *line_formating(int prompt_size)
{
    int key = 0;
    char *command_line = NULL;

    prompt_size = prompt_size;
    while ((key = getchar()) > 0) {
        if (key == ENTER_KEY)
            return command_line;
        if (key == DEL_KEY) {
            //remove_char_to_str(command_line);
            my_putstr("\b \b");
        }
        else {
            //command_line = add_char_to_str(command_line, key);
            my_putchar(key);
        }
    }
    return NULL;
}

/*static char *add_char_to_str(char *str, char c)
{
    char *new_str = NULL;
    int i = 0;

    if (str == NULL) {
        new_str = malloc(sizeof(char));
    }
    while (str[i]) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = c;
    new_str[i + 1] = '\0';
    return new_str;
}*/

/*static char *remove_char_to_str(char *str)
{
    int size = my_strlen(str);
    char *new_str = NULL;

    if (size == 0)
        return NULL;
    new_str = malloc(sizeof(char) * size);
    for (int i = 0; str[i + 1]; i++)
        new_str[i] = str[i];
    return new_str;
}*/

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

static char *add_char_to_str(char *str, char c);
static char *remove_char_to_str(char *str);
static void display_command_line(char *str);

char *line_formating(void)
{
    int key = 0;
    char *command_line = NULL;

    while ((key = getchar()) > 0) {
        if (key == ENTER_KEY) {
            my_putchar('\n');
            return command_line;
        }
        if (key == DEL_KEY && my_strlen(command_line) >= 1) {
            my_putstr("\b \b");
            command_line = remove_char_to_str(command_line);
        }
        else if (key != DEL_KEY) {
            command_line = add_char_to_str(command_line, key);
            display_command_line(command_line);
        }
    }
    return NULL;
}

static char *add_char_to_str(char *str, char c)
{
    char *new_str = NULL;
    int i = 0;

    if (str == NULL) {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = c;
        new_str[1] = '\0';
        return new_str;
    }
    new_str = malloc(sizeof(char) * my_strlen(str) + 2);
    while (str[i]) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = c;
    new_str[i + 1] = '\0';
    return new_str;
}

static char *remove_char_to_str(char *str)
{
    int size = my_strlen(str);
    char *new_str = NULL;

    if (size == 0)
        return NULL;
    new_str = malloc(sizeof(char) * size);
    for (int i = 0; str[i + 1]; i++)
        new_str[i] = str[i];
    if (my_strlen(str) == 0)
        return NULL;
    return new_str;
}

static void display_command_line(char *str)
{
    int size = my_strlen(str);

    for (int i = 1; i < size; i++)
        my_putstr("\b \b");
    my_putstr(str);
}
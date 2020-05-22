/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** line_formating
*/

#include <termios.h>
#include <curses.h>
#include "dict.h"

#ifndef LINE_FORMATING_H_
#define LINE_FORMATING_H_

#define DEL_KEY 127
#define ENTER_KEY 13

typedef struct terminal
{
    char *term_path;
    SCREEN *new_term;
    struct termios termios;
}terminal_t;

terminal_t get_termios_infos(dict_t *env);
char *get_term_from_env(dict_t *env);
char *line_formating(void);

#endif /* !LINE_FORMATING_H_ */

/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** line_formating
*/

#include <curses.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "line_formating.h"
#include "dict.h"

terminal_t get_termios_infos(dict_t *env)
{
    struct termios termios_p;
    terminal_t term;

    if (tcgetattr(STDIN_FILENO, &termios_p) < 0) {
        my_puterr("Couldn't get termios.\n");
        exit(84);
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &termios_p);
    term.termios = termios_p;
    term.term_path = get_term_from_env(env);
    term.termios.c_lflag &= ~(ICANON | ECHO);
    term.termios.c_cc[VTIME] = 0;
    term.termios.c_cc[VMIN] = 1;
    term.new_term = newterm(NULL, stdin, stdout);
    return term;
}

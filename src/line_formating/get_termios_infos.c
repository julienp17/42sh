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

struct termios get_termios_infos(void)
{
    struct termios termios_p;

    if (tcgetattr(STDOUT_FILENO, &termios_p) < 0) {
        my_puterr("Couldn't get termios.\n");
        exit(84);
    }
    return termios_p;
}

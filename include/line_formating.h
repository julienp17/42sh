/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** line_formating
*/

#include <termios.h>
#include "dict.h"

#ifndef LINE_FORMATING_H_
#define LINE_FORMATING_H_

struct termios get_termios_infos(void);
char *get_term_from_env(dict_t *env);

#endif /* !LINE_FORMATING_H_ */

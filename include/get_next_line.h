/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** Header file for get_next_line
*/

#ifndef GET_NEXT_LINE_H_
    #define GET_NEXT_LINE_H_

    #ifndef READ_SIZE
        #define READ_SIZE   (42)
    #endif

    typedef struct buffer {
        char *buf;
        unsigned int offset;
        _Bool line_found;
    } buffer_t;

    char *get_next_line(int fd);
    buffer_t *get_buffer(char **ret);
    char *read_next_line(int fd, buffer_t *buffer);
    char *my_realloc_str(char *str, unsigned int size_alloc);
#endif
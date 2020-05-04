/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** Returns the next line in a file
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

char *get_next_line(int fd)
{
    static char *ret = NULL;
    buffer_t *buffer = NULL;
    char *line = NULL;
    unsigned int i = 0;

    if (fd < 0 || !(buffer = get_buffer(&ret)))
        return (NULL);
    for (i = 0 ; buffer->buf[i] && buffer->buf[i] != '\n' ; i++);
    buffer->line_found = (buffer->buf[i] == '\n');
    line = read_next_line(fd, buffer);
    for (i = 0 ; line && line[i] ;) {
        if (line[i] == '\n') {
            ret = my_strcpy(ret, &line[i + 1]);
            line[i] = '\0';
        } else
            i++;
    }
    free(buffer);
    return (line);
}

buffer_t *get_buffer(char **ret)
{
    buffer_t *buffer = NULL;

    if ((*ret) == NULL) {
        if (((*ret) = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
            return (NULL);
        (*ret)[0] = 0;
    }
    if ((buffer = malloc(sizeof(buffer_t))) == NULL ||
            (buffer->buf = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
        return (NULL);
    buffer->buf[0] = 0;
    if (*ret) {
        for (buffer->offset = 0 ; (*ret)[buffer->offset] ; buffer->offset++);
        buffer->buf = my_realloc_str(buffer->buf, buffer->offset + READ_SIZE);
        buffer->buf = my_strcpy(buffer->buf, *ret);
        (*ret)[0] = '\0';
    }
    return (buffer);
}

char *read_next_line(int fd, buffer_t *buffer)
{
    ssize_t bytes_read = 0;
    unsigned int i = 0;

    while (!(buffer->line_found)) {
        bytes_read = read(fd, buffer->buf + buffer->offset, READ_SIZE);
        buffer->offset += (bytes_read != - 1) ? bytes_read : 0;
        buffer->buf[buffer->offset] = '\0';
        for (i = 0 ; buffer->buf[i] && buffer->buf[i] != '\n'; i++);
        buffer->line_found = (buffer->buf[i] == '\n');
        if ((bytes_read != 0 && bytes_read < READ_SIZE)
                || (bytes_read == 0 && buffer->buf[0] != '\0'))
            return (buffer->buf);
        else if (bytes_read <= 0)
            return (NULL);
        if (!(buffer->line_found) && !(buffer->buf = my_realloc_str(
                                    buffer->buf,buffer->offset + READ_SIZE)))
            return (NULL);
    }
    return (buffer->buf);
}

char *my_realloc_str(char *str, unsigned int size_alloc)
{
    char *tmp = NULL;
    unsigned int len = 0;

    for (len = 0 ; str[len] ; len++);
    if ((tmp = malloc(sizeof(char) * (len + 1))) == NULL)
        return (NULL);
    tmp[0] = '\0';
    tmp = my_strcpy(tmp, str);
    free(str);
    if ((str = malloc(sizeof(char) * (size_alloc + 1))) == NULL)
        return (NULL);
    str[0] = '\0';
    str = my_strcpy(str, tmp);
    free(tmp);
    return (str);
}
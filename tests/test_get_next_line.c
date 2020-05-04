/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** Unit tests for get next line
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int fd = -1;

void open_file(void)
{
    fd = open("tests/get_next_line_test_file.txt", O_RDONLY);
    cr_redirect_stdout ();
}

void close_file(void)
{
    if (fd != -1)
        close(fd);
}

Test(get_next_line, read_line, .init = open_file, .fini = close_file)
{
    char *expected = "Confidence  is so  overrated.";
    char *actual = get_next_line(fd);

    cr_assert_str_eq(actual, expected);
}

Test(get_next_line, read_lines, .init = open_file, .fini = close_file)
{
    char *expected = "Confidence  is so  overrated.";
    char *actual = get_next_line(fd);

    cr_assert_str_eq(actual, expected);
    expected = "It's when we're most";
    actual = get_next_line(fd);
    cr_assert_str_eq(actual, expected);
}

Test(get_next_line, bad_fd)
{
    int bad_fd = open("not_existing", O_RDONLY);
    char *actual = get_next_line(bad_fd);

    cr_assert_null(actual);
}
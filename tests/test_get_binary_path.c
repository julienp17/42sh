/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** test_get_binary_path
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "my.h"

Test(get_binary_path, null_env)
{
    char const command[] = "ls";
    dict_t *env = NULL;
    char *path = NULL;

    path = get_binary_path(command, env);
    cr_assert_not_null(path);
    cr_assert_str_eq(path, "/bin/ls");
}

Test(get_binary_path, tmp_path)
{
    char const command[] = "ls";
    dict_t *env = NULL;
    char *path = NULL;

    dict_set(&env, "PATH", my_strdup("/tmp"));
    path = get_binary_path(command, env);
    cr_assert_null(path);
}

Test(get_binary_path, direct_path)
{
    char const command[] = "/bin/ls";
    dict_t *env = NULL;
    char *path = NULL;

    dict_set(&env, "PATH", my_strdup("/tmp"));
    path = get_binary_path(command, env);
    cr_assert_not_null(path);
    cr_assert_str_eq(path, "/bin/ls");
}
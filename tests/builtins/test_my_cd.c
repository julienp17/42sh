/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Unit tests for my cd builtin
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "builtins.h"
#include "my.h"

Test(my_cd, no_args)
{
    int ac = 1;
    char *av[] = {"cd", NULL};
    shell_t *shell = NULL;
    int status = 0;
    char *cwd = NULL;
    char *old_cwd = NULL;

    shell = shell_create(NULL);
    old_cwd = getcwd(NULL, 0);
    dict_set(&(shell->env), my_strdup("HOME"), old_cwd);
    dict_set(&(shell->env), my_strdup("PWD"), my_strdupcat(old_cwd, "/src"));
    dict_set(&(shell->env), my_strdup("OLDPWD"), old_cwd);
    status = my_cd(ac, av, shell);
    cr_assert_eq(status, 0);
    cwd = getcwd(NULL, 0);
    cr_assert_str_eq(dict_get(shell->env, "HOME"), old_cwd);
    cr_assert_str_eq(dict_get(shell->env, "HOME"), cwd);
    cr_assert_str_eq(dict_get(shell->env, "PWD"), dict_get(shell->env, "HOME"));
    cr_assert_str_eq(dict_get(shell->env, "PWD"), getcwd(NULL, 0));
    cr_assert_str_eq(dict_get(shell->env, "OLDPWD"), old_cwd);
}

Test(my_cd, hyphen, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"cd", "-", NULL};
    shell_t *shell = NULL;
    int status = 0;
    char *cwd = NULL;
    char *old_cwd = NULL;

    shell = shell_create(NULL);
    old_cwd = getcwd(NULL, 0);
    cwd = my_strdupcat(old_cwd, "/src");
    dict_set(&(shell->env), my_strdup("PWD"), old_cwd);
    dict_set(&(shell->env), my_strdup("OLDPWD"), cwd);
    status = my_cd(ac, av, shell);
    cr_assert_eq(status, 0);
    cr_assert_stdout_eq_str(my_strdupcat(cwd, "\n"));
    cr_assert_str_eq(cwd, getcwd(NULL, 0));
    cr_assert_str_eq(cwd, dict_get(shell->env, "PWD"));
    cr_assert_str_eq(old_cwd, dict_get(shell->env, "OLDPWD"));
}

Test(my_cd, too_many_arguments, .init = cr_redirect_stderr)
{
    int ac = 3;
    char *av[] = {"cd", "a", "b", NULL};
    int status = 0;

    status = my_cd(ac, av, NULL);
    cr_assert_stderr_eq_str("cd: Too many arguments.\n");
    cr_assert_eq(status, 1);
}

Test(my_cd, path_not_existing, .init = cr_redirect_stderr)
{
    int ac = 2;
    char *av[] = {"cd", "I don't exist", NULL};
    shell_t *shell = NULL;
    int status = 0;
    char *cwd = NULL;

    shell = shell_create(NULL);
    cwd = getcwd(NULL, 0);
    dict_set(&(shell->env), "PWD", cwd);
    dict_set(&(shell->env), "OLDPWD", my_strdup("/home/julien"));
    status = my_cd(ac, av, shell);
    cr_assert_eq(status, 1);
    cr_assert_stderr_eq_str("I don't exist: No such file or directory.\n");
    cr_assert_str_eq(dict_get(shell->env, "PWD"), cwd);
    cr_assert_str_eq(dict_get(shell->env, "OLDPWD"), "/home/julien");
    free(cwd);
}
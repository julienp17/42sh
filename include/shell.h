/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** Header file for my shell
*/

#ifndef MY_SH_H_
    #define MY_SH_H_

    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include "dict.h"

    #define MY_EXIT_ERROR          -84
    #define MY_EXIT_QUIT           92
    #define COMMAND_SEP            ';'
    #define ENV_SEP                '='
    #define PATH_SEP               ':'
    #define PIPE_SEP               '|'
    #define AND_SEP                "&&"
    #define OR_SEP                 "||"
    #define DEFAULT_PATH           "/bin:/usr/bin"
    #define HERE_DOC_PROMPT        "? "

    typedef unsigned int uint;

    typedef struct shell {
        int status;
        dict_t *env;
        dict_t *alias;
        bool exit;
    } shell_t;

    shell_t *shell_create(char **env);
    void shell_destroy(shell_t *shell);

    enum PIPE_END {READ, WRITE};

    int my_shell(char **env);
    int my_shell_loop(shell_t *shell);

    char *prompt(void);
    char *reformat_command_line(char *command_line);

    bool syntax_is_correct(char **args);
    bool is_special_char(char const c);
    bool is_special_token(char const *str);

    int run_command(char const *command, shell_t *shell);
    int run_commands(char const *command_line, shell_t *shell);
    int run_pipes(char const *command, shell_t *shell);
    int execute_command(char const *command, shell_t *shell);

    int run_binary(int ac, char **av, shell_t *shell);
    char *get_binary_path(char *command, dict_t *env);
    void execute_child(char **args, dict_t *env);
    int wait_parent(pid_t child_pid);

    int redirect(char **args);
    int redirect_here_document(char const *here);
#endif
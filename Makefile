##
## EPITECH PROJECT, 2020
## PSU_my_ls_2019
## File description:
## Makefile
##

CC			=	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
MAIN_F		=	main.c
OBJ_M		=	$(MAIN:.c=.o)

SRC			=	$(addprefix $(SRC_D), $(SRC_F))
OBJ			=	$(SRC:.c=.o)
SRC_D		=	src/
SRC_F		=	my_shell.c \
				alias/alias_replace.c \
				file_control/get_next_line.c \
				binaries/run_binary.c \
				binaries/get_binary_path.c \
				builtins/get_builtin.c \
				builtins/my_cd.c \
				builtins/my_exit.c \
				builtins/my_env.c \
				builtins/my_setenv.c \
				builtins/my_unsetenv.c \
				builtins/my_alias.c \
				builtins/my_unalias.c \
				builtins/my_repeat.c \
				builtins/my_which.c \
				commands/is_special_token.c \
				commands/check_syntax.c \
				commands/run_commands.c \
				commands/run_command.c \
				pipes/run_pipes.c \
				prompt/prompt.c \
				prompt/reformat_command_line.c \
				redirection/redirect.c \
				redirection/redirect_here_document.c \
				structures/shell/shell_create.c \
				structures/shell/shell_destroy.c \

SRC_UT		=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT		=	$(SRC_UT:.c=.o)
SRC_UT_D	=	tests/
SRC_UT_F	=	test_prompt.c \
				test_get_next_line.c \
				test_run_binary.c \
				test_get_binary_path.c \
				test_syntax_is_correct.c \
				test_reformat_command_line.c \
				builtins/test_get_builtin.c \
				builtins/test_my_cd.c \
				builtins/test_my_exit.c \
				builtins/test_my_env.c \
				builtins/test_my_setenv.c \
				builtins/test_my_unsetenv.c \
				builtins/test_my_alias.c \
				builtins/test_my_repeat.c \

INC			=	-I./include

CFLAGS		=	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS)

LDFLAGS		=	-L./lib -lmy -ldict

LDFLAGS_UT  =	-lcriterion --coverage

DBFLAGS		=	-g -g3 -ggdb

NAME		=	42sh

NAME_UT		=	unit_tests

all: $(NAME)

$(NAME): makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS)

tests_run: makelib clean $(SRC) $(OBJ_UT)
	$(CC) -o $(NAME_UT) $(SRC) $(OBJ_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)

makelib:
	make -C ./lib/my all
	make -C ./lib/dict all

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my fclean

re: fclean all

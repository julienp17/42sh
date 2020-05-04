##
## EPITECH PROJECT, 2019
## my_rpg
## File description:
## Libdict Makefile
##

CC 			= 	gcc

SRC			=	dict_clear.c \
				dict_get.c \
				dict_has_key.c \
				dict_remove.c \
				dict_set.c \
				dict_print.c \
				dict_destroy.c \
				dict_from_strarr.c \
				dict_to_strarr.c \

OBJ			=	$(SRC:.c=.o)

INC 		=	-I../my/

CFLAGS		=	-W -Wall -Wextra -Werror -L../ -lmy $(INC) $(LDFLAGS)

LDFLAGS		=	-L../ -lmy

DBFLAGS		=	-g -g3 -ggdb

HEADER		=	dict.h

NAME		=	libdict.a

all:		make_libmy $(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

make_libmy:
	make -C ../my/ all

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean

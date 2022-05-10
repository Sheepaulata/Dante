##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME_GEN	= generateur/generateur

SRC 	=	sources/main.c \
			sources/my_put.c \
			sources/my_getnbr.c \
			sources/imperfect_maze.c 	\
			sources/perfect_maze.c	\
			sources/print_maze.c \
			sources/error.c 	\
			sources/create_maze.c	\

CFLAGS	=	-Wall -Wshadow -Wextra -I include

OBJ		= 	$(SRC:.c=.o)

NAME 	= 	generator

all:		$(NAME)

$(NAME): 	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all
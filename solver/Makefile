##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC 	=	sources/main.c \
			sources/my_put.c \
			sources/my_getnbr.c \
			sources/solver_algo.c 	\
			sources/solve_map.c	\
			sources/map_params.c \
			sources/len.c 	\
			sources/map.c	\
			sources/map_reader.c 	\

CFLAGS	=	-Wall -Wshadow -Wextra -I include -lm

OBJ		= 	$(SRC:.c=.o)

NAME 	= 	solver

all:		$(NAME)

$(NAME): 	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all
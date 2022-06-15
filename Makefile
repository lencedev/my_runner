##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CC		=	gcc
CFLAGS	=	-I./
LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRC		=	$(wildcard *.c) \
			$(wildcard menu/*.c) \
			$(wildcard lvl/*.c) \
			$(wildcard ennemis/*.c) \
			$(wildcard music/*.c) \
			$(wildcard pause/*.c) \
			$(wildcard layers/*.c)

OBJ		=	$(SRC:.c=.o)
NAME	=	my_runner

all: 	$(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
		@echo "OK!"

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: fclean \
	all

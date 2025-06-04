##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Write a makefile for MiniShell1
##

SRC =	$(addprefix src/, main.c		\
		parse/parsing.c					\
		parse/parse_doors.c				\
		parse/parse_rooms.c				\
		path_finding/move_bots.c		\
		path_finding/compute_dist.c		\
		init_graph/create_graph.c		\
		init_graph/create_robots.c)		\

OBJ = $(SRC:.c=.o)

CPPFLAGS = -iquote ./include/ -Ilib

CFLAGS = -Wall -Wextra -pedantic

LDLIBS = -lmy

LDFLAGS = -L lib/

NAME = amazed

all:	build_lib $(NAME)

build_lib:
	$(MAKE) -C lib/my/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)  $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean: clean_lib
	$(RM) $(OBJ)

clean_lib:
	$(MAKE) -C lib/my/ clean

fclean: clean fclean_lib
	$(RM) $(NAME)

fclean_lib:
	$(MAKE) -C lib/my/ fclean

re_lib:
	$(MAKE) -C lib/my re

re: fclean re_lib all

.PHONY: all build_lib cleann clean_lib fclean re_lib re

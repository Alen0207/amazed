##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## task01
##

SRC	=	$(addprefix str/, my_putchar.c				\
		my_putstr.c			 						\
		my_revstr.c									\
		my_strcapitalize.c							\
		my_strcat.c									\
		my_strcmp.c									\
		my_strcpy.c									\
		my_strdup.c									\
		my_strendcmp.c								\
		my_strlen.c									\
		my_strlowcase.c								\
		my_strncat.c								\
		my_strncmp.c								\
		my_strncpy.c								\
		my_strstr.c									\
		my_strupcase.c)								\
		$(addprefix nbr/, my_alphanum.c				\
		my_compute_power_rec.c						\
		my_compute_square_root.c					\
		my_getnbr.c									\
		my_is_float.c								\
		my_is_nbr.c									\
		my_is_prime.c								\
		my_put_nbr.c								\
		my_rev_nbr.c)								\
		$(addprefix array/, my_show_word_array.c	\
		my_str_to_word_array.c)						\
		$(addprefix dprintf/, my_dprint.c			\
		print_function.c)							\


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME_H	=	my.h

CPPFLAGS	=	-iquote ./include/

CFLAGS	=	 -Wall -Wextra -pedantic


all: $(NAME)

$(NAME):	$(OBJ)
		$(AR) rc $(NAME) $(OBJ)
		mv $(NAME) ../
		cp include/$(NAME_H) ../

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re

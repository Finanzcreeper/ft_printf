CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MAKEFLAGS = --no-print-directory
SRC = ft_printf.c ft_transformer.c
NAME =	libftprintf.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	ar -cvq $(NAME) $(OBJ) libft/*.o

test : $(NAME) comp clean
	- rm $(NAME)

comp :
	clear && $(CC) .main.c $(NAME)

clean :
	-@ rm -f $(OBJ) && make fclean -C libft || true

fclean : clean
	-@ rm -f $(NAME) a.out || true

re : fclean all

.PHONY : LIBFT test comp clean fclean re


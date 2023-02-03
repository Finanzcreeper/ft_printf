CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = ft_printf.c ft_transformer.c
NAME =	libftprintf.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) LIBFT
	ar -cvq $(NAME) $(OBJ) libft/*.o

LIBFT :
	make -C libft

test : $(NAME) comp clean
	- rm $(NAME)

comp :
	clear && $(CC) .main.c $(NAME)

clean :
	- rm $(OBJ) && make fclean -C libft

fclean : clean
	- rm $(NAME) a.out

re : fclean all

.PHONY : LIBFT test comp clean fclean re


CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = ft_printf.c ft_transformer.c
NAME =	ft_printf.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) LIBFT
	ar -cvq $(NAME) $(OBJ) libft/libft.a

LIBFT :
	make -C libft

test : $(NAME) comp clean
	- rm $(NAME)

comp :
	clear && $(CC) .main.c ft_printf.a libft/libft.a

clean :
	- rm $(OBJ) && make fclean -C libft

fclean : clean
	- rm $(NAME) a.out

re : fclean all

.PHONY : LIBFT test comp clean fclean re


NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c printf_chars.c printf_hexa.c printf_number.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
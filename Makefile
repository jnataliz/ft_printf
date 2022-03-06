NAME = libftprintf.a
CC = gcc
SRC = src/ft_printf.c src/ft_flag.c src/ft_parse_flag.c
OBJ = ft_printf.o ft_flag.o ft_parse_flag.o
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror -c
LIB = ./libft/libft.a

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ) $(LIB) 
	ranlib $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

NAME = libftprintf.a
TEST = test
CC = gcc 
SRC = src/main.c src/ft_printf.c src/ft_flag.c src/ft_parse_flag.c
OBJ = $(SRC:.c=.o)
LIBFT = libft
INCLUDE = -I./include -I./libft
CFLAGS = -Wall -Wextra -Werror  $(INCLUDE)
# CFLAGS = $(INCLUDE)
LIB = ./libft/libft.a

all: $(NAME)

$(TEST): $(OBJ) $(LIB) 
	$(CC) $(OBJ) $(LIB) -o $(TEST)

$(NAME): $(OBJ)
	@rm -f $(NAME)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rc $(NAME) $(OBJ) $(LIB) 
	@ranlib $(NAME)
	@make clean

clean: 
	rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
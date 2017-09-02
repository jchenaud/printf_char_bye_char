NAME = libftprintf.a

SRC = Core_function.c  ft_strlen.c ft_putnbr.c ft_putstr.c ft_putchar.c\

INCLUDES = includes

BRICK = Core_function.o ft_strlen.o ft_putnbr.o ft_putstr.o ft_putchar.o\

# LIBFT_PATH = libft/
# LIBFT_LIB = libft/libft.a

all: $(NAME)
$(NAME):
	# cd $(LIBFT_PATH) && make re
	@gcc -c -Wall  -Wextra $(SRC) -I $(INCLUDES)
	@ar rc $(NAME) $(BRICK)
	@ranlib $(NAME)

clean:
	# cd $(LIBFT_PATH) && make clean	
	@/bin/rm -f $(BRICK)

fclean: clean
	# cd $(LIBFT_PATH) && make fclean	
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean

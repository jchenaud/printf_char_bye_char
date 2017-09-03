NAME = libftprintf.a

SRC = Core_function.c  ft_strlen.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_intflag.c ft_atoi.c ft_itoa_base_large.c ft_itoa_base.c\

INCLUDES = includes

BRICK = Core_function.o ft_strlen.o ft_putnbr.o ft_putstr.o ft_putchar.o ft_intflag.o ft_atoi.o ft_itoa_base_large.o ft_itoa_base.o\

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

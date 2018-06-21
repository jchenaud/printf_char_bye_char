NAME = libftprintf.a

SRC = 	Core_function.c x_flag.c ft_strlen.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_strdup.c\
		ft_intflag.c ft_atoi.c ft_itoa_base_large.c ft_itoa_base.c ll_itoa_base.c\
		ft_nega_itobase.c ft_strjoin.c ft_nega_litoa_base.c flag_pc.c flag_s.c flag_c.c flag_o.c flag_d.c flag_u.c\
		flag_p.c flag_uni_c.c\

INCLUDES = includes

BRICK = Core_function.o x_flag.o ft_strlen.o ft_putnbr.o ft_putstr.o ft_putchar.o ft_strdup.o\
		ft_intflag.o ft_atoi.o ft_itoa_base_large.o ft_itoa_base.o ll_itoa_base.o\
		ft_nega_itobase.o ft_strjoin.o ft_nega_litoa_base.o flag_pc.o flag_s.o flag_c.o flag_o.o flag_d.o flag_u.o\
		flag_p.o flag_uni_c.o\


all: $(NAME)
$(NAME):
	# cd $(LIBFT_PATH) && make re
	@gcc -c -Wall  -Wextra   $(SRC) -I $(INCLUDES)
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

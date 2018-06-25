NAME = libftprintf.a

SRC = 	ft_printf.c x_flag.c ft_strlen.c ft_putnbr.c ft_putstr.c ft_putchar.c ft_strdup.c\
		ft_intflag.c ft_atoi.c ft_itoa_base_large.c  ll_itoa_base.c\
		ft_strjoin.c ft_nega_litoa_base.c flag_pc.c flag_s.c flag_c.c flag_o.c flag_d.c flag_u.c\
		flag_p.c flag_uni_c.c easy_func.c take_value.c flag_s_size.c print_wchar.c next_flag.c ft_check_flag.c ft_modif_flag.c\

INCLUDES = includes

BRICK = ft_printf.o x_flag.o ft_strlen.o ft_putnbr.o ft_putstr.o ft_putchar.o ft_strdup.o\
		ft_intflag.o ft_atoi.o ft_itoa_base_large.o  ll_itoa_base.o\
		ft_strjoin.o ft_nega_litoa_base.o flag_pc.o flag_s.o flag_c.o flag_o.o flag_d.o flag_u.o\
		flag_p.o flag_uni_c.o easy_func.o take_value.o flag_s_size.o print_wchar.o next_flag.o ft_check_flag.o ft_modif_flag.o


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

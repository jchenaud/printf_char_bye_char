int x_flag(const char *str, va_list ap, t_env *e)
{
	// int size;
	// char *ito = NULL;
	if (e->ito)
		free(e->ito);

	if (str[e->i + 1] == 'x' && e->have_l > 0)
		e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),16, 0);
	else if (e->have_l >0)
		e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long long unsigned int)),16, 1);
	else if (str[e->i + 1] == 'x' && e->have_l == 0)
		e->ito = ft_itoa_base(va_arg(ap,int),16, 0);
	else if (e->have_l == 0)
		e->ito = ft_itoa_base(va_arg(ap,int),16, 1);
	e->size = ft_strlen(e->ito);
	if (e->have_sharp == 0 && e->have_int == 0 && e->have_point == 0)
	{
			write(1,e->ito,e->size);
			e->nc += e->size;
	} 
	// else 
	// {
	// 	e->ito = ito;
	// 	e->size = size;
	// }
	return (0);
}


int int_flag(const char *str, va_list ap, t_env *e)
{
	e->have_point = 0;
	e->zero = 0;
	e->size = 0;
	e->have_int = 1;
	int k;
	int nb;
	int tmp_nb;
	char c;
	char next_f;


	k = 0;
	c = str[e->i + 1];
	//printf("c= %c \n",c );

	nb = ft_int_flag_return_value(str,e->i,e);
	e->int_value = nb; // 3 varible c faudra opti
	tmp_nb = nb;
	
	if ( nb != 0)
	{
		if (e->zero != 0)
			c = '0';
		else
			c = ' ';
		e->i += ft_inc_intflag(nb,e);
		// if (str[e->i + 1] == '.')
		// 	e->have_point = 1;
	 // 	printf("stri[%c]\n",str[e->i+1]);
		// printf("have point = [%d]",e->have_point);
		next_f =  next_flag(str,e->i+1);
		if (str[e->i + 1] == '.')
		{
			e->have_point = 1;
			
			//printf("char = %c\n",next_f);
			if (next_f == 'x' || next_f == 'X')
			{
				while (str[e->i + 1] != 'x' && str[e->i + 1] != 'X')
				{
					e->i++;
				//	printf("coucou");

				}

			}
			//printf("nb = %d\n",nb);
			//printf("char = %c\n",str[e->i]);

		}
		if ((e->have_sharp != 0) && (next_f == 'x' || next_f == 'X'))
		{
			if (nb > 0)
			{
				e->have_neg = 0;
				x_flag(str, ap, e);
				if (nb >= e->size)
					e->nc += nb;
				else 
					e->nc += e->size;
				if (e->zero != 0)
				{
					//ft_printf("ha que coucou\n");
					if (next_f == 'x')
						write(1,"0x",2);
					else
						write(1,"0X",2);
				}
				while (nb - e->size - 2> 0)
				{
					ft_putchar(c);
					nb--;
				}
			}
			else 
			{
				e->have_neg = 1;
				while (str[e->i + 1] != 'x' && str[e->i + 1] != 'X')
					e->i++;
				x_flag(str, ap, e);
				if (str[e->i+1] == 'x')
				{
					write(1,"0x",2);
					write(1, e->ito, e->size);
				}
				else
				{
					write(1,"0X",2);
					write(1, e->ito, e->size);
				}
				nb *= -1;
				if (nb >= e->size)
					e->nc += nb;
				else 
					e->nc += e->size;
				while (nb - e->size - 2> 0)
				{
					ft_putchar(c);
					nb--;
				}
			}
			e->have_sharp = 0;
		}
		else if (nb > 0 && str[e->i + 1] != '%' && str[e->i + 1] != '.')
		{
			ft_check_flag(str,e->i,ap,e);
			if (nb >= e->size)
				e->nc += nb;
			else 
				e->nc += e->size;
			while (nb - e->size > 0)
			{
				ft_putchar(c);
				nb--;
			}
			if(next_f != 's' && next_f != 'S')
				write(1, e->ito, e->size);
			else
				write(1, e->string, e->size);

			//if (str[e->i + 1] != '%')

		}
		else if (nb < 0 && str[e->i + 1] != '%' && str[e->i + 1] != '.')
		{
			nb *= -1;
			ft_check_flag(str, e->i, ap, e);
			if (nb >= e->size)
				e->nc += nb;
			else 
				e->nc += e->size;
			write(1, e->ito, e->size);
			while (nb - e->size > 0)
			{
				ft_putchar(c);
				nb--;
			}
		}
		else if (str[e->i + 1] == '%')
		{
			if(nb > 0)
			{
				e->nc += nb;
				while (nb - 1 > 0)
				{
					ft_putchar(c);
					nb--;
				}
				ft_putchar('%');
			}
			else if(nb < 0)
			{
				nb *= -1;
				e->nc += nb;
				ft_putchar('%');
				while (nb - 1 > 0)
				{
					ft_putchar(c);
					nb--;
				}
			}
		}
		//free(e->ito);
		e->have_int = 0;
	}
	if (e->have_point == 1)
	{
		//ft_printf("fuck\n");
		if(tmp_nb == 0)
			e->i++;
		next_f = next_flag(str,e->i);
		printf("str[i]%c\n",str[e->i+1]);
		if ((e->int_value = ft_int_flag_return_value(str,e->i,e)) != 0)
		{
			//printf("coucou\n");
			
			if(next_f == 'S' || next_f == 's')
				while (str[e->i+1] != 's' && str[e->i+1] != 'S')
					e->i++;
			//printf("coucou\n");
			ft_check_flag(str,e->i,ap,e);
			//printf("coucou\n");
		}
		else //if (next_flag(str[e->i]) == '%')
		{
				//ft_printf("salut %c\n",next_flag(str,e->i));
			//printf("str[i]%c\n",str[e->i+1]);
			//printf("flag = %c\n",next_f);
			if (next_f == '%')
			{
				//printf("quesaue je fou la\n");
				ft_putchar('%');
				e->nc++;
			}
			else if (next_f == 'x' || next_f == 'X')// && tmp_nb != 0)
			{	
				ft_check_flag(str,e->i,ap,e);
				if(ft_atoi(e->ito) != 0)
				{

					write(1, e->ito, e->size);
					//printf("coucou\n");
				}
				else
				{
					//e->i++;
				 	while (str[e->i+1] != 'x' && str[e->i+1] != 'X')
						e->i++;
					//printf("have point 0 = [%d]",e->have_point);	
					//printf("stri[%c]\n",str[e->i+1]);

				//printf("yo\n");		



					// if (str[e->i+1] && str[e->i+1] != '%')
					// {
					// 	//e->i++;
					// 	write(1,&str[e->i+1],1);
					// }
					//ft_printf("salut %c\n",&str[e->i+1]);
				}
					//printf("cocorico\n");
				//printf("yo la companie\n");
			}

		}
		//e->have_point = 0;
		// while (int_flag_find(str,e->i + 1) == 1)
		// 	e->i++;
		// e->i++;
		// ft_putchar('%');
		// e->nc++;	
	}
	return(0);

}

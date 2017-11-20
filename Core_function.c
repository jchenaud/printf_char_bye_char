
#include "ft_printf.h"
#include <stdio.h>

void ft_init(t_env *e)
{

	 e->presition = 0;
	 e->int_value = 0;

	e->have_sharp = 0;
	e->have_l = 0;
	e->have_int = 0;
	e->have_point = 0;
	
	e->have_neg = 0;
	e->have_write = 0;
	e->have_posi = 0;
	e->have_space = 0;
	e->zero = 0;
	e->sub_n_zero = 0;
	e->have_h = 0;
	e->have_j = 0;
	e->have_z = 0;
	e->ito_neg = 0;

	if (e->ito != NULL)
	{
		free(e->ito);
		e->ito = NULL;
	}
}

void ft_modif_flag(const char * str, t_env *e)
{
	//printf("k[%c]\n",str[e->i+1]);
	while (have_modi_flag(str[e->i+1]) == 1)
	{

		if (str[e->i + 1] == ' ')
			e->have_space++;
		else if (str[e->i + 1] == '#')
			e->have_sharp = 1;
		else if (str[e->i + 1] == '.')
			e->have_point = 1;
		else if (str[e->i + 1] == 'l')
			e->have_l++;
		else if (str[e->i + 1] == 'h')
			e->have_h++;
		else if (str[e->i + 1] == 'j')
			e->have_j++;
		else if(str[e->i + 1] == '+')
			e->have_posi++;
		else if(str[e->i + 1] == 'z')
			e->have_z++;
		else if(str[e->i + 1] == '0') // y a une coquille 
		{
			while (str[e->i + 1] == '0')
				e->i++;
			e->i--;
			e->zero++;
			// if (int_flag_find(str,e->i+1) == 1)
			// 	return ;
		}
		else if(str[e->i + 1] == '-')
		{
			//printf("ito[%s]\n",e->ito);
			if (int_flag_find_without_zero(str,e->i+1) == 1)
				return ;
			e->have_neg++;
		}
		//e->have_neg++;
		e->i++;
	}
	//printf("k[%c]\n",str[e->i+1]);

}

int ft_check_flag(const char *str, unsigned int init,va_list ap,t_env *e)
{

	//printf("k[%c]\n",str[e->i+1]);
	if (init == 1)
	{
		ft_init(e);
		init = 0;
	}
	// while(str[e->i+1] == ' ')
	// {
	// 	e->have_space++;
	// 	e->i++;
	// }
	ft_modif_flag(str,e);
	//printf("[%c]\n",str[e->i+1]);
	if (str[e->i + 1] == '%')
	{
		flag_pc(e);
		return(0);
	}
	else if(str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
	{
		x_flag(str, ap, e);
		return (0);
	}
	else if (str[e->i + 1] == 'o')
	{
		flag_o(ap ,e);
		return (0);
	}
	else if (str[e->i + 1] == 'd')
	{
		flag_d(ap ,e);
		return (0);
	}
	else if (str[e->i + 1] == 's')
	{
		flag_s(e, ap);
		return (0);
	}
	else if (str[e->i + 1] == 'c')
	{
		flag_c(e,ap);
		return (0);
	}
	else if (str[e->i + 1] == 'u' || str[e->i + 1] == 'U')
	{
		//write(1,"salut",5);
		flag_u( ap, e, str[e->i + 1]);
		return (0);
	}
	else if(int_flag_find(str, e->i) == 1)
	{
		int_flag(str, e);
	 	ft_check_flag(str, 0, ap, e);
	 	return (0);
	}
	//else
	// {
	// 	//printf("x\n");
	// 	int_flag(str,ap,e);
	// 	//printf("y\n");
	// 	ft_check_flag(str,0,ap,e);
	// 	//printf("z\n");

	// }
	return(0);
// if (str[e->i + 1] ==  ' ')
// {
// 	if (next_flag(str,e->i+1) == 'd')
// 	{
// 		while(str[e->i + 1] == ' ')
// 			e->i++;
// 		e->have_space++;
// 		ft_check_flag(str,0,ap,e);

// 		if(ft_atoi(e->ito) >= 0)
// 		{
// 			ft_putchar(' ');
// 			e->nc++;
// 		}

// 		write(1,e->ito,e->size);
// 		e->nc += e->size;
	
// 		e->have_space = 0;
// 		return (0);
// 	}
// 	while(str[e->i + 1] == ' ')
// 		e->i++;
// }
// if (str[e->i + 1] == 's' || str[e->i + 1] == 'S')
// 	{
// 		//char *string;
// 		e->string = va_arg(ap,char*);
// 		if (e->have_int == 0)
// 		{
// 			if(e->string != NULL)
// 			{
// 				e->size = ft_strlen(e->string);

// 				if (e->have_point == 0)
// 				{
// 					write(1, e->string, e->size);
// 					e->nc += e->size;
// 				}
// 			}
// 			else
// 			{
// 				write(1, "(null)",6);
// 				e->nc += 6;
// 			}
// 		}
// 		else
// 		{
// 				e->size = ft_strlen(e->string);
// 				return(0);		
// 		}
// 	}
// 	else if (str[e->i + 1] == 'c' || str[e->i + 1] == 'C')
// 	{
// 		e->c = va_arg(ap,int);
// 		if (e->have_int == 0)
// 		{
// 			if (e->c == '0')
// 			{
// 				ft_putchar('\0');
// 			}
// 			else 
// 				write(1,&e->c,1);
// 			e->nc++;
// 		}
// 		else
// 			e->size = 1;
// 	}
// 	else if (str[e->i + 1] == 'd')
// 	{
// 		int k;
// 		int add_size;

// 		e->sub_n_zero = 0;
// 		add_size = 0;
// 		if (e->have_l == 0 && e->have_h == 0)
// 			k = va_arg(ap,int);
// 		else if (e->have_l == 1)//&& e->have_h == 0)
// 			e->ito = ft_neg_litoa_base((long int)k,10, 0);
// 		if (k == -2147483648 || (k == 2147483648))
// 		{
// 			e->nc = 10;
// 			if (k == -2147483648)
// 			{
// 				write(1,"-2147483648",11);
// 				e->nc++;
// 			}
// 			if (k == 2147483648)
// 				write(1,"2147483648",10);
// 			return (0);
// 		}
// 		if (e->have_posi != 0 && k >= 0)
// 		{
// 			ft_putchar('+');
// 		// 	//k *= -1;
// 		 	add_size++;
// 		}
// 		if (k < 0 && e->zero != 0  && e->have_int != 0)
// 		{
// 			ft_putchar('-');
// 			//e->nc++;
// 			//add_size ++;
// 			e->sub_n_zero++;
// 			k *= -1;
// 		} 
// 	//	if(k < 0 && k != -2147483648)
// 	//		add_size++
// 		if (e->have_l == 0)
// 			e->ito = ft_neg_itoa_base(k,10, 0);
// 		else if (e->have_l == 1)
// 			e->ito = ft_neg_litoa_base(k,10, 0);

			
// 		//printf("e->ito[%s]\n",e->ito);
// 		e->size = add_size;
// 		e->size += ft_strlen(e->ito);
// 		//printf("size[%d] ito[]\n",e->size);
// 		if (e->have_int == 0 && e->have_space == 0)
// 		{
// 			if  (k != -2147483648)
// 				e->nc += e->size;
// 			else
// 				e->nc += 11;
// 			ft_putnbr(k);
// 		}
// 		return (0);
// 	}
// 	else if (str[e->i + 1] == '%')
// 	{
// 		ft_putchar('%');
// 		e->nc++;
// 	}
// 	else if (str[e->i + 1] == 'p')
// 	{
// 		void *ptr;
// 		ptr = va_arg(ap,void *); // a convertire en exa
// 		ft_putnbr(ptr);
// 		// free(ptr);
// 		// ptr = NULL;
// 	}
// 	else if (str[e->i + 1] == 'o')
// 	{
// 		//ft_putchar('P');
// 		o_flag(str,ap,e);
// 		// if (e->zero != 0)
// 		// 		printf("e->0 = [%d]\n",e->zero);
// 		if(e->have_point != 0)
// 			return (0);

// 	}
// 	else if (str[e->i + 1] == 'X' || str[e->i + 1] == 'x')
// 	{
// 			x_flag(str,ap,e);
// 			if(e->have_point != 0)
// 				return (0);
// 	}
// 	else if(str[e->i + 1] == 'j')
// 	{
// 		e->i++;
// 		// int size;
// 		// char *ito;
// 		if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X') 
// 		{
// 				if(str[e->i + 1] == 'x')
// 					e->ito = ft_llitoa_base((long unsigned int)(va_arg(ap,long unsigned int)),16, 0);
// 				else 
// 					e->ito = ft_llitoa_base((long unsigned int)(va_arg(ap,long unsigned int)),16, 1);
// 				e->size = ft_strlen(e->ito);
// 			if (e->have_sharp == 0 && e->have_int == 0)
// 			{
// 				write(1,e->ito,e->size);
// 				e->nc += e->size;
// 			} 
// 		}
// 	}
	// else
	// {
	// 	if (int_flag(str,ap,e) == -1)
	// 		return(-1);
	// 	e->have_write = 0;

	// }
	//return (0);

}

//faire une fonction itsflague_int ...


int ft_end(t_env *e)
{
	int nb_char = e->nc;
	// if(e->ito)
	// 	free(e->ito);
	if (e->ito != NULL)
	{
		free(e->ito);
		e->ito = NULL;
	}
	// if(e)
	// {
	// 	free(e);
	// 	e = NULL;
	// }
	return (nb_char);
}

int ft_printf(const char *str, ...)
{
	//printf("k");
	static t_env e;
	va_list ap;
	//e = (t_env *)malloc(sizeof(t_env));
	// if (!e)
	// 	return (0);
	e.ito = NULL;
	e.string = NULL;


	e.nc = 0;
	//unsigned int nc;

	// unsigned int i;
	e.i = 0;
	if (!(str[0]))
	{
		//free(e);
		return(0);
	}
	va_start(ap, str);
	ft_init(&e);
	while ((str[e.i] && str[e.i] != '%') || (e.i == 0))
	{
		if (e.i != 0 || str[e.i] != '%')// || (!str[1]))
		{
			write(1,&str[e.i],1);
		e.nc++;
		}
		if(str[e.i] != '%')
			e.i++;
		while(str[e.i] && str[e.i] == '%')
		{		
			if(str[e.i+1])
			{
				// if(str[e->i+1] != '\0')
				// {
					///printf("c = [%c]\n",str[e->i+1]);
					if(ft_check_flag(str,1,ap,&e) == -1)
					{
						ft_printf("yo\n");
						//return (ft_end(e));
					}
					// printf("/////////////////////////////////////////////\n");
					//printf("Yo[%c]",'k');
				//}
				// if (str[e->i] && str[e->i] != '%')
				// 	write(1,&str[e->i],1);
			}
			else
				return(e.nc);
			e.i = e.i+2;
			
		}
	}
	va_end(ap);
	return (ft_end(&e));
	printf("\n");
	

}





// if (str[e->i + 1] ==  ' ')
// {
// 	if (next_flag(str,e->i+1) == 'd')
// 	{
// 		while(str[e->i + 1] == ' ')
// 			e->i++;
// 		e->have_space++;
// 		ft_check_flag(str,e->i,ap,e);

// 		if(ft_atoi(e->ito) >= 0)
// 		{
// 			ft_putchar(' ');
// 			e->nc++;
// 		}

// 		write(1,e->ito,e->size);
// 		e->nc += e->size;
	
// 		e->have_space = 0;
// 		return (0);
// 	}
// 	while(str[e->i + 1] == ' ')
// 		e->i++;
// }
// if (str[e->i + 1] == 's' || str[e->i + 1] == 'S')
// 	{
// 		//char *string;
// 		e->string = va_arg(ap,char*);
// 		if (e->have_int == 0)
// 		{
// 			if(e->string != NULL)
// 			{
// 				e->size = ft_strlen(e->string);

// 				if (e->have_point == 0)
// 				{
// 					write(1, e->string, e->size);
// 					e->nc += e->size;
// 				}
// 			}
// 			else
// 			{
// 				write(1, "(null)",6);
// 				e->nc += 6;
// 			}
// 		}
// 		else
// 		{
// 				e->size = ft_strlen(e->string);
// 				return(0);		
// 		}
// 	}
// 	else if (str[e->i + 1] == 'c' || str[e->i + 1] == 'C')
// 	{
// 		e->c = va_arg(ap,int);
// 		if (e->have_int == 0)
// 		{
// 			if (e->c == '0')
// 			{
// 				ft_putchar('\0');
// 			}
// 			else 
// 				write(1,&e->c,1);
// 			e->nc++;
// 		}
// 		else
// 			e->size = 1;
// 	}
// 	else if (str[e->i + 1] == 'd')
// 	{
// 		int k;
// 		int add_size;

// 		e->sub_n_zero = 0;
// 		add_size = 0;
// 		if (e->have_l == 0 && e->have_h == 0)
// 			k = va_arg(ap,int);
// 		else if (e->have_l == 1)//&& e->have_h == 0)
// 			e->ito = ft_neg_litoa_base((long int)k,10, 0);
// 		if (k == -2147483648 || (k == 2147483648))
// 		{
// 			e->nc = 10;
// 			if (k == -2147483648)
// 			{
// 				write(1,"-2147483648",11);
// 				e->nc++;
// 			}
// 			if (k == 2147483648)
// 				write(1,"2147483648",10);
// 			return (0);
// 		}
// 		if (e->have_posi != 0 && k >= 0)
// 		{
// 			ft_putchar('+');
// 		// 	//k *= -1;
// 		 	add_size++;
// 		}
// 		if (k < 0 && e->zero != 0  && e->have_int != 0)
// 		{
// 			ft_putchar('-');
// 			//e->nc++;
// 			//add_size ++;
// 			e->sub_n_zero++;
// 			k *= -1;
// 		} 
// 	//	if(k < 0 && k != -2147483648)
// 	//		add_size++
// 		if (e->have_l == 0)
// 			e->ito = ft_neg_itoa_base(k,10, 0);
// 		else if (e->have_l == 1)
// 			e->ito = ft_neg_litoa_base(k,10, 0);

			
// 		//printf("e->ito[%s]\n",e->ito);
// 		e->size = add_size;
// 		e->size += ft_strlen(e->ito);
// 		//printf("size[%d] ito[]\n",e->size);
// 		if (e->have_int == 0 && e->have_space == 0)
// 		{
// 			if  (k != -2147483648)
// 				e->nc += e->size;
// 			else
// 				e->nc += 11;
// 			ft_putnbr(k);
// 		}
// 		return (0);
// 	}
// 	else if(str[e->i + 1] == '+')
// 	{
// 		e->have_posi = 1;
// 		e->i++;
// 		while(str[e->i + 1] == ' ')
// 			e->i++;
// 	 	ft_check_flag(str,e->i,ap,e);
// 	}
// 	else if (str[e->i + 1] == '%')
// 	{
// 		ft_putchar('%');
// 		e->nc++;
// 	}
// 	else if (str[e->i + 1] == 'p')
// 	{
// 		void *ptr;
// 		ptr = va_arg(ap,void *); // a convertire en exa
// 		ft_putnbr(ptr);
// 		// free(ptr);
// 		// ptr = NULL;
// 	}
// 	else if (str[e->i + 1] == 'o')
// 	{
// 		//ft_putchar('P');
// 		o_flag(str,ap,e);
// 		// if (e->zero != 0)
// 		// 		printf("e->0 = [%d]\n",e->zero);
// 		if(e->have_point != 0)
// 			return (0);

// 	}
// 	else if (str[e->i + 1] == 'X' || str[e->i + 1] == 'x')
// 	{
// 			x_flag(str,ap,e);
// 			if(e->have_point != 0)
// 				return (0);
// 	}
// 	else if(str[e->i + 1] == 'l')
// 	{
// 		e->i++;
// 		//int size;
// 		//char *ito = NULL;
// 		e->have_l++;

// 		if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X') 
// 			x_flag(str,ap,e);
// 		else
// 		{
// 			e->i++;
// 	 		ft_check_flag(str,e->i,ap,e);

// 		}
// 		e->have_l = 0;
// 	}
// 	else if(str[e->i + 1] == 'h')
// 	{
// 		e->i++;
// 		if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X') 
// 		{
// 			if(str[e->i + 1] == 'x')
// 				e->ito = ft_itoa_base((short int)(va_arg(ap,short int)),16, 0);
// 			else
// 				e->ito = ft_itoa_base((short int)(va_arg(ap,short int)),16, 1);
// 			e->size = ft_strlen(e->ito);
// 			if (e->have_sharp == 0 && e->have_int == 0)
// 			{
// 				write(1,e->ito,e->size);
// 				e->nc += e->size;
// 			} 
// 		else 
// 		{
// 			ft_check_flag(str,e->i,ap,e);
// 		}
// 	}
// 	else if(str[e->i + 1] == 'j')
// 	{
// 		e->i++;
// 		// int size;
// 		// char *ito;
// 		if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X') 
// 		{
// 				if(str[e->i + 1] == 'x')
// 					e->ito = ft_llitoa_base((long unsigned int)(va_arg(ap,long unsigned int)),16, 0);
// 				else 
// 					e->ito = ft_llitoa_base((long unsigned int)(va_arg(ap,long unsigned int)),16, 1);
// 				e->size = ft_strlen(e->ito);
// 			if (e->have_sharp == 0 && e->have_int == 0)
// 			{
// 				write(1,e->ito,e->size);
// 				e->nc += e->size;
// 			} 
// 		}
// 	}
// 	else if(str[e->i + 1] == '#')
// 	{
// 		e->have_sharp = 1;

// 		e->i++;
// 		if (str[e->i + 1] == '.')
// 			e->have_point = 1;
// 		if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X') 
// 		{
// 				x_flag(str,ap,e);
// 				if (ft_have_val(e->ito) == 1) 
// 				{
// 					if (str[e->i + 1] == 'X')
// 						write(1,"0X",2);
// 					else 
// 						write(1,"0x",2);
// 				write(1,e->ito,ft_strlen(e->ito));
// 					e->nc += 2 + ft_strlen(e->ito);
// 				else
// 				{
// 					ft_putchar('0');
// 					e->nc++;
// 				}
// 		}
// 		else if (str[e->i + 1] == 'l')
// 		{
// 			e->have_l++;
// 			ft_check_flag(str,e->i,ap,e);
// 			if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X') 
// 			{
// 				if (ft_have_val(e->ito) == 1) 
// 				{
// 					if (str[e->i + 1] == 'X')
// 						write(1,"0X",2);
// 					else 
// 						write(1,"0x",2);
// 				write(1,e->ito,ft_strlen(e->ito));
// 				e->nc += 2 + ft_strlen(e->ito);
// 				}
// 				else
// 				{
// 					ft_putchar('0');
// 					e->nc++;
// 				}
// 			}
// 			e->have_l = 0;
// 		}
// 		else if (next_flag(str,e->i+1) == 'x' || next_flag(str,e->i+1) == 'X') //  ou pourai opti en diminuan le nobre dappele a next_flag
// 		{
// 			if(next_flag(str,e->i+1) == 'x')//&& e->have_point == 0)
// 			{
// 				//e->i++;
// 				int_flag(str,ap,e);
// 				if (e->have_neg == 0 && e->have_point == 0)
// 				{
// 					if (e->zero == 0)
// 						write(1,"0x",2);
// 					write(1, e->ito, e->size);
// 				}
// 			}
// 			else if (next_flag(str,e->i+1) == 'X')// && e->have_point == 0)
// 			{
// 				int_flag(str,ap,e);
// 				if (e->have_neg == 0 && e->have_point == 0)
// 				{
// 					if (e->zero == 0)
// 						write(1,"0X",2);
// 					write(1, e->ito, e->size);
// 				}
// 			}
// 		}
// 		else if (next_flag(str,e->i+1) == 'o')
// 		{
// 			ft_check_flag(str,0,ap,e);
// 			if (e->have_neg == 0 && e->have_point == 0)
// 				{
// 					if (e->zero == 0)
// 						write(1,"0",1);
// 					write(1, e->ito, e->size);
// 				}
// 		}
// 		e->zero = 0;
// 		e->have_point = 0;
// 		e->have_sharp = 0;
// 	}
// 	else
// 	{
// 		if (int_flag(str,ap,e) == -1)
// 			return(-1);
// 		e->have_write = 0;

// 	}
// 	return (0);

// }
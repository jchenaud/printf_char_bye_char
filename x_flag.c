/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 07:14:40 by jchenaud          #+#    #+#             */
/*   Updated: 2017/11/20 16:27:37 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void juste_print(const char *str,t_env *e)
{
	if(e->have_sharp != 0 && ft_atoi(e->ito) != 0)
	{
		if (str[e->i + 1] == 'x')
			write(1,"0x",2);
		else
			write(1,"0X",2);
		e->nc += 2;
	}
	write(1,e->ito,e->size);
	e->nc += e->size;
}

int x_flag(const char *str, va_list ap, t_env *e)
{
	// int size;
	// char *ito = NULL;
	if (e->ito)
	{ 
		free(e->ito);
		e->ito = NULL;
	}

	if (str[e->i + 1] == 'x' && (e->have_l > 0 || e->have_j > 0))
		e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),16, 0);
	else if (e->have_l >0)
		e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long long unsigned int)),16, 1);
	else if (str[e->i + 1] == 'x' && e->have_l == 0)
		e->ito = ft_itoa_base(va_arg(ap,int),16, 0);
	else if (e->have_l == 0)
		e->ito = ft_itoa_base(va_arg(ap,int),16, 1);
	e->size = ft_strlen(e->ito);
	////////////////////////////____affichage_________________________________

	int sharp_size = 0;
	char c;
	if (e->zero > 0)
		c = '0';
	else 
		c = ' ';
	if (e->have_sharp != 0 && ft_atoi(e->ito) != 0)
	{
		if((e->int_value == 0 || e->zero != 0))
		{
			if (str[e->i + 1] == 'x')
				write(1,"0x",2);
			else
				write(1,"0X",2);
			e->nc += 2;
			e->have_sharp = 0;
			if (e->zero != 0)
				sharp_size = 2;

		}
		else
			sharp_size = 2;
		//e->size += 2;
	}
	if (ft_atoi(e->ito) == 0 && e->have_point != 0)
	{
		if (e->int_value != 0)
		{
			while(e->int_value > 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value--;
			}
			while(e->int_value < 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value++;
			}
		}
		return(0);
	}
	if (e->int_value == 0 && e->have_point == 0)
		juste_print(str, e);
	else 
	{
		if(e->int_value != 0 && e->have_point == 0)
		{
			while(e->int_value - e->size  - sharp_size > 0)
			{
				ft_putchar(c);
				e->nc++;
				e->int_value--;
			}
			juste_print(str ,e);
			while(e->int_value + e->size + sharp_size < 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value++;
			}
		}
		else if(e->int_value == 0 && e->have_point != 0)
		{
			if(e->presition < e->size)
				juste_print(str, e);
			////// maque un truc si la presition est superrieure ?
		}
		else if (e->int_value != 0 && e->have_point != 0)
		{
			while(e->int_value - e->size > 0)
			{
				ft_putchar(c);
				e->nc++;
				e->int_value--;
			}
			if(e->presition < e->size)
				juste_print(str, e);
			///// maque un truc si la presition est superrieure ?
			while(e->int_value + e->size < 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value++;
			}
		}

	}
	return (0);
}

// int point_flag(const char *str, va_list ap, t_env *e)
// {
// 	//ft_printf("salut\n");
// 	int nb;
// 	//char *next_f;
// 	//ft_printf("yo");

// 	if(str[e->i+1] == '.')
// 	{
// //	ft_printf("yo[2]");
		
// 		e->have_point = 1;
// 		e->i++;
// 		nb = ft_int_flag_return_value(str,e->i,e);
// 		//ft_printf("nb[%d]",nb);
// 		if (nb <= 0)
// 		{
// 		//	ft_printf("yo[3]");
// 			e->i++;
// 			//ft_putchar('\n');
// 			if (char_is_flag(str[e->i + 1]) == 1)
// 			{
// 				//ft_printf("salut\n");
// 				if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
// 				{
// 					x_flag(str, ap, e);
// 					if (ft_atoi(e->ito) == 0)
// 					{
// 						ft_putchar(' ');// ses pas ouf mais je sais pas pourauoi i+2 marche pas
// 						e->nc++;
// 					}
// 						//ft_printf("cacahutte");
// 				}
// 				else
// 				{
// 					//ft_printf("yo");
// 					ft_check_flag(str,e->i,ap,e);
// 				}
// 				return (0);
// 			}
// 		}
// 		e->i += ft_inc_intflag(nb,e);
// 	//	ft_printf("c[%c]\n",str[e->i + 1] );
// 		if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X' ||  str[e->i + 1] == 'o' )
// 		{
// 		//ft_printf("yo");
// 			// if(str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
// 			// 	x_flag(str, ap, e);
// 			// else if(str[e->i + 1] == 'o')
// 			// 	o_flag(str, ap, e);
// 			ft_check_flag(str, e->i, ap, e);
// 			//ft_printf("intv[%d]",e->int_value);
// 			if (e->int_value < 0 || e->have_int == 0)
// 			{
// 				//	ft_printf("salut");

// 				if (nb >= e->size)// && ((e->int_value == 0)||(e->int_value * -1) < nb))
// 				{
// 				//	ft_printf("salut");
// 					if (((e->int_value == 0)||(e->int_value * -1) < nb))
// 						e->nc += nb;
// 					while(nb > e->size)
// 					{
// 						ft_putchar('0');
// 						nb--;
// 					}
// 				write(1, e->ito, e->size);
// 				e->have_write = 1;
// 				}
// 				else if (nb < e->size)// if (e->int_value < nb)
// 				{
// 					e->nc += e->size;
// 					write(1, e->ito, e->size);
// 				}
// 			}
// 			else
// 			{
// 				e->i++;
// 				return (0);				
// 			}
// 		//	ft_printf("c1 []");
// 			//e->i++;
// 		}
// 		else if (str[e->i + 1] == 's' || str[e->i + 1] == 'S')
// 		{

// 			int size;
// 			ft_check_flag(str, e->i, ap, e);
// 			if (nb >= e->size)
// 				size = e->size;
// 			else 
// 				size = nb;
// 			if (e->have_int == 0) //e->int_value < 0 ||
// 			{
// 				write(1, e->string, size);
// 				e->nc += size;
// 			}
// 			else if (e->int_value < 0)
// 			{
// 				e->size = size;
// 					//ft_printf("size[%d]",size);
// 					//write(1, e->string, size);
// 			}
// 			else if (e->int_value > 0)
// 			{
// 				if (size >= e->int_value)
// 				{
// 					write(1, e->string, size);
// 					e->nc += size;
// 				}
// 				else
// 				{
// 					e->size = size;
// 					return(0);
// 				}
// 			}
// 		}
// 		else if (str[e->i + 1] == 'c' || str[e->i + 1] == 'C')
// 		{
// 			ft_check_flag(str, e->i, ap, e);
// 		}
// 		// else if (str[e->i + 1] == 'o')
// 		// {
// 		// 	//ft_printf("yo[4]");
// 		// 	// if (e->int_value < 0 || e->have_int == 0)
// 		// 	// {
// 		// 		//ft_printf("yo");
// 		// 		o_flag(str, ap, e);
// 		// 		// if (e->have_int = 0)
// 		// 		// {
// 		// 			if (nb >= e->size)  // ya deux nb 
// 		// 			{
// 		// 				//if (e->have_int = 0 || e->int_value < nb)

// 		// 					e->nc += nb;
// 		// 				while(nb > e->size)
// 		// 				{
// 		// 					ft_putchar('0');
// 		// 					nb--;
// 		// 				}
// 		// 			}
// 		// 			else 
// 		// 			{
// 		// 				e->nc += e->size;
// 		// 			}
// 		// 		//}
// 		// //ft_pr//intf("yo");
// 		// 	// ft_printf("yo[5]");
// 		// 	// 	write(1, e->ito, e->size);
// 		// 	// ft_printf("yo[6]");
// 		// 	//e->i++;

// 		// 	// }
// 		// // 	// else
// 		// // 	// {
// 		// // 	// 	e->i++;
// 		// // 	// 	ft_printf("yo");
// 		// // 	// 	ft_check_flag(str, e->i, ap, e);
// 		// // 	// 	return (0);				
// 		// // 	// }
// 		//  }
// 		// else
// 		// {
// 		// 	e->i++;
// 		// 	ft_check_flag(str, e->i, ap, e);
// 		// }

// 		return(1);
// 	}
// 	return(0);
// }




void int_flag(const char *str, t_env *e)
{
	int nb;

	nb = ft_int_flag_return_value(str,e->i,e);
	e->i += ft_inc_intflag(nb);
	
	if (e->have_point == 1)
	{
		if (nb > 0)
		 	e->presition = nb;
		 else
		 	e->presition = 0;
	}
	else 
	{
		if(e->have_neg)
			nb *= -1;
		e->int_value = nb;
	}
}


















































// int int_flag(const char *str, va_list ap, t_env *e)
// {
// 	//ft_printf("int_flag\n");
// 	e->have_point = 0;
// 	//e->zero = 0;
// 	e->size = 0;
// 	int k;
// 	int nb;
// 	int tmp_nb;
// 	char c;
// 	char next_f;


// 	k = 0;
// 	c = str[e->i + 1];
// 	nb = ft_int_flag_return_value(str,e->i,e);
// 	e->int_value = nb; // 3 varible c faudra opti
// 	if (nb != 0)
// 	{
// 		//ft_printf("yo");
// 		// if()

// 		e->have_int++;
// 		if (e->zero != 0 && nb > 0)
// 			c = '0';
// 		else
// 			c = ' ';
// 		e->i += ft_inc_intflag(nb,e);
// 		// printf("c = [%c]",str[e->i]);
// 		next_f =  next_flag(str,e->i);
// 		if (str[e->i + 1] == '.')
// 			point_flag(str, ap, e);
// 		if (e->have_sharp != 0)// && (next_f == 'x' || next_f == 'X'))
// 		{
// 			if (next_f == 'x' || next_f == 'X' || next_f == 'o')
// 			{
// 				if (nb > 0 && e->have_neg == 0)
// 				{
// 					if (next_f == 'x' || next_f == 'X')
// 						x_flag(str, ap, e);
// 					else if(next_f == 'o')
// 						o_flag(str, ap, e);
// 					if (nb >= e->size)
// 						e->nc += nb;
// 					else 
// 						e->nc += e->size;
// 					if (e->zero != 0)
// 					{
// 						if (next_f == 'x')
// 							write(1,"0x",2);
// 						else if (next_f == 'X')
// 							write(1,"0X",2);
// 						else if (next_f == 'o')
// 						{
// 							write(1,"0",1);
// 						}
// 					}
// 					if (next_f == 'x' || next_f == 'X')
// 					{
// 						while (nb - e->size - 2> 0)
// 						{
// 							ft_putchar(c);
// 							nb--;
// 						}
// 					}
// 					else if(next_f == 'o')
// 						while (nb - e->size - 1> 0)
// 						{
// 							//ft_putchar('k');
// 							ft_putchar(c);
// 							nb--;
// 						}
// 				}
// 				else 
// 				{
// 					//ft_printf("salut");
// 					e->have_neg = 1;
// 					while (str[e->i + 1] != 'x' && str[e->i + 1] != 'X' && str[e->i + 1] != 'o')
// 						e->i++;
// 					if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
// 						x_flag(str, ap, e);
// 					else if(str[e->i + 1] == 'o')
// 						o_flag(str,ap,e);
// 					if (str[e->i+1] == 'x')
// 					{
// 						write(1,"0x",2);
// 						write(1, e->ito, e->size);
// 					}
// 					else if (str[e->i+1] == 'X')
// 					{
// 						write(1,"0X",2);
// 						write(1, e->ito, e->size);
// 					}
// 					else if(str[e->i+1] == 'o')
// 					{
// 							write(1,"0",1);
// 							write(1, e->ito, e->size);
// 					}
// 					if (nb < 0)
// 						nb *= -1;
// 					if (nb >= e->size)
// 						e->nc += nb;
// 					else 
// 						e->nc += e->size;
// 					if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
// 					{
// 						while (nb - e->size - 2 > 0)
// 						{
// 							ft_putchar(c);
// 							nb--;
// 						}
// 					}
// 					else if(str[e->i + 1] == 'o')
// 					{
// 						//ft_printf("salut");
// 						while (nb - e->size - 1> 0)
// 						{
// 							ft_putchar(c);
// 							nb--;
// 						}
// 					}
// 				}
// 				e->have_sharp = 0;
// 			}
// 		}
// 		else if (nb > 0 && str[e->i + 1] != '%')// && str[e->i + 1] != '.')// && e->have_write == 0)// && e->have_point == 0)
// 		{
		
// 			if (e->have_point == 0 && e->have_write == 0)
// 			{
// 				//printf("[B]");
// 				//printf(&str[e->i+1]);	
// 				//printf("[%c]",str[e->i]);	
// 				ft_check_flag(str,e->i,ap,e);
// 				// printf("[B]");

// 			}
// 			if (nb >= e->size && e->have_write == 0)
// 				e->nc += nb;
// 			else if (e->have_write == 0)
// 				e->nc += e->size;
// 			while (nb - e->size - e->sub_n_zero > 0)
// 			{
// 				ft_putchar(c);
// 				nb--;
// 			}
// 			if(next_f == 's' || next_f == 'S') // ici peut se jouer le teste 48
// 			{
// 				write(1, e->string, e->size);
// 			}
// 			else if (next_f == 'x' || next_f == 'X' || next_f == 'o' || next_f == 'd')
// 			{
// 				if (e->ito && ft_atoi(e->ito) != 0)
// 				{
// 					write(1, e->ito, e->size);
// 				}
// 			}
// 			else if (next_f == 'c' || next_f == 'c')
// 				ft_putchar(e->c);
// 		}
// 		else if (nb < 0 && str[e->i + 1] != '%')// && str[e->i + 1] != '.' && e->have_write == 0)
// 		{
// 			nb *= -1;
// 			e->have_neg = 1;
// 			if (e->have_point == 0)
// 				ft_check_flag(str, e->i, ap, e);
// 			if (nb >= e->size && e->have_write == 0)
// 				e->nc += nb;
// 			else if (e->have_write == 0) 
// 				e->nc += e->size;
// 			if(next_f == 's' || next_f == 'S')
// 				write(1, e->string, e->size);
// 			else if (next_f == 'c' || next_f == 'c')
// 				ft_putchar(e->c);
// 			else if ((next_f == 'x' || next_f == 'X' || next_f == 'o' ||  next_f == 'd')&& (e->have_write == 0))
// 			{
// 				write(1, e->ito, e->size);
// 			}
// 			while (nb - e->size - e->sub_n_zero > 0)
// 			{
// 				ft_putchar(c);
// 				nb--;
// 			}
// 		}
// 		else if (str[e->i + 1] == '%')
// 		{
// 			if(nb > 0)
// 			{
// 				e->nc += nb;
// 				while (nb - 1 > 0)
// 				{
// 					ft_putchar(c);
// 					nb--;
// 				}
// 				ft_putchar('%');
// 			}
// 			else if(nb < 0)
// 			{
// 				nb *= -1;
// 				e->nc += nb;
// 				ft_putchar('%');
// 				while (nb - 1 > 0)
// 				{
// 					ft_putchar(c);
// 					nb--;
// 				}
// 			}
// 		}
// 		e->have_int = 0;
// 	}
// 	else
// 	{
// 		if(str[e->i+1] == '.' || str[e->i+1] == '-' || str[e->i+1] == '+')
// 		{
// 			if (str[e->i+1] == '.')
// 				point_flag(str, ap, e);
// 			else if (str[e->i+1] == '-')
// 			{
// 				e->have_neg++;
// 				e->i++;
// 				ft_check_flag(str,0,ap, e);
// 			}
// 			else
// 			{
// 				e->have_posi++;
// 				//e->i++;
// 				ft_check_flag(str,0,ap, e);
// 			}
// 		}
// 		else
// 		{
// 			if (str[e->i+1])
// 				e->i++;
// 			else 
// 				return(-1);
// 			if (str[e->i+1] == '-')
// 			{
// 				e->have_neg = 1;
// 				e->i++;
// 				ft_check_flag(str,0,ap, e);
// 			}
// 			else if (str[e->i+1] == '+')
// 			{
// 				//ft_printf("yo\n");
// 				e->have_posi = 1;
// 				//e->i++;
// 				//ft_printf(&str[e->i+1]);
// 				ft_check_flag(str,0,ap, e);
// 			}
// 			else
// 			 {
// 		 		while (str[e->i+1] == '0')
// 		 			e->i++;
// 				ft_check_flag(str,0,ap, e);
// 			}
// 	}
// 		//{

// 		// 	point_flag(str, ap, e);
// 		//}
// 	}
// 	if (str[e->i + 1] == NULL)
// 	{
// 		return(-1);
// 	}
// 	return(0);
// }
// 	// if (e->have_point == 1)
// 	// {
// 	// 	if(tmp_nb == 0)
// 	// 		e->i++;
// 	// 	next_f = next_flag(str,e->i);
// 	// 	//printf("str[i]%c\n",str[e->i+1]);
// 	// 	if ((e->int_value = ft_int_flag_return_value(str,e->i,e)) != 0)
// 	// 	{
// 	// 		//printf("coucou\n");
			
// 	// 		if(next_f == 'S' || next_f == 's')
// 	// 			while (str[e->i+1] != 's' && str[e->i+1] != 'S')
// 	// 				e->i++;
// 	// 		ft_check_flag(str,e->i,ap,e);
// 	// 	}
// 	// 	else //if (next_flag(str[e->i]) == '%')
// 	// 	{
// 	// 		if (next_f == '%')
// 	// 		{
// 	// 			//printf("quesaue je fou la\n");
// 	// 			ft_putchar('%');
// 	// 			e->nc++;
// 	// 		}
// 	// 		else if (next_f == 'x' || next_f == 'X')// && tmp_nb != 0)
// 	// 		{	
// 	// 				//printf("salut\n");

// 	// 			ft_check_flag(str,e->i,ap,e);
// 	// 			if(e->ito && ft_atoi(e->ito) != 0)
// 	// 			{
// 	// 				//printf("salut\n");
// 	// 				write(1, e->ito, e->size);
// 	// 			}
// 	// 			else
// 	// 			{
// 	// 			 	while (str[e->i+1] != 'x' && str[e->i+1] != 'X')
// 	// 					e->i++;	



// 					// if (str[e->i+1] && str[e->i+1] != '%')
// 					// {
// 					// 	//e->i++;
// 					// 	write(1,&str[e->i+1],1);
// 					// }
// 					//ft_printf("salut %c\n",&str[e->i+1]);
// 			//	}
// 		//	}

// 		//}
// 		//e->have_point = 0;	
// 	//}
	




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 07:14:40 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/21 14:07:57 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void juste_print(const char *str,t_env *e)
{
	if(e->have_sharp != 0 && hexa_size(e->ito) > 0)
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

int hexa_size(const char *str) // retourne le nombre de cractre  exa daffiler de la chaine  si aue des 0 return -1
{
	int i;
	int have_oly_zero;

	have_oly_zero = 1;
	i = 0;

	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f')))
	{
		if (str[i] != '0')
			have_oly_zero = 0;
		i++;
	}
	if (i == 0 || have_oly_zero == 0)
		return (i);
	return (-1);
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

  
  // printf("yolo \n");
 if (str[e->i + 1] == 'x')
 {

 	if(e->have_l >= 2)
 		e->ito =  ft_llitoa_base((unsigned long long int)(va_arg(ap,unsigned long long int)),16,0);
 	else if(e->have_l == 1)
 		e->ito =  ft_llitoa_base((unsigned long int)(va_arg(ap,unsigned long int)),16,0);
 	else if (e->have_j != 0)
 		e->ito =  ft_llitoa_base((uintmax_t)(va_arg(ap,uintmax_t)),16,0);
 	else if (e->have_z != 0)
 		e->ito = ft_llitoa_base((ssize_t)(va_arg(ap,ssize_t)),16,0);

 	else
 		e->ito =  ft_llitoa_base((unsigned int)(va_arg(ap,unsigned int)),16,0);

 	// if(e->have_l >= 2)
 	// 	e->ito =  ft_neg_litoa_base((long long int)value,16,0);
 	// else if(e->have_l == 1)
 	// 	e->ito =  ft_neg_litoa_base((unsigned long int)value,16,0);
 	// else if (e->have_j != 0)
 	// 	e->ito =  ft_neg_litoa_base((uintmax_t)value,16,0);
 	// else
 	// 	e->ito =  ft_neg_litoa_base(value,16,0);

 	// if (e->have_l == 0 && e->have_j == 0  && e->have_z == 0)
 		 // e->ito = ft_neg_litoa_base((int)value,16, 0);
	// else if (e->have_l != 0  && e->have_h == 0 && e->have_j == 0 )
		// e->ito = ft_neg_litoa_base((unsigned long long int )value ,10, 0);
	// else if (e->have_l == 0 && e->have_h == 0 && e->have_j == 1 )
		// e->ito = ft_neg_litoa_base((uintmax_t) value, 10, 0);
	// else if (e->have_l == 0 && e->have_h == 0 && e->have_j == 0 )
		// e->ito = ft_neg_litoa_base((ssize_t)value ,10, 0);
 }
 else{

 	if(e->have_l >= 2)
 		e->ito =  ft_llitoa_base((unsigned long long int)(va_arg(ap,unsigned long long int)),16,1);
 	else if(e->have_l == 1)
 		e->ito =  ft_llitoa_base((unsigned long int)(va_arg(ap,unsigned long int)),16,1);
 	else if (e->have_j != 0)
 		e->ito =  ft_llitoa_base((uintmax_t)(va_arg(ap,uintmax_t)),16,1);
 	else if (e->have_z != 0)
 		e->ito =  ft_llitoa_base((ssize_t)(va_arg(ap,ssize_t)),16,1);

 	else
 		e->ito =  ft_llitoa_base((unsigned int)(va_arg(ap,unsigned int)),16,1);

 	// long long int value;
	// value =  (va_arg(ap,long long int));
 // 	if(e->have_l != 0)
 // 		e->ito =  ft_neg_litoa_base((long long int)value,16,1);
 // 	else if(e->have_l == 1)
 // 		e->ito =  ft_neg_litoa_base((unsigned long int)value,16,1);
 // 	else if (e->have_j != 0)
 // 		e->ito =  ft_neg_litoa_base((uintmax_t)value,16,1); 		
 // 	else
 // 	e->ito =  ft_neg_litoa_base(value,16,1);

 // 	if (e->have_l == 0 && e->have_j == 0  && e->have_z == 0)
 // 		 e->ito = ft_neg_litoa_base((int)value,16, 1);
	// else if (e->have_l != 0  && e->have_h == 0 && e->have_j == 0 )
	// 	e->ito = ft_neg_litoa_base((long long int )value ,10, 0);
	// else if (e->have_l == 0 && e->have_h == 0 && e->have_j == 1)
	// 	e->ito = ft_neg_litoa_base((uintmax_t) value, 10, 0);
	// else if (e->have_l == 0 && e->have_h == 0 && e->have_j == 0 )
	// 	e->ito = ft_neg_litoa_base((ssize_t)value ,10, 0);
 }
  // printf("yolo 2\n");
 
 	//else if (e->have_l == 0 && e->have_h == 1 && e->have_j == 0 && e->have_z == 0)
	// 	e->ito = ft_neg_litoa_base((short int)value,10, 0);
	// else if (e->have_l == 0 && e->have_h == 2 && e->have_j == 0 && e->have_z == 0)
	// 	e->ito = ft_neg_litoa_base((signed char)value ,10, 0);
	// else if (e->have_l == 1 && e->have_h == 0 && e->have_j == 0 && e->have_z == 0)
	// 	e->ito = ft_neg_litoa_base(((long int)va_arg(ap, long int)),10, 0);
	e->size = ft_strlen(e->ito);

	int exa_size = hexa_size(e->ito);


   //printf("yolo 3\n");



	// if (str[e->i + 1] == 'x' && (e->have_l > 0 || e->have_j > 0))
	// 	e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),16, 0);
	// else if (e->have_l > 0 || e->have_j > 0)
	// 	e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long long unsigned int)),16, 1);

	// else if (str[e->i + 1] == 'x' && e->have_z != 0)
	// 	e->ito = ft_llitoa_base((ssize_t)(va_arg(ap,ssize_t)),16, 0);
	// else if (e->have_z != 0)
	// 	e->ito = ft_llitoa_base((ssize_t)(va_arg(ap,ssize_t)),16, 1);

	// else if (str[e->i + 1] == 'x' && e->have_l == 0)
	// 	e->ito = ft_itoa_base((long long int)(va_arg(ap,long long int)),16, 0);
	// else //if (e->have_l == 0)
	// 	e->ito = ft_itoa_base((long long int)(va_arg(ap,long long int)),16, 1);
	// e->size = ft_strlen(e->ito);

	// int exa_size = hexa_size(e->ito);
	// ////////////////////////////____affichage_________________________________


	int sharp_size = 0;
	char c;
	int put_char = 0;
	if (e->zero > 0 && e->have_point == 0)
		c = '0';
	else 
		c = ' ';

	if (e->have_sharp != 0 && exa_size != 0  && exa_size != -1)//ft_atoi(e->ito) != 0)
	{
		if(((e->int_value <= e->size + 2)||(e->int_value > e->presition && e->have_point != 0) || (e->zero != 0)) && (e->zero == 0 || e->int_value == 0 || e->have_point == 0) )//(e->int_value == 0 || e->int_value <= e->presition + 2) || (e->zero != 0))
		{

			if (str[e->i + 1] == 'x')
				write(1,"0x",2);
			else
				write(1,"0X",2);
			e->nc += 2;
			e->have_sharp = 0;
			if (e->zero != 0 || e->int_value <= e->presition + 2)
				sharp_size = 2;
		}
		else
			sharp_size = 2;
		//e->size += 2;
	}

	if (exa_size == -1 && e->have_point != 0)
	{
			while(e->int_value > 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value--;
			}
		if(exa_size == -1 && e->presition > 0)
		{
			ft_putchar('0');
			e->nc++;
		}
		 	return(0);
	}

	if (e->have_point != 0)
	{
		
		int tmp;
		tmp =  e->presition;
		while(e->int_value > e->presition && e->zero != 0 && e->presition >= e->size + sharp_size)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value--;
			put_char++;

		}

		while(e->presition > e->size)
			{
				
				ft_putchar('0'); //c ou o
				e->nc++;
				e->presition--;
				put_char++;
			}
			e->presition =  tmp;
	}


	if (e->int_value == 0)// && e->have_point == 0)
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
				juste_print(str, e);
		}
		else if (e->int_value != 0 && e->have_point != 0)
		{
			if(e->have_neg == 0)
			{
				int sup;
				if (e->presition > e->size)
					sup = e->presition;
				else
					sup = e->size;
				while(e->int_value - sharp_size  - sup > 0)
				{
					ft_putchar(c);
					e->nc++;
					e->int_value--;
				}
			}
				juste_print(str, e);
			while(e->int_value + e->size + put_char  < 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value++;
			}
		}


	}
//   printf("\nyolo 10\n");

	return (0);
}

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
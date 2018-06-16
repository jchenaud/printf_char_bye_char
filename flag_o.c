/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:37:20 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/15 09:29:05 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int absol(int nb)
// {
// 	if (nb < 0 && nb != -2147483647)
// 		return (-nb);
// 	else if (nb > 0)
// 		return (nb);
// 	return (0); 

// }

static void juste_print(t_env *e)
{
	if (e->have_sharp != 0 && ft_atoi(e->ito) != 0)
	{
		ft_putchar('0');
		e->nc++;
	}
	if (ft_atoi(e->ito) != 0 || e->have_point == 0 || e->have_sharp != 0)
	{
		write(1,e->ito,e->size);
		e->nc += e->size;
	}
}

void  flag_o(va_list ap, t_env *e)
{
	// int size;
	// char *ito = NULL;

	//printf("chocola");
	char c;
	int size_sharp;
	int place_zero;
	place_zero = 0;

	if (e->ito)
	{
		free(e->ito);
		e->ito = NULL;
	}
	

	if (e->have_sharp != 0)
		size_sharp = 1;
	else
		size_sharp = 0;

	//if (e->have_l > 0)
		e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),8, 0);
//	else if (e->have_l == 0)
	//	e->ito = ft_itoa_base(va_arg(ap,int),8, 0);
	e->size = ft_strlen(e->ito);

	if (e->zero > 0 && ft_atoi(e->ito) != 0)
		c = '0';
	else 
		c = ' ';

	if (e->int_value == 0 && e->have_point == 0)//e->have_sharp == 0 && 
	{
		juste_print(e);
		return ;
	} 
	else
	{
		if (e->int_value > 0 && e->have_point == 0)
			e->int_value--;
		else if (e->int_value < 0)
		{	
			if (e->presition == 0 && ft_atoi(e->ito) == 0)
				;
			else
				e->int_value++;
			//if (e->have_point != 0 && e->)
			// 	e->int_value++;
		}
		if (e->have_point != 0 && ft_atoi(e->ito) != 0)// && absol(e->int_value) <= e->presition)// && e->int_value  )
		{
			while(e->presition > e->size)
			{
				ft_putchar('0');
				e->nc++;
				e->presition--;
				place_zero++;
			}
			
		}
	
			
			while (e->int_value - size_sharp - e->size >=  0 ) 
			{
				ft_putchar(c);
				e->nc++;
				e->int_value--;
			}
			juste_print(e);
			while (e->int_value + e->size + size_sharp + place_zero <= 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value++;
			}
	}
}
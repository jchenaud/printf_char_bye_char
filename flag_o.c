/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:37:20 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/18 14:10:19 by jchenaud         ###   ########.fr       */
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
	if (e->have_sharp != 0)
	{
		if ((ft_atoi(e->ito) != 0 )&& (e->have_point == 0 || e->size  >= e->presition ))
		{
			ft_putchar('0');
			e->nc++;
		}
		else if( e->have_point == 0 && e->int_value != 0)
		{
			ft_putchar(' ');
			e->nc++;
		}
	}
	if (ft_atoi(e->ito) != 0 || e->have_point == 0 || e->have_sharp != 0)
	{
		write(1,e->ito,e->size);
		e->nc += e->size;
	}
	else if (e->have_point != 0 && ft_atoi(e->ito) == 0 && e->int_value !=0 && e->presition == 0)
	{
		ft_putchar(' ');
		e->nc ++;
	}
}

void  flag_o(va_list ap, t_env *e)
{
	char c;
	int size_sharp;
	int place_zero;
	place_zero = 0;

	if (e->ito)
	{
		free(e->ito);
		e->ito = NULL;
	}
	
	if ((e->have_sharp) != 0)
		size_sharp = 1;
	else
		size_sharp = 0;

	e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),8, 0);
	e->size = ft_strlen(e->ito);

	if ((e->zero > 0) && (ft_atoi(e->ito) != 0 || (e->have_point == 0)))
		c = '0';
	else 
		c = ' ';

	if (e->int_value == 0 && e->have_point == 0)
	{
		juste_print(e);
		return ;
	} 
	else
	{
		if (e->int_value > 0 && e->have_neg != 0)
			e->int_value *=-1;
		int abs = e->int_value;
		if (e->int_value < 0)
			abs *=-1;
		if ((e->have_point != 0) && (e->presition > abs || e->presition > e->size))
		{
			if (e->presition < abs)
			{
				while(e->presition < e->int_value)
				{
					 if (e->have_neg == 0)
					 	ft_putchar(' ');
					 else
						ft_putchar(c);
					e->nc++;
					e->int_value--;
				}
			}
				int tmp_presition =  e->presition;
				while(e->presition > e->size)
				{
					ft_putchar('0');
					e->nc++;
					e->presition--;
					place_zero++;
				}
				while(ft_atoi(e->ito) == 0 && e->presition > 0 && e->int_value >= 0 && tmp_presition > 1 && e->have_sharp == 0)
				{
					ft_putchar('0');
					e->nc++;
					e->presition--;
				}
				e->presition =  tmp_presition;
		}
		if(e->have_neg == 0 )
		{
			if (c == '0' && e->have_point != 0  && e->presition == 0)
				c = ' '; 
			while (e->int_value - size_sharp - e->size - place_zero >  0)
			{
				ft_putchar(c);
				e->nc++;
				e->int_value--;
			}
		}
			juste_print(e);
			if (size_sharp == 1 && ft_atoi (e->ito) == 0 )
				size_sharp = 0;
			while (e->int_value + e->size + size_sharp + place_zero < 0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value++;
			}
	}
}
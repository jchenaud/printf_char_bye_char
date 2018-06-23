/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:07:29 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/23 23:26:36 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void flag_p(va_list ap , t_env *e)
{
	// char c;

	// if (e->zero != 0)
	// 	c = '0';
	// else
	// 	c = 'f';
	e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),16, 0);//ft_itoa_base(va_arg(ap, int),16 , 0);
	e->size = ft_strlen(e->ito);

if (e->zero == 0)//&& e->int_value >= e->int_value)
	while (e->int_value > e->size + 2)
	{
		e->int_value--;
		ft_putchar(' ');
		e->nc++;
	}


	if (ft_atoi(e->ito) != 0)
	{
		write(1,"0x",2);
		e->nc += 2;
		int i = 0;
		if (e->have_point != 0 && e->presition > e->int_value)
		{
			while(e->presition - e->size > 0)
			{
				ft_putchar('0');
				e->presition--;
				e->nc++;
			}
		}
		write(1, e->ito, e->size);
		e->nc += e->size;
		e->size += 2;
	}
	else
	{
		int pres;
		if(e->have_point != 0 && e->presition < 3 && e->presition > 0)
			pres = e->presition;
		else if (e->have_point != 0 && e->presition == 0)
			pres = 2;
		else
			pres = 3; 
		write(1,"0x0",pres);
		e->nc += pres;
		e->size = pres;
	}

	if (e->zero != 0)
		while (e->int_value > e->size)
		{
			e->int_value--;
			ft_putchar('0');
			e->nc++;
		}
	if(e->presition != 0 && e->presition > e->int_value)
		while(e->presition - (e->size - 2) > 0)
		{
			e->presition--;
			ft_putchar('0');
			e->nc++;
		}
	while (e->int_value + e->size < 0)
	{
		e->int_value++;
		ft_putchar(' ');
		e->nc++;
	}
}

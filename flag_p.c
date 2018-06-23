/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:07:29 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/22 23:32:20 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void flag_p(va_list ap , t_env *e)
{
	char c;

	if (e->zero != 0)
		c = '0';
	else
		c = 'f';
	e->ito = ft_llitoa_base((long long unsigned int)(va_arg(ap,long  long unsigned int)),16, 0);//ft_itoa_base(va_arg(ap, int),16 , 0);
	e->size = ft_strlen(e->ito);


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
		
		write(1, e->ito, e->size);
		e->nc += e->size;
		e->size += 2;
	}
	else
	{
		write(1,"0x0",3);
		e->nc += 3;
		e->size = 3;
	}
	while (e->int_value + e->size < 0)
	{
		e->int_value++;
		ft_putchar(' ');
		e->nc++;
	}
}

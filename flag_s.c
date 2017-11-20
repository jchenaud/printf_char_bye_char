/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:48:59 by jchenaud          #+#    #+#             */
/*   Updated: 2017/10/27 13:51:19 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void juste_write(t_env *e)
{
	write(1,e->string,e->size);
	e->nc += e->size;
}

void flag_s(t_env *e, va_list ap)
{
	e->string = va_arg(ap,char*);
	if(!e->string)
	{
		write(1,"(null)",6);
		e->nc += 6;
		return ;
	}
	e->size = ft_strlen(e->string);
	if (e->have_point != 0)
	{
		if (e->presition < e->size)
			e->size = e->presition;
	}
	if (e->int_value <= e->size && e->int_value >= 0)// && e->have_point == 0)
	{
		juste_write(e);
		return ;
	}
	if (e->int_value > e->size || e->int_value < 0)//&& e->have_point == 0)
	{
		while (e->int_value - e->size > 0)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value--;
		}
		juste_write(e);
		while (e->int_value + e->size < 0)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value++;
		}
	} 

}
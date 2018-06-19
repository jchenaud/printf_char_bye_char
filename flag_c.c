/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:48:34 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/15 10:36:40 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_c(t_env *e, va_list ap)
{	char c;

	if (e->zero != 0)
		c = '0';
	else
		c = ' ';
	e->c = va_arg(ap,int);
	while (e->int_value > 1)
	{
		ft_putchar(c);
		e->nc++;
		e->int_value--;
	}
	ft_putchar(e->c);
	while (e->int_value < -1)
	{
		ft_putchar(' ');
		e->nc++;
		e->int_value++;
	}
	e->nc++;
}
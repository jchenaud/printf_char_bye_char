/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:50:35 by jchenaud          #+#    #+#             */
/*   Updated: 2017/10/27 10:56:56 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void flag_pc(t_env *e)
{
	while (e->int_value - 1 > 0)
	{
		ft_putchar(' ');
		e->nc++;
		e->int_value--;
	}
	ft_putchar('%');
	e->nc++;
	while (e->int_value + 1 < 0)
	{
		ft_putchar(' ');
		e->nc++;
		e->int_value++;
	}
}
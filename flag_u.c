/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:50:40 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/15 15:15:53 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int difzero(char *n, int s)
// {
// 	if (ft_atoi(n) == 0 && s == 1)
// 		return (0);
// 	return (1);
// }

static void juste_print(t_env *e)
{
	write(1,e->ito,e->size);
	e->nc += e->size;
}


void  flag_u(va_list ap, t_env *e , char u)
{
	if (e->ito)
	{
		free(e->ito);
		e->ito = NULL;
	}
//write(1,"coucou",6);

	if (u == 'U')
		e->have_l++;

	if (e->have_l == 0 && e->have_j == 0)
		e->ito = ft_itoa_base_large(((unsigned int)va_arg(ap,unsigned int)),10, 0);
	else if (e->have_h != 0 && e->have_l == 0)
		e->ito = ft_itoa_base_large(((short unsigned int)va_arg(ap, unsigned int)),10, 0);
	else if (e->have_l == 1 && e->have_j == 0)
		e->ito = ft_itoa_base_large(((unsigned long int)va_arg(ap,unsigned long int)),10, 0);
	else if (e->have_l == 2 && e->have_j == 0)
		e->ito = ft_itoa_base_large(((unsigned long long int)va_arg(ap,unsigned long long int)),10, 0);
	else if (e->have_l == 0 && e->have_j == 1)
		e->ito = ft_itoa_base_large(((uintmax_t)va_arg(ap,uintmax_t)),10, 0);
	// if (!e->ito)
	// 	return ;
	e->size = ft_strlen(e->ito);
	char c;
	c = (e->zero != 0)? '0' : ' ';
	// if (e->presition > e->size || e->presition <= e->int_value)
	// {
		while(e->int_value - e->size - e->presition > 0)
		{
			e->int_value--;
			ft_putchar(c);
			e->nc++;
		}
		while(e->presition - e->size > 0)
		{
			e->presition--;
			ft_putchar('0');
			e->nc++;
		}

	juste_print(e);
	while(e->int_value + e->size < 0)
	{
		e->int_value++;
		ft_putchar(' ');
		e->nc++;
	}
}
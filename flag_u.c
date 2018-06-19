/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:50:40 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/17 11:19:39 by jchenaud         ###   ########.fr       */
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
	if (e->have_z == 0)
	{
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
	}
	else
		e->ito = ft_itoa_base_large(((ssize_t)va_arg(ap,ssize_t)),10, 0);
	 
	 if (e->have_point != 0 && e->presition == 0 && ft_atoi(e->ito) == 0)
	 	return ;


	e->size = ft_strlen(e->ito);
	char c;
	c = (e->zero != 0)? '0' : ' ';
	if (e->presition > e->int_value || e->presition == 0)
	{
		int tmp = e->int_value;
		while(e->int_value - e->size - e->presition > 0)
		{
			e->int_value--;
			ft_putchar(c);
			e->nc++;
		}
		e->int_value = tmp;
		tmp = e->presition;
		while(e->presition - e->size > 0)
		{
			e->presition--;
			ft_putchar('0');
			e->nc++;
		}
		e->presition = tmp;
	}
	else{
		int tmp = e->int_value;
		while(e->int_value > e->presition && e->int_value > e->size)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value--;
		}
		e->int_value = tmp;
		tmp = e->presition;
		while(e->presition - e->size > 0)
		{
			e->presition--;
			ft_putchar('0');
			e->nc++;
		}
		e->presition = tmp;

	}

	juste_print(e);
	//printf("presition = %d e->int_value = %d\n",e->presition,e->int_value);
	if (e->int_value < 0 && (e->int_value * -1) > e->presition)
	{
		while(e->int_value + e->size < 0)// && (e->presition < e->int_value)) // && (e->have_neg != 0)) //|| e->have_neg != 0))
		{
			e->int_value++;
			ft_putchar(' ');
			e->nc++;
		}
	}
}
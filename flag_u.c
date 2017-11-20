/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:50:40 by jchenaud          #+#    #+#             */
/*   Updated: 2017/11/20 15:55:43 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int difzero(char *n, int s)
{
	if (ft_atoi(n) == 0 && s == 1)
		return (0);
	return (1);
}

static void juste_print(t_env *e)
{
	write(1,e->ito,e->size);
	e->nc += e->size;
}


void  flag_u(va_list ap, t_env *e , char u)
{
	// if (e->ito)
	// {
	// 	free(e->ito);
	// 	e->ito = NULL;
	// }
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


// 	e->size = ft_strlen(e->ito);
// 	if(e->ito[0] == '-')
// 		e->ito_neg = 1;
// 	else
// 		e->ito_neg = 0;
// 	int modi_size;
// 	int mod_pres;
// 	char c;

// 	modi_size = 0;
// 	mod_pres = 0;

// 	if(e->have_space != 0 && ft_atoi(e->ito) > 0 && e->have_posi == 0 && e->have_point == 0)
// 	{
// 		ft_putchar(' ');
// 		e->nc++;
// 	}


// else if (difzero(e->ito,e->size) == 0)
// 	{
// 		while(e->int_value > e->presition)
// 		{
// 			ft_putchar(' ');
// 			e->int_value--;
// 			e->nc++;
// 			modi_size++;
// 		}
// 		while(e->presition > 0)
// 		{
// 			ft_putchar('0');
// 			e->presition--;
// 			e->nc++;
// 			modi_size++;
// 		}
// 	}


// 	if (e->ito_neg == 0)
// 	{
// 		if (e->zero > 0 && ft_atoi(e->ito) != 0 && e->presition == 0)
// 			c = '0';
// 		else 
// 			c = ' ';

// 		if((e->have_point != 0) && ( e->int_value <= 0 || e->int_value < e->presition))
// 		{
// 			int tmp = modi_size;
// 			if(e->have_posi != 0 && ft_atoi(e->ito) != 0 )
// 			{
// 				ft_putchar('+');
// 				e->nc++;
// 				e->have_posi = 0;
// 				tmp++;
// 			}
// 			while(e->presition - e->size - modi_size > 0)
// 			{
// 				ft_putchar('0');
// 				e->nc++;
// 				e->presition--;
// 				tmp++;
// 			}
// 			modi_size = tmp;
// 		}
// 		else if (e->have_point != 0  && e->presition > e->size && ft_atoi(e->ito) != 0)
// 			mod_pres = e->presition - e->size;	
// 		if(e->have_posi > 0 && ft_atoi(e->ito) >= 0 )
// 		{
// 			if (c == '0')
// 			{
// 				ft_putchar('+');
// 				e->nc++;
// 				e->have_posi = 0;
// 			}
// 			modi_size++;
// 		}
// 		while(e->int_value - e->size - modi_size - mod_pres > 0)
// 		{// printf("c[%c]\n",c );
// 			ft_putchar(c);
// 			e->nc++;
// 			e->int_value--;
// 		}
// 		if(e->have_posi != 0 && ft_atoi(e->ito) >= 0 && c == ' ')
// 		{
// 			ft_putchar('+');
// 			e->nc++;
// 			modi_size++;
// 		}
// 		if (mod_pres != 0)
// 		{
// 			while (mod_pres > 0)
// 			{
// 				ft_putchar('0');
// 				mod_pres--;
// 				e->nc++;
// 			}
// 		}
// 		juste_print(e);
// 		while(e->int_value + e->size  + modi_size < 0)
// 		{
// 			ft_putchar(' ');
// 			e->nc++;
// 			e->int_value++;
// 		}
// 	}
// 	else
// 	{
// 		if ((e->zero > 0 && ft_atoi(e->ito) != 0) && (e->presition == 0 || e->presition < e->int_value))
// 			c = '0';
// 		else 
// 			c = ' ';
// 		//printf("c [%c]\n",c );
// 		if((e->have_point != 0) && ( e->int_value <= 0 || e->int_value < e->presition))
// 		{
// 			int tmp = modi_size;


// 			if(ft_atoi(e->ito) < 0 && e->ito_neg == 1)
// 			{
// 				ft_putchar('-');
// 				e->presition++;
// 				e->ito_neg = 2;
// 				e->nc++;
// 			}


// 			while(e->presition - e->size - modi_size > 0)
// 			{
// 				ft_putchar('0');
// 				e->nc++;
// 				e->presition--;
// 				tmp++;
// 			}
// 			modi_size = tmp;
// 		}
// 		else if (e->have_point != 0  && e->presition > e->size && ft_atoi(e->ito) != 0)
// 			mod_pres = e->presition - e->size;	
	

// 		if (c == '0' && ft_atoi(e->ito) < 0 && e->ito_neg == 1)
// 		{
// 			ft_putchar('-');
// 			e->ito_neg = 2;
// 			e->nc++;
// 		}

// 		while(e->int_value - e->size - modi_size - mod_pres > 0)
// 		{// printf("c[%c]\n",c );
// 			ft_putchar(c);
// 			e->nc++;
// 			e->int_value--;
// 		}
		
// 		if(ft_atoi(e->ito) < 0 && e->ito_neg == 1)
// 		{
// 			ft_putchar('-');
// 			e->ito_neg = 2;
// 			e->nc++;
// 		}
// 		if (mod_pres != 0)
// 		{
// 			while (mod_pres > 0)
// 			{
// 				ft_putchar('0');
// 				mod_pres--;
// 				e->nc++;
// 			}
// 		}
// 		juste_print(e);
// 		while(e->int_value + e->size  + modi_size < 0)
// 		{
// 			ft_putchar(' ');
// 			e->nc++;
// 			e->int_value++;
// 		}
// 		//printf("juste_nega");

// 	}
}
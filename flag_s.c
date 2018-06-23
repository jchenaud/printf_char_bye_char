/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:48:59 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/23 16:33:01 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void juste_write(t_env *e,char flag)
{
	//si s basi go write 
	if (flag == 's')
	{
		write(1,e->string,e->size);
		e->nc += e->size;
	}
	else
	{
	//ft_printf("size  = %d \n",e->size);
		//ft_putstr("coucou\n");
		int i;
		i = 0;
		int add = 0;

		while(i < e->size)
		{ 
			add = 0;
			if (e->have_point != 0)
			{
				e->presition -= size_wchar(e->string_wc[i]);
				if(e->presition < 0)
					return ;
			}
			add = print_wchar(e->string_wc[i]);
			i++;
			// if (e->have_neg != 0)
			// {
			// 	e->int_value += add;
			// }
			e->nc += add; 
		}
	//	ft_putstr("coucou2\n");

	}
}

void flag_s_min(t_env *e ,va_list ap , char flag, char c)
{
	e->string = va_arg(ap,char*);
	
	if(!e->string)
		e->string = "(null)";
	e->size = ft_strlen(e->string);
	if (e->have_point != 0)
	{
		if (e->presition < e->size)
			e->size = e->presition;
	}
	if (e->int_value <= e->size && e->int_value >= 0)// && e->have_point == 0)
	{
		juste_write(e,flag);
		return ;
	}
	if (e->int_value > e->size || e->int_value < 0)//&& e->have_point == 0)
	{
		while (e->int_value - e->size > 0)
		{
			ft_putchar(c);
			e->nc++;
			e->int_value--;
		}
		juste_write(e,flag);
		while (e->int_value + e->size < 0)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value++;
		}
	} 
}


void flag_s_maj(t_env *e ,va_list ap , char flag)
{
  e->string_wc = va_arg(ap,wchar_t *);
	
	if(!e->string_wc)
		e->string_wc = L"(null)";
	e->size = ft_strlen_wchar(e->string_wc);
	if (e->have_point != 0)
	{
		if (e->presition < e->size)
			e->size = e->presition;
	}
	if (e->int_value <= e->size && e->int_value >= 0)// && e->have_point == 0)
	{
		juste_write(e,flag);
		return ;
	}
	if (e->int_value > e->size || e->int_value < 0)//&& e->have_point == 0)
	{
		//printf("e-.size %d \n",e->size);
		int char_can_print_size = 0 ;
		int i = 0;
		int tmp_p = e->presition;
		int tmp_s = e->size;
		int k;
		//char_can_print++; 
		if (e->have_point != 0)
		{
			while(i < e->size)
			{ 
				k = size_wchar(e->string_wc[i]);
				e->presition -= k;
				if(e->presition < 0)
					break ;
				i++;
				char_can_print_size += k; 
			}
		}
		else{
			while(i < e->size)
			{ 
				k = size_wchar(e->string_wc[i]);
				char_can_print_size += k; 

				  if(e->int_value - char_can_print_size < 0)
					  	break ;
				i++;
			}
		}
			while (e->int_value  - char_can_print_size >  0)
			{
				ft_putchar(' ');
				e->nc++;
				e->int_value--;
			}
			e->presition = tmp_p;
			e->size = tmp_s;
		
		juste_write(e,flag);
		while (e->int_value + e->size < 0)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value++;
		}
	} 
}


void flag_s(t_env *e, va_list ap, char flag)
{
	char c;
	if (e->zero != 0)
		c = '0';
	else
		c = ' ';
	if(flag == 's' && e->have_l != 0)
		flag = 'S';

	if(flag == 's')
		flag_s_min(e ,ap ,flag,c);
	else
		flag_s_maj(e ,ap ,flag);
	

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_uni_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:53:56 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/23 14:59:25 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_uputchar(wchar_t c)
// {

// 	char *s[4];
// 	//printf("%d\n",c );
// 	if ((unsigned int) c <= 127)
// 		ft_putchar((unsigned int)c);
// 	else
// 	{
// 		long long unsigned int
// 		printf("%u\n",(unsigned int)c );
// 		//unsigned int hexa_big;
// 		//hexa_big = ft_llitoa_base((unsigned int)c, 16, 0);

// 	}
// 	if (c <= 0x7FF)
// 	{
// 		s[0] = (c >> 6) + 0xC0;
// 		s[1] = (c & 0x3F) + 0x80;

// 		//return (2);
// 	}
// 	if (c <= 0xFFFF)
// 	{
// 		s[0] = (c >> 12) + 0xE0;
// 		s[1] = ((c >> 6) & 0x3F) + 0x80;
// 		s[2] = (c & 0x3F) + 0x80;
// 	//	return (3);
// 	}
// 	s[0] = (c >> 18) + 0xF0;
// 	s[1] = ((c >> 12) & 0x3F) + 0x80;
// 	s[2] = ((c >> 6) & 0x3F) + 0x80;
// 	s[3] = (c & 0x3F) + 0x80;
// 	//return (4);
// 	// if ((unsigned int)c < 2048)
// 	// {
// 	// 	ft_putchar(192 | ((unsigned int)c >> 6));
// 	// 	ft_putchar(128 | ((unsigned int)c & 63));
// 	// }
// 	// else if ((unsigned int)c < 65536)
// 	// {
// 	// 	ft_putchar(224 | ((unsigned int)c >> 12));
// 	// 	ft_putchar(128 | (((unsigned int)c >> 6) & 63));
// 	// 	ft_putchar(128 | ((unsigned int)c & 63));
// 	// }
// 	// else if ((unsigned int)c < 1114112)
// 	// {
// 	// 	ft_putchar(240 | ((unsigned int)c >> 18));
// 	// 	ft_putchar(128 | (((unsigned int)c >> 12) & 63));
// 	// 	ft_putchar(128 | (((unsigned int)c >> 6) & 63));
// 	// 	ft_putchar(128 | ((unsigned int)c & 63));
// 	// }
// }


int 	size_wchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		if (MB_CUR_MAX >= 1)
			return (1);
	}
	else if (c <= 0x7FF)
	{
		if (MB_CUR_MAX >= 2)
			return (2);
	}
	else if (c <= 0xFFFF)
	{
		if (MB_CUR_MAX >= 3)
			return (3);
	}
	else if(c <= 0x10FFFF)
	{
		if (MB_CUR_MAX >= 4)
			return (4);
	}
	return(0);
	
}

int		print_wchar(wchar_t c)
{
	 //if (c < 0)
		//return (0);
	if (c <= 0x7F)
	{
		if (MB_CUR_MAX >= 1)
		{
			ft_putchar(c);
			return (1);
		}
	}
	else if (c <= 0x7FF)
	{
		if (MB_CUR_MAX >= 2)
		{
			ft_putchar((c >> 6) + 0xC0);
			ft_putchar((c & 0x3F) + 0x80);
			return (2);
		}
	}
	else if (c <= 0xFFFF)
	{
		if (MB_CUR_MAX >= 3)
		{
			ft_putchar((c >> 12) + 0xE0);
			ft_putchar(((c >> 6) & 0x3F) + 0x80);
			ft_putchar((c & 0x3F) + 0x80);
			return (3);
		}
	}
	else if(c <= 0x10FFFF)
	{
		if (MB_CUR_MAX >= 4)
		{
			ft_putchar((c >> 18) + 0xF0);
			ft_putchar(((c >> 12) & 0x3F) + 0x80);
			ft_putchar(((c >> 6) & 0x3F) + 0x80);
			ft_putchar((c & 0x3F) + 0x80);
			return (4);
		}
		return (0);
	}
	return (-1);

	//}
}


int flag_uni_c(t_env *e, va_list ap,char flag)
{	

	//print_unicode(ap,)
	

		// printf("debut\n");

	char c;
	wchar_t wc;


	if (e->zero != 0)
		c = '0';
	else
		c = ' ';
	// if (flag == 'C' || e->have_l != 0)
		wc = va_arg(ap,wchar_t);
	// else
	// 	wc = (unsigned char)va_arg(ap,int);


	if( (wc > 0xD7FF && wc < 0xE000) || (wc > 0x2FFFF && wc < 0xE0000) || (wc > 0x10FFFF) )//if (wc == 256 || wc == 0XBFFE)
	{
		//printf("chity value\n");
		e->nc = -1;
		return (-1); // doit metre fin et retourner -1
	}
	// int size_modif = 0;
	// if (flag == 'C' || e->have_l != 0)
	// 	size_modif = size_wchar(wc);
	// if(size_modif < 0)
	// 	size_modif = 0;

	while (e->int_value > 1)//size_modif)
	{
		ft_putchar(c);
		e->nc++;
		e->int_value--;
	}
	int add = 0;
	if (flag == 'C' || e->have_l != 0)
	{
		if (wc < 0)
		{
			e->nc = -1;
			return (-1);
		}
		// if (e->have_point != 0)
		// {

		// }
		// else
			add = print_wchar(wc);
		//printf("value  : %d\n", wc);
	}
	else
	{
		ft_putchar(wc);
		add++;
	}

	if (add ==  -1)
	{
		//printf("yolo\n");
		e->nc = -1;
		return (-1);
	}
	while (e->int_value  + (add -1) < -1)
	{
		ft_putchar(' ');
		e->nc++;
		e->int_value++;
	}
	e->nc += add;
	// printf("fin \n");
	return (0);
}
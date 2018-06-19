/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_uni_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:53:56 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/19 16:04:09 by jchenaud         ###   ########.fr       */
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


int		print_wchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		ft_putchar(c);
		return (1);
	}
	if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
		return (2);
	}
	if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		return (3);
	}
	// else if(0xFFFFFFFF)
	// {
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
		return (4);

	//}
}


void flag_uni_c(t_env *e, va_list ap)
{	

	//print_unicode(ap,)
	


	char c;
	wchar_t wc;


	if (e->zero != 0)
		c = '0';
	else
		c = ' ';
	wc = va_arg(ap,wchar_t);
	if (wc == 256 || wc == 0XBFFE)
	{
		return ; // doit metre fin et retourner -1
	}

	while (e->int_value > 1)
	{
		ft_putchar(c);
		e->nc++;
		e->int_value--;
	}
	int add = print_wchar(wc);
	while (e->int_value < -1)
	{
		ft_putchar(' ');
		e->nc++;
		e->int_value++;
	}
	e->nc += add;
}
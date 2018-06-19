/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:55:36 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/19 13:17:25 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputchar(wchar_t c)
{
	if ((unsigned int)c < 2048)
	{
		ft_putchar(192 | ((unsigned int)c >> 6));
		ft_putchar(128 | ((unsigned int)c & 63));
	}
	else if ((unsigned int)c < 65536)
	{
		ft_putchar(224 | ((unsigned int)c >> 12));
		ft_putchar(128 | (((unsigned int)c >> 6) & 63));
		ft_putchar(128 | ((unsigned int)c & 63));
	}
	else if ((unsigned int)c < 1114112)
	{
		ft_putchar(240 | ((unsigned int)c >> 18));
		ft_putchar(128 | (((unsigned int)c >> 12) & 63));
		ft_putchar(128 | (((unsigned int)c >> 6) & 63));
		ft_putchar(128 | ((unsigned int)c & 63));
	}
}

// void ft_uputchar(wchar_t c)
// {

// }
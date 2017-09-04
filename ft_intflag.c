/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 23:34:43 by jchenaud          #+#    #+#             */
/*   Updated: 2017/09/04 06:43:56 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int ft_intflag_value(const char *str,unsigned int i, t_env *e)
// {
// 	char *int_flag;
// 	int k;
// 	int nb;

// 	k = 0;
// 	nb = 0;
// 	int_flag = "1234567890.-";

// }

int ft_have_val(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] && str[i] != '0')
		return (1);
	return(0);
}

int ft_inc_intflag(int nb,t_env *e)
{
	int neg;
	int c;
	int n;

	neg = 0;
	c = 1;
	n = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb *= -1;
		neg = 1;
	}
	else if (nb == -2147483648)
		return (11);
	if (n < 1000000000)
	{
		while (c <= nb)
		{
			c *= 10;
			n++; 
		}
		return (n + neg + e->zero);
	}
	return(11);


}

int int_flag_find(const char *str,unsigned int i)
{
	char *int_flag;
	int f;

	f = 0;
	int_flag = "1234567890.";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f])
		return (1);
	return (0);


}

int ft_int_flag_return_value(const char *str,unsigned int i,t_env *e)
{
	char *int_flag;
	int nb;
	int f;
	
	f = 0;
	int_flag = "1234567890.-";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f] && int_flag[f] != '.')
	{
		nb = ft_atoi(&str[i+1]);
		while (str[i+1] == '0')
		{
			e->zero++;
			i++;
		}
		return (nb);
	}
	else if (int_flag[f] == '.')
	{
		e->have_point = 1;
	}
	return (0);

}
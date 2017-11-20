/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 23:34:43 by jchenaud          #+#    #+#             */
/*   Updated: 2017/11/14 11:53:15 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



// else if (str[e->i + 1] == 'o')
// 		{
// 			//ft_printf("yo[4]");
// 			// if (e->int_value < 0 || e->have_int == 0)
// 			// {
// 				//ft_printf("yo");
// 				o_flag(str, ap, e);
// 				// if (e->have_int = 0)
// 				// {
// 					if (nb >= e->size)  // ya deux nb 
// 					{
// 						//if (e->have_int = 0 || e->int_value < nb)

// 							e->nc += nb;
// 						while(nb > e->size)
// 						{
// 							ft_putchar('0');
// 							nb--;
// 						}
// 					}
// 					else 
// 					{
// 						e->nc += e->size;
// 					}
// 			}
// 		//ft_pr//intf("yo");
// 			// ft_printf("yo[5]");
// 			// 	write(1, e->ito, e->size);
// 			// ft_printf("yo[6]");
// 			//e->i++;

// 			// }


// static int ft_intflag_value(const char *str,unsigned int i, t_env *e)
// {
// 	char *int_flag;
// 	int k;
// 	int nb;

// 	k = 0;
// 	nb = 0;
// 	int_flag = "1234567890.-";

// }

int char_is_flag(char c)
{
	char *flag;
	int i;

	i = 0;
	flag = "sSpdDioOuUxXcC%";
	while (flag[i] && flag[i] != c)
		i++;
	if (flag[i])
		return(1);
	return(0);
}

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

int ft_inc_intflag(int nb)
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
		// ft_printf("0 = [%d]",e->zero);
		// ft_printf("decalge de = [%d]",n + neg + e->zero);
		return (n + neg); //+ e->zero);
	}
	return(11);


}

char next_flag(const char *str, int i)
{
	char *int_flag;
	int f;
	int k;

	k = 0;
	int_flag = "1234567890.-  ";
	while (str[i+k])
	{
		f = 0;
		while (str[i + k] != int_flag[f] && int_flag[f])
			f++;
		if(!(int_flag[f]))
			return (str[i+k]);
		k++;
	}
	return (0);

}

int int_flag_find(const char *str,unsigned int i)
{
	char *int_flag;
	int f;

	f = 0;
	int_flag = "1234567890-";//.";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f])
		return (1);
	return (0);
}

int int_flag_find_without_zero(const char *str,unsigned int i)
{
	char *int_flag;
	int f;

	f = 0;
	int_flag = "123456789-";//.";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f])
		return (1);
	return (0);
}

// int int_flag_find2(char c)
// {
// 	char *int_flag;
// 	int f;

// 	f = 0;
// 	int_flag = "1234567890-";//.";
// 	while (c != int_flag[f] && int_flag[f])
// 		f++;
// 	if (c == int_flag[f] && int_flag[f])
// 		return (1);
// 	return (0);
// }

int have_modi_flag(char c)
{
	int	 i;
	char *modi_flag;

	i = 0;
	modi_flag = " #.lhj+-0z";//-";
	//printf("char c [%c]\n",c);
	while (modi_flag[i] && c != modi_flag[i])
		i++;
	if(modi_flag[i] && c  == modi_flag[i])
		return (1);
	return (0);


}

int ft_int_flag_return_value(const char *str,unsigned int i,t_env *e)
{
	char *int_flag;
	int nb;
	int f;
	
	f = 0;
	int_flag = "1234567890-";//.-";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f] && int_flag[f] != '.')
	{
		nb = ft_atoi(&str[i+1]);
		if (nb < 0)
			i++;
		if (str[i+1] == '0')
		{
		  	e->zero++;
		  	//i++;
		}
		// if (str[i + 1] == '.')
		// 	e->have_point = 1;
		return (nb);
	}
	// else if (int_flag[f] == '.')
	// 	e->have_point = 1;
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nega_itobase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:41:27 by jchenaud          #+#    #+#             */
/*   Updated: 2017/10/29 11:33:08 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(unsigned long nbr, int base)
{
	int i;

	i = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}
// static int	ft_size(unsigned int nbr, int base)
// {
// 	int i;

// 	i = 1;
// 	while (nbr  >  base)
// 	{
// 		nbr = nbr / base;
// 		i++;
// 	}
// 	return (i);
// }

static void	ft_recursive_min(char *str, unsigned int nbr, int base, int i)
{
	char *t;

	t = "0123456789abcdef";
	if (i > 0)
		ft_recursive_min(str, nbr / base, base, i - 1);
	str[i - 1] = t[nbr % base];
}

static void	ft_recursive_maj(char *str, unsigned int nbr, int base, int i)
{
	char *t;

	t = "0123456789ABCDEF";
	if (i > 0)
		ft_recursive_maj(str, nbr / base, base, i - 1);
	str[i - 1] = t[nbr % base];
}

char		*ft_neg_itoa_base(int nbr, int base, char maj)
{
	int		nb;
	char	*str;
	int neg;
	neg = 0;

	if (nbr == -2147483648)
	{
			//str = (char *)malloc(sizeof(*str) * 11);
			//str = "-2147483648";
			return(ft_strdup("-2147483648"));
	}
	if(nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	nb = ft_size(nbr, base);
	
	str = (char *)malloc(sizeof(*str) * nb + 1 +neg);
	if (str == NULL)
		return (NULL);
	if (maj == 0)
		ft_recursive_min(str, nbr, base, nb);
	else
		ft_recursive_maj(str, nbr, base, nb);
	str[nb] = '\0';
	if(neg == 1)
		str = ft_strjoinc_free('-', str, 1);
	return (str);
}
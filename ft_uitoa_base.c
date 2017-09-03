/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeahoare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:28:32 by jeahoare          #+#    #+#             */
/*   Updated: 2017/04/10 05:22:54 by jeahoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ull	ft_lenght(unsigned long long nbr, int base)
{
	signed int s_i;

	s_i = 1;
	while (nbr >= (unsigned long long)base)
	{
		nbr /= base;
		s_i++;
	}
	return (s_i);
}

static char		*ft_recur(t_ull nbr, int base, char *s, int maj)
{
	char				*bs;
	int					counter;
	unsigned long long	tmp;

	tmp = nbr;
	counter = ft_lenght(tmp, base) - 1;
	bs = (maj == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	while (counter >= 0)
	{
		s[counter--] = bs[(tmp % base)];
		tmp /= base;
	}
	return (s);
}

char			*ft_uitoa_base(t_ull nbr, int base, int maj)
{
	char *s;

	s = (char *)malloc((sizeof(*s) * ft_lenght(nbr, base)) + 1);
	if (s == NULL)
		return (NULL);
	s[ft_lenght(nbr, base)] = 0;
	if ((s = ft_recur(nbr, base, s, maj)) == NULL)
		return (NULL);
	return (s);
}

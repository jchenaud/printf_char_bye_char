/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strposchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:49:05 by jchenaud          #+#    #+#             */
/*   Updated: 2016/12/14 15:38:32 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strposchr(const char *s, int c)
{
	int i;

	i = -1;
	if (s == NULL)
		return (0);
	while (s[++i] != c && s[i])
		;
	if (s[i] != c)
		return (1);
	return (i);
}

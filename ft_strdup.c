/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:38:54 by jchenaud          #+#    #+#             */
/*   Updated: 2017/10/29 13:51:51 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	i = 0;
	size = ft_strlen(s) + 1;
	tab = (char*)malloc(sizeof(*tab) * (size));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

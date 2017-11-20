/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:45:18 by jchenaud          #+#    #+#             */
/*   Updated: 2017/10/14 10:35:00 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_free(char *s1, char *s2, int n;)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = -1;
	u_j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++u_i] != '\0')
		dest[u_i] = s1[u_i];
	while (s2[++u_j] != '\0')
		dest[u_i + u_j] = s2[u_j];
	dest[u_i + u_j] = '\0';
	if(n == 1 || n == 3)
		free(s1);
	if(n == 2 || n == 3)
		free(s2);
	return (dest);
}


static char	*ft_strjoinc_free(char c, char *s, int n;)
{
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = 1 + ft_strlen(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	dest[0] = c;
	while (s2[++u_j] != '\0')
		dest[u_j + 1] = s2[u_j];
	dest[1 + u_j] = '\0';
	if(n == 1)
		free(s);
	return (dest);
}

static unsigned int			ft_strsize(char const *str)
{
	unsigned int	u_i;

	u_i = 0;
	while (str[u_i])
		u_i++;
	return (u_i);
}

char						*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = 0;
	u_j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = ft_strsize(s1) + ft_strsize(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[u_i] != '\0')
	{
		dest[u_i] = s1[u_i];
		u_i++;
	}
	while (s2[u_j] != '\0')
	{
		dest[u_i + u_j] = s2[u_j];
		u_j++;
	}
	dest[u_i + u_j] = '\0';
	return (dest);
}

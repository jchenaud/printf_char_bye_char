/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:03:23 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/12 11:29:59 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int u_i;

	if (!s1 || !s2)
		return (0);
	u_i = 0;
	while (s1[u_i] == s2[u_i] && s1[u_i] && s2[u_i])
		u_i++;
	if (s1[u_i] != s2[u_i])
		return (0);
	return (1);
}
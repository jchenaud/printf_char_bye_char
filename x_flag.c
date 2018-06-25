/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 07:14:40 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 11:53:46 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		juste_print(const char *str, t_env *e)
{
	if (e->have_sharp == 1 && hexa_size(e->ito) > 0)
	{
		if (str[e->i + 1] == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		e->nc += 2;
	}
	write(1, e->ito, e->size);
	e->nc += e->size;
}

int				hexa_size(const char *str)
{
	int i;
	int have_oly_zero;

	have_oly_zero = 1;
	i = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') ||
		(str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f')))
	{
		if (str[i] != '0')
			have_oly_zero = 0;
		i++;
	}
	if (i == 0 || have_oly_zero == 0)
		return (i);
	return (-1);
}

static void		x_sharp(t_env *e, const char *str)
{
	if (e->have_sharp == 1 && e->exa_size != 0 && e->exa_size != -1)
	{
		if (((e->int_value <= e->size + 2) ||
		(e->int_value > e->presition && e->have_point == 1) || (e->zero != 0))
				&& (e->zero == 0 || e->int_value == 0 || e->have_point == 0))
		{
			if (str[e->i + 1] == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
			e->nc += 2;
			e->have_sharp = 0;
			if (e->zero != 0 || e->int_value <= e->presition + 2)
				e->sharp_size = 2;
		}
		else
			e->sharp_size = 2;
	}
}

static int		x_point_zero(t_env *e)
{
	if (e->exa_size == -1 && e->have_point == 1)
	{
		while (e->int_value > 0)
			ft_putchar_nc_sup_int(' ', &e->int_value, e);
		if (e->exa_size == -1 && e->presition > 0)
			ft_putchar_nc('0', e);
		return (0);
	}
	return (1);
}

static void		x_poin(t_env *e, int *put_char, const char *str)
{
	int tmp;

	if (e->have_point == 1)
	{
		tmp = e->presition;
		while (e->int_value > e->presition &&
				e->zero != 0 && e->presition >= e->size + e->sharp_size)
			ft_putchar_nc_int_sint(' ', &(*put_char), &e->int_value, e);
		if (!(e->int_value > 0 && e->int_value < e->presition))
			while (e->presition > e->size &&
					(e->presition > e->int_value && e->int_value >= 0))
				ft_putchar_nc_int_sint('0', &(*put_char), &e->presition, e);
		e->presition = tmp;
	}
	if (e->int_value == 0)
		juste_print(str, e);
}

static void		x_normal_end(t_env *e, int *put_char, char c, const char *str)
{
	int sup;

	if (e->have_neg == 0)
	{
		if (e->presition > e->size)
			sup = e->presition;
		else
			sup = e->size;
		while (e->int_value - e->sharp_size - sup > 0)
			ft_putchar_nc_sup_int(c, &e->int_value, e);
		while (e->presition > e->exa_size)
			ft_putchar_nc_int_sint('0', &(*put_char), &e->presition, e);
	}
	juste_print(str, e);
	while (e->int_value + e->size + (*put_char) < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}

static void		x_normal(t_env *e, int *put_char, char c, const char *str)
{
	if (e->have_point == 0)
	{
		while (e->int_value - e->size - e->sharp_size > 0)
			ft_putchar_nc_sup_int(c, &e->int_value, e);
		juste_print(str, e);
		while (e->int_value + e->size + e->sharp_size < 0)
			ft_putchar_nc_int(' ', &e->int_value, e);
	}
	else if (e->int_value != 0 && e->have_point == 1)
		x_normal_end(e, &(*put_char), c, str);
}

int		x_flag(const char *str, va_list ap, t_env *e)
{
	char	c;
	int		put_char;

	put_char = 0;
	e->sharp_size = 0;
	if (str[e->i + 1] == 'x')
		take_value_x_min(ap, e);
	else
		take_value_x_maj(ap, e);
	e->exa_size = hexa_size(e->ito);
	if (e->zero > 0 && e->have_point == 0)
		c = '0';
	else
		c = ' ';
	x_sharp(e, str);
	if (x_point_zero(e) == 0)
		return (0);
	x_poin(e, &put_char, str);
	if (e->int_value != 0)
		x_normal(e, &put_char, c, str);
	return (0);
}

void	int_flag(const char *str, t_env *e)
{
	int nb;

	nb = ft_int_flag_return_value(str, e->i, e);
	e->i += ft_inc_intflag(nb);
	if (e->have_point == 1)
	{
		if (nb > 0)
			e->presition = nb;
		else
			e->presition = 0;
	}
	else
	{
		if (e->have_neg)
			nb *= -1;
		e->int_value = nb;
	}
}

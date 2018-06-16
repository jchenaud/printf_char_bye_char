
//#include "ft_printf.h"
#include "includes/ft_printf.h"
#include <stdio.h>

void ft_init(t_env *e)
{

	e->presition = 0;
	e->int_value = 0;

	e->have_sharp = 0;
	e->have_l = 0;
	e->have_int = 0;
	e->have_point = 0;

	e->have_neg = 0;
	e->have_write = 0;
	e->have_posi = 0;
	e->have_space = 0;
	e->zero = 0;
	e->sub_n_zero = 0;
	e->have_h = 0;
	e->have_j = 0;
	e->have_z = 0;
	e->ito_neg = 0;

	if (e->ito != NULL)
	{
		free(e->ito);
		e->ito = NULL;
	}
}
int ft_protect(char *str, t_env *e)
{
	if (!str[e->i+1])
		return (-1);

	if (e->have_l != 0 && e->have_h != 0)
	{
		if (str[e->i + 1] == 'd')
		{
			e->have_h = 0;
			return(0);
		}
		else
			return(-1);
	}



	if (e->have_j != 0 && e->have_h != 0 && str[e->i + 1] != 'd')
				return(-1);
	if (e->have_j != 0 && e->have_h != 0)
	{
	 	e->have_h = 0;
	 	return(0);
	 }

	if (e->have_j != 0 && e->have_z != 0 && str[e->i + 1] != 'd')
		return(-1);
	 if (e->have_j != 0 && e->have_z != 0)
	{
	 	e->have_z = 0;
	 	return(0);
	 }
	if (e->have_h != 0 && e->have_z != 0)
	{
		e->have_h = 0;
		return(0);
	}
	
	return (0);
}

void ft_modif_flag(const char * str, t_env *e)
{
	while (have_modi_flag(str[e->i+1]) == 1)
	{

		if (str[e->i + 1] == ' ')
			e->have_space++;
		else if (str[e->i + 1] == '#')
			e->have_sharp = 1;
		else if (str[e->i + 1] == '.')
			e->have_point = 1;
		else if (str[e->i + 1] == 'l')
			e->have_l++;
		else if (str[e->i + 1] == 'h')
			e->have_h++;
		else if (str[e->i + 1] == 'j')
			e->have_j++;
		else if(str[e->i + 1] == '+')
			e->have_posi++;
		else if(str[e->i + 1] == 'z')
			e->have_z++;
		else if(str[e->i + 1] == '0') // y a une coquille 
		{
			while (str[e->i + 1] == '0')
				e->i++;
			e->i--;
			e->zero++;
		}
		else if(str[e->i + 1] == '-')
		{
			if (int_flag_find_without_zero(str, e->i + 1, e) == 1)
				return ;
			e->have_neg++;

			
		}
		if (str[e->i + 1])
			e->i++;
		else
			return ;
	}
}

int ft_check_flag(const char *str, unsigned int init, va_list ap, t_env *e)
{

	if (init == 1)
	{
		ft_init(e);
		init = 0;
	}
	ft_modif_flag(str, e);
	if (ft_protect(str, e) == -1)
		return (-1);

	if (str[e->i + 1] == '%')
	{
		flag_pc(e);
		return(0);
	}
	else if(str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
	{
		x_flag(str, ap, e);
		return (0);
	}
	else if (str[e->i + 1] == 'o' || str[e->i + 1] == 'O' )
	{
		flag_o(ap ,e);
		return (0);
	}
	else if (str[e->i + 1] == 'd' || str[e->i + 1] == 'i' || str[e->i + 1] == 'D')
	{
		if ( str[e->i + 1] == 'D')
			e->have_l = 2;
		flag_d(ap ,e);
		return (0);
	}
	else if (str[e->i + 1] == 's')
	{
		flag_s(e, ap);
		return (0);
	}
	else if (str[e->i + 1] == 'c')
	{
		flag_c(e,ap);
		return (0);
	}
	else if (str[e->i + 1] == 'u' || str[e->i + 1] == 'U')
	{
		flag_u( ap, e, str[e->i + 1]);
		return (0);
	}
	else if (str[e->i + 1] == 'p')
	{
		flag_p(ap, e);
		return (0);
	}
	else if(int_flag_find(str, e->i) == 1)
	{
		int_flag(str, e);
		ft_check_flag(str, 0, ap, e);
		return (0);
	}else
	{
		ft_putchar(str[e->i + 1]);
		e->nc++;
	}
	return(0);

}

//faire une fonction itsflague_int ...


int ft_end(t_env *e)
{
	int nb_char;

	nb_char = e->nc;
	if (e->ito)
	{
		//ft_printf("");
		free(e->ito);
		e->ito = NULL;
	}
	return (nb_char);
}

int	ft_printf(const char *str, ...)
{
	static t_env e;
	va_list ap;

	e.ito = NULL;
	e.string = NULL;
	e.nc = 0;
	e.i = 0;
	if (!(str[0]))
		return (0);
	va_start(ap, str);
	ft_init(&e);
	while ((str[e.i] && str[e.i] != '%') || (e.i == 0))
	{
		if (e.i != 0 || str[e.i] != '%')
		{
			write(1, &str[e.i], 1);
			e.nc++;
		}
		if (str[e.i] != '%')
			e.i++;
		while (str[e.i] && str[e.i] == '%')
		{
			if (str[e.i + 1])
			{
				if (ft_check_flag(str, 1, ap, &e) == -1)
				{	
					va_end(ap);
					return (ft_end(&e));
				}
			}
			else
				return (e.nc);
			e.i = e.i + 2;
		}
	}
	va_end(ap);
	return (ft_end(&e));
	//printf("\n");
}

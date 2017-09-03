
#include "ft_printf.h"
#include <stdio.h>
int ft_check_flag(const char *str, unsigned int i,va_list ap,t_env *e)
{
	if (str[e->i + 1] == 's' || str[e->i + 1] == 'S')
	{
		char *string;
		string = va_arg(ap,char*);
		write(1,string,ft_strlen(string));
		e->nc += ft_strlen(string);
	}
	else if (str[e->i + 1] == 'c' || str[e->i + 1] == 'C')
	{
		char c; 
		c = va_arg(ap,int);
		write(1,&c,1);
		e->nc++;
	}
	else if (str[e->i + 1] == 'd')
	{
		int k;
		k = va_arg(ap,int);
		ft_putnbr(k,e);
	}
	else if (str[e->i + 1] == '%')
	{
		ft_putchar('%');
		e->nc++;
	}
	else if (str[e->i + 1] == 'p')
	{
		void *ptr;
		ptr = va_arg(ap,void *); // a convertire en exa
		ft_putnbr(ptr);

	}
	else if (str[e->i + 1] == 'x')
	{
		int size;
		char *ito;

		ito = ft_itoa_base(va_arg(ap,int),16, 0);
		size = ft_strlen(ito);
		write(1,ito,size);
		e->nc += size; 
	}
	else if (str[e->i + 1] == 'X')
	{
		int size;
		char *ito;

		ito = ft_itoa_base(va_arg(ap,int),16, 1);
		size = ft_strlen(ito);
		write(1,ito,size);
		e->nc += size; 
	}
	else
	{
///////////////////////////////////////////////////////////////////////////////////////autre func pour opti
	e->have_point = 0;
	int k;
	int nb;

	k = 0;
	nb = ft_int_flag_return_value(str,e->i,e);
	if ( nb != 0)
	{
		e->i += ft_inc_intflag(nb);
		if (nb > 0)
		{
			//printf(" str \n", str[i]);
			 if (str[e->i + 1] != '%')
			 	k++;
			while (nb - k > 1)
			{
				ft_putchar(' ');
				e->nc++;
				nb--;
			}
			//printf("str %c\n",str[e->i+1]);
			 if (str[e->i] != '%')
			{
				ft_check_flag(str,e->i,ap,e);
				return (0);
			}
			ft_putchar('%');
		}
		else
		{
			if (str[e->i + 1] != '%')
			{
				ft_check_flag(str,e->i,ap,e);
				k++;
			}
			else
				ft_putchar('%');
			while (nb + k < -1)
			{
				ft_putchar(' ');
				e->nc++;
				nb++;
			}
				e->nc++;

		}
		//e->nc++;
	}
	else if (e->have_point == 1)
	{
		e->i++;
		while (int_flag_find(str,e->i + 1) == 1)
			e->i++;
		e->i++;
		ft_putchar('%');
		e->nc++;

		
	}

	// int k;
	// int f;
	// f = 0;
	// k = 0;
	// char *int_flag;
	// //printf("debug\n");
	// ft_int_flag_return_value(str,i,e);
	// int_flag = "1234567890.-";
	// while (str[i + 1] != int_flag[f] && int_flag[f])
	// 	f++;
	// if (str[i + 1] == int_flag[f] && int_flag[f])
	// {
	// 	if (int_flag[k] != '.')
	// 	{
	// 		if(str[i + 2] && str[i + 2] == '%')
	// 			while (((int)int_flag[f]) - 48 - k > 1)
	// 			{
	// 				k++;
	// 				ft_putchar(' ');
	// 				e->nc++;
	// 			}
	// 		ft_putchar(str[i+2]);
	// 		e->nc++;
	// 	}
	// }
}
	return (0);

}

//faire une fonction itsflague_int ...


int ft_printf(const char *str, ...)
{
	t_env *e;
	va_list ap;
	

	e = (t_env *)malloc(sizeof(t_env));
	e->nc = 0;
	//unsigned int nc;

	// unsigned int i;
	e->i = 0;
	va_start(ap, str);
	if (!(str[0]))
		return(0);
	//printf("str[i]=%c\n",str[i]);

	while ((str[e->i] && str[e->i] != '%') || (e->i == 0))
	{
		if (e->i != 0 || str[e->i] != '%')// || (!str[1]))
		{
			write(1,&str[e->i],1);
		e->nc++;
			//printf ("coucou\n");
		}
		if(str[e->i] != '%')
			e->i++;
	//printf("str[i]=%c\n",str[i]);

		while(str[e->i] == '%'  && str[e->i])
		{		
	//printf("str[i]=%c\n",str[i]);

			if(str[e->i+1] != '\0')
			{
	//printf("debug\n");

				while(str[e->i+1] == ' ')
					e->i++;
				ft_check_flag(str,e->i,ap,e);
			}
			else
				return(e->nc);
			e->i = e->i+2;
		}
	}
	return (e->nc);

}
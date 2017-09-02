
#include "ft_printf.h"
int ft_check_flag(const char *str, unsigned int i,va_list ap)
{
	//while(str[i+1] && str[i + 1] == ' ')
	//	i++;
	// if(str[i+1] == ' ')
	// 	return(1);
	// if(str[i + 1] == '\0')
	// 	return (0);
	if (str[i + 1] == 's' || str[i + 1] == 'S')
	{
		char *string;
		string = va_arg(ap,char*);
		write(1,string,ft_strlen(string));
	}
	else if (str[i + 1] == 'c' || str[i + 1] == 'C')
	{
		char c; 
		c = va_arg(ap,int);
		write(1,&c,1);
	}
	else if (str[i + 1] == 'd')
	{
		int k;
		k = va_arg(ap,int);
		ft_putnbr(k);
	}
	else if (str[i + 1] == '%')
		ft_putchar('%');
	else if (str[i + 1] == 'p')
	{
		void *ptr;
		ptr = va_arg(ap,void *);
		ft_putnbr(ptr);

	}
		return (0);

}


int ft_printf(const char *str, ...)
{
	//t_env *e;
	va_list ap;

	unsigned int i;
	i = 0;
	va_start(ap, str);

	while (str[i] && str[i] != '%')
	{
		write(1,&str[i],1);
		i++;
		while(str[i] == '%' && str[i])
		{
			while(str[i+1] == ' ')
				i++;
			ft_check_flag(str,i,ap);
			i = i+2;
		}
	}
	return (0);

}
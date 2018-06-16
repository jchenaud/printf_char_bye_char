
#include "ft_printf.h"

static int	ft_size(intmax_t nbr, int base)
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

static void	ft_recursive_min(char *str, intmax_t nbr, int base, int i)
{
	char *t;

	t = "0123456789abcdef";
	if (i > 0)
		ft_recursive_min(str, nbr / base, base, i - 1);
	str[i - 1] = t[nbr % base];
}

static void	ft_recursive_maj(char *str, intmax_t nbr, int base, int i)
{
	char *t;

	t = "0123456789ABCDEF";
	if (i > 0)
		ft_recursive_maj(str, nbr / base, base, i - 1);
	str[i - 1] = t[nbr % base];
}

char		*ft_neg_litoa_base(intmax_t nbr, int base, char maj)
{
	int		nb;
	char	*str;
	int neg;
	neg = 0;
	//printf("[%lld]\n",nbr);
	if (nbr == LONG_MIN)
	{
		//str = (char *)malloc(sizeof(*str) * 21);
		//str = "-9223372036854775808";
		str = ft_strdup("-9223372036854775808");
		return(str);
	}
	if(nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	nb = ft_size(nbr, base);
	//write(1,"coucou2\n",8);
	
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
	//write(1,"coucou3\n",8);

	//rintf("[%s]\n",str);
	return (str);
}
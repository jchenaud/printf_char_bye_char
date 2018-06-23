/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:50:27 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/23 23:39:24 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int difzero(char *n, int s)
{
	if (ft_atoi(n) == 0 && s == 1)
		return (0);
	return (1);
}

static void juste_print(t_env *e)
{
	// if (ft_atoi(e->ito) == 0 && e->zero == 0)
	// {

	// }
	// if (ft_atoi(e->ito) >= 0 || e->ito_neg != 0)// || e->zero == 0)
	// {
		if (e->have_point == 0 && difzero(e->ito,e->size) == 0)
		{
			write(1,e->ito,e->size);
			e->nc++;
		}
		else if(difzero(e->ito,e->size) == 1)
		{
			if (e->ito_neg == 1 ||  e->ito_neg == 0)
			{
				write(1,e->ito,e->size);
				e->nc += e->size;
			}
			else if (difzero(e->ito,e->size) == 1)
			{
				write(1,&e->ito[1],e->size-1);
				e->nc += e->size - 1;
			}
		}
		
	//}
	// else
	// {
	// 	write(1,&e->ito[1],e->size-1);
	// 	e->nc += e->size - 1;
	// }
	//printf("WTF\n");/////////////////////;

}


void  flag_d(va_list ap, t_env *e)
{
	//write(1,"coucou\n",7);

	if (e->ito != NULL)
	{
		free(e->ito);
		e->ito = NULL;
	}
 // long long int value;

	// value =  va_arg(ap,   long long int);


if(e->have_l >= 2)
 		e->ito =  ft_neg_litoa_base((long long int)(va_arg(ap,long long int)),10,0);
 	else if(e->have_l == 1)
 		e->ito =  ft_neg_litoa_base((long int)(va_arg(ap,long int)),10,0);
 	else if (e->have_j != 0)
 		e->ito =  ft_neg_litoa_base((intmax_t)(va_arg(ap,intmax_t)),10,0);
 	else if (e->have_z != 0)
 		e->ito = ft_neg_litoa_base((size_t)(va_arg(ap,size_t)),10,0);
 	else if (e->have_h == 1)
 		e->ito = ft_neg_litoa_base((short int)(va_arg(ap,int)),10,0);
 	else if (e->have_h > 1)
 		e->ito = ft_neg_litoa_base((signed char)(va_arg(ap,int)),10,0);
 	else
 		e->ito =  ft_neg_litoa_base((int)(va_arg(ap,int)),10,0);

	e->size = ft_strlen(e->ito);
	if(e->ito[0] == '-')
		e->ito_neg = 1;
	else
		e->ito_neg = 0;
	int modi_size;
	int mod_pres;
	char c;

	modi_size = 0;
	mod_pres = 0;

	if(e->have_space != 0 && ft_atoi(e->ito) > 0 && e->have_posi == 0 && e->have_point == 0)
	{
		ft_putchar(' ');
		e->nc++;
		modi_size++;
	}



 if (difzero(e->ito,e->size) == 0) //|| (e->have_point != 0)difzero(e->ito,e->size) == 1)// || e->zero != 0)
	{
		if (e->have_point != 0 && e->int_value > e->presition)
		{
			ft_putchar(' ');
			e->nc++;
		}
		if (e->have_space != 0)
		{
				ft_putchar(' ');
			e->nc++;
			modi_size++;
		}

		if(e->zero != 0 && e->have_posi != 0 && e->int_value > 0 && e->have_point == 0)
		{
			ft_putchar('+');
			e->nc++;
			while(e->int_value - 1 > 0)
			{
				ft_putchar('0');
				e->nc++;
				e->int_value--;
			}
			return ;
		}
		if(e->zero != 0 && e->have_posi != 0 && e->int_value > 0 && e->have_point != 0 && e->presition < e->int_value)
		{
			e->nc += e->int_value - 1;
			while(e->int_value - e->presition - 2 > 0)
			{
				ft_putchar(' ');
				e->int_value--;
			}
			ft_putchar('+');
			e->int_value--;
			while(e->int_value - 1 > 0)
			{
				ft_putchar('0');
				e->int_value--;
			}
			return ;
		}
		// if(e->zero != 0 && e->have_posi == 0 && e->int_value > 0 && e->have_point == 0 && e->have_space)
		// {

		// }
		//if(e-)
	//	if (e->have_point != 0 && e->presition == 0)

// 		int tmp_intval;
// 		int tmp_pres;
// 		tmp_intval = e->int_value; 
// 		tmp_pres =  e->presition;

// 		if (e->have_posi != 0 && e->int_value <= 0)
// 		{
// 			ft_putchar('+');
// 			e->nc++;
// 			modi_size++;
// 			e->have_posi = 0;
// 			e->int_value--;
// 		}
// 		//printf("e->int val  = %d\n",e->int_value );
// 		if (e->presition > 1)
// 			e->presition -= 1;
// 		while(e->int_value - 1 - e->presition > 0)
// 		{
// 			if(e->have_point == 0 && e->zero != 0)
// 				ft_putchar('0');
// 			else
// 				ft_putchar(' ');
// 			e->int_value--;
// 			e->nc++;
// 			modi_size++;
// 		}
// 		if (e->presition > 0)
// 			e->presition++;
// 		while(e->presition > 0)
// 		{
// 			ft_putchar('0');
// 			e->presition--;
// 			e->nc++;
// 			modi_size++;
// 		}
// 		if (e->have_point == 0)
// 			ft_putchar('0');
// 		else if(tmp_pres == 0 && tmp_intval != 0)
// 			ft_putchar(' ');
// 		else
// 			e->nc--;
// 		e->nc++;

// 		while(e->int_value + 1 < 0)
// 		{
// 			if(e->have_point == 0 && e->zero != 0)
// 				ft_putchar(' ');
// 			else
// 				ft_putchar(' ');
// 			e->int_value++;
// 			e->nc++;
// 			modi_size++;
// 		}
// 		return ;
}
	// on peut elever tout les dif de zero



	if (e->ito_neg == 0)
	{
		if ((e->zero > 0) && ( (ft_atoi(e->ito) != 0 && e->presition == 0) || (ft_atoi(e->ito) == 0 && ((e->have_point == 0 ||( e->have_point != 0 && e->presition != 0) )))))
			c = '0';
		else 
			c = ' ';

		//printf("c =  %c\n",c );
		if((e->have_point != 0) && ( e->int_value <= 0 || e->int_value < e->presition))
		{
			int tmp = modi_size;
			if(e->have_posi != 0)// && ft_atoi(e->ito) != 0 )
			{
				ft_putchar('+');
				e->nc++;
				e->have_posi = 0;
				tmp++;
			}
			while(e->presition - e->size - modi_size > 0)
			{
				ft_putchar('0');
				e->nc++;
				e->presition--;
				tmp++;
			}
			modi_size = tmp;
		}
		else if (e->have_point != 0  && e->presition > e->size)// && ft_atoi(e->ito) != 0) //&& ft_atoi(e->ito) != 0)
			mod_pres = e->presition - e->size;	
		if(e->have_posi > 0 && ft_atoi(e->ito) >= 0 )
		{
			if (c == '0')
			{
				ft_putchar('+');
				e->nc++;
				e->have_posi = 0;
			}
			modi_size++;
		}
		while(e->int_value - e->size - modi_size - mod_pres > 0)
		{// printf("c[%c]\n",c );
			ft_putchar(c);
			e->nc++;
			e->int_value--;
		}
		if(e->have_posi != 0 && ft_atoi(e->ito) >= 0 && c == ' ')
		{
			if ((e->have_point == 0 || e->presition < e->int_value))// au debut ft_atoi(e->ito) == 0 &&  hve point || (ft_atoi(e->ito) != 0) || 
			{
				ft_putchar('+'); // BUG
				e->nc++;
				modi_size++;
			}
		}
		if (mod_pres != 0)
		{
			while (mod_pres > 0)
			{
				ft_putchar('0');
				mod_pres--;
				e->nc++;
			}
		}
		juste_print(e);
		if (e->int_value < 0 && e->have_posi != 0)
		{
			ft_putchar(' ');
			e->nc++;
			
		}
		while(e->int_value + e->size  + modi_size < 0)
		{ 
			//ft_putchar('0');

			ft_putchar(' ');
			e->nc++;
			e->int_value++;
		}
		//printf("neg =  %d posi = %d\n",e->have_neg,e->have_posi );
		
	}
	else
	{
		if ((e->zero > 0 ) && (e->presition == 0 || e->presition < e->int_value)) // dans premiere parantese && ft_atoi(e->ito) != 0
			c = '0';
		else 
			c = ' ';
		//printf("c [%c]\n",c );
		if((e->have_point != 0) && ( e->int_value <= 0 || e->int_value < e->presition))
		{
			int tmp = modi_size;


			// if(ft_atoi(e->ito) < 0)// && e->ito_neg == 1)
				ft_putchar('-');
				e->presition++;
				e->ito_neg = 2;
				e->nc++;

			while(e->presition - e->size - modi_size > 0)
			{
				ft_putchar('0');
				e->nc++;
				e->presition--;
				tmp++;
			}
			modi_size = tmp;
		}
		else if (e->have_point != 0  && e->presition > e->size) //&& ft_atoi(e->ito) != 0)
			mod_pres = e->presition - e->size +1;	
	

		if (c == '0' && ft_atoi(e->ito) < 0 && e->ito_neg == 1)
		{
			ft_putchar('-');
			e->ito_neg = 2;
			e->nc++;
		}

		while(e->int_value - e->size - modi_size - mod_pres > 0)
		{// printf("c[%c]\n",c );
			ft_putchar(c);
			e->nc++;
			e->int_value--;
		}
		
		if(e->ito_neg == 1)
		{
			ft_putchar('-');
			e->ito_neg = 2;
			e->nc++;
		}
		if (mod_pres != 0)
		{
			while (mod_pres > 0)
			{
				ft_putchar('0');
				mod_pres--;
				e->nc++;
			}
		}
		juste_print(e);
		while(e->int_value + e->size  + modi_size < 0)
		{
			ft_putchar(' ');
			e->nc++;
			e->int_value++;
		}
		//printf("juste_nega");
	}

}
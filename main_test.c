# include "ft_printf.h"
# include <stdio.h>
int main()
{
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("salut\n");
	printf("salut\n");
	printf("//////////////////////////////////////////////////////////\n");
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("salut %s bye\n","cocorico");
//	printf("//////////////////////////////////////////////////////////\n");
	printf("salut %s bye\n","cocorico");
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("salut %c%s%d\n",'c',"oco",-54);
	printf("salut %c%s%d\n",'c',"oco",-54);
	printf("//////////////////////////////////////////////////////////\n");
	printf("salut %%%s\n","salut");
	ft_printf("salut %%%s\n","salut");
	printf("//////////////////////////////////////////////////////////\n");
	printf("//////////////////////////////////////////////////////////\n");
	printf("salut %    %%s\n","salut");
	ft_printf("salut %    %%s\n","salut");
	printf("//////////////////////////////////////////////////////////\n");
	printf("//////////////////////////////////////////////////////////\n");
	printf("[%p]\n","salut");
	ft_printf("[%p]\n","salut");
		printf("//////////////////////////////////////////////////////////\n");
	printf("//////////////////////////////////////////////////////////\n");
ft_printf("\n");
printf("\n");
printf("//////////////////////////////////////////////////////////\n");
		printf("%5%");
		printf("//////////////////////////////////////////////////////////\n");
		ft_printf("%5%");
		printf("//////////////////////////////////////////////////////////\n");

		//ft_printf("[ %5% ]\n");
		//printf("[ %5% ]\n");
		printf("//////////////////////////////////////////////////////////\n");
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("%-5%");
	printf("//////////////////////////////////////////////////////////\n");
	printf("%-5%");
	printf("//////////////////////////////////////////////////////////\n");
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("%.0%");
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("%x", 42);
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("%10x", 42);
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("%lx", 4294967296);
	printf("//////////////////////////////////////////////////////////\n");

	 ft_printf("%010x", 542);
	printf("//////////////////////////////////////////////////////////\n");
	
	ft_printf("%5%");
	printf("//////////////////////////////////////////////////////////\n");
ft_printf("%#llx", 9223372036854775807);
	printf("//////////////////////////////////////////////////////////\n");
	ft_printf("%#x", 0);
	printf("//////////////////////////////////////////////////////////\n");
	


}
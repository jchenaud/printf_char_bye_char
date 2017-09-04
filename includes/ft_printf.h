#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct  s_env
{
	va_list ap;
	unsigned int nc; // le nobre decaractere afficher
	unsigned int i;  // pose sur str

	int have_point;
	int zero;


	int have_sharp;
	int have_l;
	int para_value;
	char *ito;
	
}				t_env;


char		*ft_itoa_base(unsigned int nbr, int base, char maj);
char		*ft_llitoa_base(long long unsigned int nbr, int base, char maj);

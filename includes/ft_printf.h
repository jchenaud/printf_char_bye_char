#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct  s_env
{
	va_list ap;
	unsigned int nc; // le nobre decaractere afficher
	unsigned int i;  // pose sur str

	int have_point;
	
}				t_env;


char		*ft_itoa_base(unsigned int nbr, int base, char maj);
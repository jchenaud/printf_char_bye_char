#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <wchar.h>
#include <stdlib.h>

typedef struct  s_env
{
	va_list ap;
	unsigned int nc; // le nobre decaractere afficher
	unsigned int i;  // pose sur str

	int have_point;
	int have_space;
	int have_posi;
	int have_int;

	int int_value;
	int presition;

	int zero;

	int have_neg;// si il ya au moin 1 moins 
	int ito_neg;
	int neg;// le nobre de -
	int have_sharp;
	int have_h;
	int have_l;
	int have_j;
	int have_z;
	int para_value;
	char *ito; // regler sur sa taille maxe 
	int size;
	int have_write;
	int sub_n_zero;



	char *string;
	wchar_t *string_wc;

	char c;
	int k; // just int value of %d
	//int comme_arg;

	
}				t_env;

int			ft_printf(const char *str, ...);


char		*ft_itoa_base(unsigned int nbr, int base, char maj);
char		*ft_neg_itoa_base(int nbr, int base, char maj);
char		*ft_itoa_base_large(uintmax_t nbr, int base, char maj);

//char		*ft_neg_litoa_base(long long int nbr, int base, char maj);
char		*ft_neg_litoa_base(intmax_t nbr, int base, char maj);

char		*ft_llitoa_base(long long unsigned int nbr, int base, char maj);
int 		x_flag(const char *str, va_list ap, t_env *e);
void		int_flag(const char *str, t_env *e); 
char 		next_flag(const char *str,int i);
int			have_modi_flag(const char c);
char		*ft_strjoinc_free(char c, char *s, int n);

char		*ft_strdup(const char *);

void		flag_pc(t_env *e);
void		flag_s(t_env *e, va_list ap, char flag);
void		flag_c(t_env *e, va_list ap);
void		flag_o(va_list ap, t_env *e,char flag);
void		flag_d(va_list ap, t_env *e);
void 		flag_u(va_list ap, t_env *e , char u);
void 		flag_p(va_list ap , t_env *e);



int 		int_flag_find(const char *str,unsigned int i); // retourn 1 si ya des monbre dans le flag
int 		int_flag_find_without_zero(const char *str,unsigned int i,t_env *e);
int			ft_int_flag_return_value(const char *str,unsigned int i,t_env *e);
int			ft_inc_intflag(int nb);
int 		flag_uni_c(t_env *e, va_list ap, char flag);



int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
void 		ft_uputchar(wchar_t c);

int 		hexa_size(const char *str);
//static 	int absol(int nb)













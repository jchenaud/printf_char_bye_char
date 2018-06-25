

typedef struct		s_env
{
	va_list			ap;

	unsigned int	nc;
	unsigned int	i;
	int				have_point;
	int				have_space;
	int				have_posi;
	int				have_int;
	int				int_value;
	int				presition;
	int				zero;
	int				have_neg;
	int				ito_neg;
	int				neg;
	int				have_sharp;
	int				have_h;
	int				have_l;
	int				have_j;
	int				have_z;
	int				para_value;
	char			*ito;
	int				size;
	int				have_write;
	int				sub_n_zero;
	char			*string;
	wchar_t			*string_wc;
	char			c;
	int				k;
	int				exa_size;
	int				sharp_size;
	int				tmp_p;
	int				tmp_s;
	int				ret;
}					t_env;

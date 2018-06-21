
#include "ft_printf.h"

char	*ft_strjoin_free(char *s1, char *s2, int n)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = -1;
	u_j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++u_i] != '\0')
		dest[u_i] = s1[u_i];
	while (s2[++u_j] != '\0')
		dest[u_i + u_j] = s2[u_j];
	dest[u_i + u_j] = '\0';
	if(n == 1 || n == 3)
	{
		free(s1);
		s1 = NULL;
	}
	if(n == 2 || n == 3)
	{
		free(s2);
		s2 = NULL;
	}
	return (dest);
}


char	*ft_strjoinc_free(char c, char *s, int n)
{
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_j = -1;
	if (s == NULL)
		return (NULL);
	u_size = 1 + ft_strlen(s);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	dest[0] = c;
	while (s[++u_j] != '\0')
		dest[u_j + 1] = s[u_j];
	dest[1 + u_j] = '\0';
	// if(n == 1)
	// {
	// 	free(s);
	// 	s = NULL;
	// }
//printf("\n DEST adress = %p\n",dest);

	return (dest);
}

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}

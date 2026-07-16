#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = f(s[i]);
		i++;
	}
	return (out);
}

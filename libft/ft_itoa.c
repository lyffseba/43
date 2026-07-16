#include "libft.h"

static size_t	int_len(int n)
{
	size_t	len;
	long	v;

	v = n;
	len = (v <= 0);
	if (v < 0)
		v = -v;
	while (v > 0)
	{
		v /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	v;

	len = int_len(n);
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	v = n;
	if (v < 0)
	{
		s[0] = '-';
		v = -v;
	}
	if (v == 0)
		s[0] = '0';
	s[len] = '\0';
	while (v > 0)
	{
		s[--len] = (char)('0' + (v % 10));
		v /= 10;
	}
	return (s);
}

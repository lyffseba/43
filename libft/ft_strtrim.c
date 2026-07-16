#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\n'
			|| s[end - 1] == '\t'))
		end--;
	return (ft_strsub(s, (unsigned int)start, end - start));
}

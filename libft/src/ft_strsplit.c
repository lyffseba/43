#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	n;
	int		in_word;

	n = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			n++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (n);
}

static char	*next_word(char const **s, char c)
{
	size_t		len;
	char const	*start;
	char		*word;

	while (**s == c)
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = ft_strsub(start, 0, len);
	*s += len;
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < words)
	{
		tab[i] = next_word(&s, c);
		if (!tab[i])
		{
			while (i > 0)
				ft_strdel(&tab[--i]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

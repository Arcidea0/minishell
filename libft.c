
#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return ((size_t)i);
}

int	ft_strchr(const char *str, int b)
{
	int	i;

	i = 0;
	while (str && str[i] != (char)b)
		if (!str[i++])
			return (-1);
	return (i);
}

int	ft_strcmp(const char *a, const char *b)
{
	size_t	m;
	size_t	len;

	m = 0;
	if (!a && !b)
		return (0);
	if (ft_strlen(a) > ft_strlen(b))
		len = ft_strlen(a);
	else
		len = ft_strlen(b);
	while (a && b && a[m] && b[m] && m < len)
	{
		if (a[m] != b[m])
			return ((unsigned char)a[m] - (unsigned char)b[m]);
		m++;
	}
	if (m != len)
		return ((unsigned char)a[m] - (unsigned char)b[m]);
	return (0);
}

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	size_t		m;

	m = 0;
	if (!a && !b)
		return (0);
	while (a[m] && b[m] && m < n)
	{
		if (a[m] != b[m])
			return ((unsigned char)a[m] - (unsigned char)b[m]);
		m++;
	}
	if (m != n)
		return ((unsigned char)a[m] - (unsigned char)b[m]);
	return (0);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	*ft_strdup(const char *s1)
{
	char			*s2;
	unsigned int	i;

	s2 = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

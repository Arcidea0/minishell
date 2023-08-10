#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return ((size_t)i);
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
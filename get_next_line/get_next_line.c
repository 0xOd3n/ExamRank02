#include "get_next_line.h"
#include <stdio.h>

int		ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s != '\0' && s++)
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int			i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 1);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int			i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i] != '\0')
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_next_line(char **line)
{

	return (0);
}

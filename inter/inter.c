#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
		if (*s == '\0' && c == '\0')
			return ((char *)s);
	}
	return (0);
}
void	*ft_memchr(const void *s, int c, size_t n)
{
	while (*(char *)s != '\0' && n--)
	{
		if (*(char *)s == c)
			return ((char *)s);
		s++;
		if (*(char *)s == '\0' && c == '\0')
			return ((char *)s);
	}
	return(0);
}
int	main(int argc, char **argv)
{
	char	*str;
	size_t	n;

	n = 0;
	if (argc == 3)
	{
		str = argv[1];
		while (*str != '\0')
		{
			if (ft_strchr(argv[2], *str) && !(ft_memchr(argv[1], *str, n++)))
				write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

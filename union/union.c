/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:41:30 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/08 13:54:22 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)--s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*start;
	char	*aux;
	size_t	n;
	size_t	len;

	n = 0;
	if (argc == 3)
	{
		len = ft_strlen(argv[1]) + ft_strlen(argv[2]) + 2;
		start = argv[1];
		aux = start;
		while (n < len)
		{
			if (*aux != '\0' && !ft_memchr(start, *aux, n))
				write(1, aux, 1);
			aux++;
			n++;
		}
	}
	return(write(1, "\n", 1));
}

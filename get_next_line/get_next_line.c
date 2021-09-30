/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:50:22 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/30 14:11:03 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*aux;
	int		i;

	i = 0;
	aux = (char *)malloc(sizeof(char) * (n + ft_strlen(s1)));
	while (*s1)
		aux[i++] = *s1++;
	while (n--)
		aux[i++] = *s2++;
	return (aux);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		rd;
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	int		i;

	i = 0;
	aux = 0;
	rd = 1;
	line = ft_strdup("");
	while (rd > 0 && line)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd > 0)
		{
			while (*buffer && *buffer != '\n')
				i++;
			aux = line;
			line = ft_strnjoin(aux, buffer, i);
			free(aux);
		//FALTA ITERAR BUFFER HASTA DESPUÉS DE LO COPIADO EN LINE
		}
	}
	return (line);
}

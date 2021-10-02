/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:50:22 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/02 18:47:05 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*nwline(char *s)
{
	printf("Entra\n");
	while (*s && *s != '\n')
		s++;
	if (*s == '\0')
		return (0);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*stat[1024];
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	char		*aux;
	char		*newline;
	int			rd;
//PROBLEMAS CON FUNCIÓN NWLINE
	rd = 1;
	aux = 0;
// Line siempre debe estar alojado al empezar
	line = ft_strdup("");
// Si no se ha inicializado la estática, se aloja una cadena vacía
	if (!stat[fd])
		stat[fd] = ft_strdup("");
// Leemos el fd y lo almacenamos en stat hasta que stat llegue al salto de línea 
// o rd llegue al EOF
	newline = nwline(stat[fd]);
	while (!newline && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		aux = stat[fd];
		stat[fd] = ft_strjoin(stat[fd], buffer);
		free(aux);
		newline = nwline(stat[fd]);
	}
//Buscamos el salto de línea nuevamente
	newline = nwline(stat[fd]);
// Si hay salto de línea, copiamos stat en line solo hasta el salto de línea, es
// decir, hasta el resultado de newline - stat[fd]. Cuidado no añadir un + 1.
	if (*newline)
	{
		aux = line;
		line = ft_strnjoin(line, stat[fd], (newline - stat[fd]));
		free(aux);
	// Movemos stat hasta una posición después del salto de línea
		aux = stat[fd];
		stat[fd] = ft_strdup(newline + 1);
		free(aux);
	}
// Si no hay salto de línea copiamos todo stat en line y liberamos stat
	else if (!*newline)
	{
		aux = line;
		line = ft_strjoin(line, stat[fd]);
		free(aux);
	}
	return (line);
}

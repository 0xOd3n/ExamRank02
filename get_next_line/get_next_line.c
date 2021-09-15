/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:50:22 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/15 14:57:45 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		rd;
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;

	aux = 0;
	rd = 1;
	line = ft_strdup("");
	while (rd > 0 && line)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd > 0)
		{
			aux = line;
			line = ft_strjoin(aux, buffer);
			free(aux);
		}
	}
	return (line);
}

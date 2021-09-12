/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:50:22 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/10 00:20:22 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		rd;
	char	*buffer;
	 
	rd = read(fd, &buffer, BUFFER_SIZE);
	line
	return (line);
}

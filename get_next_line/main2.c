/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:20:50 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/02 18:47:14 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "libft2.h"
#include <stdlib.h>

int	main()
{
	char	*line;
	int		fd;
	int		GNL;

	fd = 0;
	fd = open("./text.txt", O_RDONLY);
	GNL = get_next_line(fd, &line);
	while (GNL)
	{
		printf("\nline: %s", line);
		if (line && *line)
			free(line);
		GNL = get_next_line(fd, &line);
	}
	system("leaks a.out");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 00:20:50 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/15 14:59:08 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

int	main()
{
	char	*line;
	int		fd;

	fd = 0;
	fd = open("./text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("\nline: %s\n", line);
	if (line && *line)
		free(line);
	system("leaks a.out");
	return (0);
}

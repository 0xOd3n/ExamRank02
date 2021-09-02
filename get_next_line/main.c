#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

int	main()
{
	char	*line;
	int		gnl;

	gnl = get_next_line(&line);
	printf("line: %s\ngnl:%d\n", line, gnl);
	if (*line)
		free(line);
	system("leaks a.out");
	return (0);
}

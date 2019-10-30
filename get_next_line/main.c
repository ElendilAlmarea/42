#include "get_next_line.h"

int	main()
{
	char	*line;
	int		fd;

	fd = open("main.c", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("--> %s\n", line);
		free(line);
	}
	printf("--> %s\n", line);
	free(line);
	close(fd);
	return (0);
}
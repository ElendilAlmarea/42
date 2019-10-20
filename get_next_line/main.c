#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	**line;
	int		fd;

	line = &l;
	fd = open("main.c", O_RDONLY);
	(void)argc;
	(void)argv;
	get_next_line(fd, line);
	get_next_line(fd, line);
	//printf("%s\n", line[0]);
	//printf("%s\n", line[1]);
	close(fd);
	return (0);
}
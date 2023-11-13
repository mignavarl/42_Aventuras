#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("ejemplo.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("No se pudo abrir el archivo");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s", count, line);
		free (line);
		line = NULL;
	}
	close(fd);
	return (0);
}

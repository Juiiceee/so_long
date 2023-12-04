#include "../Include/map.h"

char **createarea(int ligne, size_t colone)
{
	char **area;
	int	i;

	i = 0;
	area = ft_calloc(ligne, sizeof(char*));
	while (i < ligne)
	{
		area[i] = ft_calloc(colone,1);
		i++;
	}
	return (area);
}

char **inputarea(char *map, int ligne, size_t colone)
{
	int	fd;
	int	i;
	char **area;

	i = 0;
	fd = open(map,O_RDONLY);
	area = createarea(ligne, colone);
	while (i < ligne)
	{
		area[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (area);
}

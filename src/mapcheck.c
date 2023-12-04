#include "../Include/map.h"
#include "../Include/get_next_line.h"

int	checksize(char *map)
{
	int		fd;
	size_t	first;
	char	*str;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	first = ft_strlen(str);
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		if (!str || first != ft_strlen(str))
			break;
		free(str);
	}
	close(fd);
	if (first == (ft_strlen(str) - 1) && !str)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

/*int	checkborder()
{

}*/
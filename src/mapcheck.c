#include "../Include/map.h"
#include "../Include/get_next_line.h"

size_t	checksize(char *map, size_t *colone)
{
	int		fd;
	char	*str;
	int		ligne;

	ligne = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	*colone = ft_strlen(str);
	while (1)
	{
		ligne++;
		free(str);
		str = get_next_line(fd);
		if (!str || *colone != ft_strlen(str))
			break;
	}
	close(fd);
	if (*colone == (ft_strlen(str) - 1) && !str)
	{
		free(str);
		return (-1);
	}
	(*colone)--;
	free(str);
	return (ligne + 1);
}

/*int	checkborder()
{

}*/
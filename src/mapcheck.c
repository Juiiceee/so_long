#include "../Include/map.h"
#include "../Include/get_next_line.h"

int	checksize()
{
	int		fd;
	size_t	first;
	char	*str;

	fd = open("map.ber", O_RDONLY);
	str = get_next_line(fd);
	first = ft_strlen(str);
	while (first == ft_strlen(str) && str)
		str = get_next_line(fd);
	close(fd);
	if (first != ft_strlen(str) && str)
		return (0);
	return (1);
}
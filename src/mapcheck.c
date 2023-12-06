#include "../Include/map.h"
#include "../Include/get_next_line.h"

int	checkmur(char **tab, int ligne, int colone)
{
	int	i;
	int	j;

	i = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colone)
		{
			if (tab[0][j] != 'M' || tab[ligne - 1][j] != 'M' || tab[i][0] != 'M' || tab[i][colone - 1] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	checkitem(char **tab, int ligne, int colone)
{
	
}

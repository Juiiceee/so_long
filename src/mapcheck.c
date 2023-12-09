#include "../Include/map.h"

int	checkmur(char **area, int ligne, int colonne)
{
	int	i;
	int	j;

	i = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colonne)
		{
			if (area[0][j] != 'W' || area[ligne - 1][j] != 'W' || area[i][0] != 'W' || area[i][colonne - 1] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	checkall(char **area, int ligne, int colonne)
{
	t_bool	good;

	good = True;
	if (!checkmur(area, ligne, colonne))
		good = error("Mur error");
	if (!checkFeca(area, ligne, colonne))
		good = error("Position depart error");
	if (!checkSortie(area, ligne, colonne))
		good = error("Sortie Error");
	if (!checkDofus(area, ligne, colonne))
		good = error("Dofus error");
	return (good * checkDofus(area, ligne, colonne));
}

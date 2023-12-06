#include "../Include/map.h"

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
			if (tab[0][j] != 'W' || tab[ligne - 1][j] != 'W' || tab[i][0] != 'W' || tab[i][colone - 1] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	checkall(char **tab, int ligne, int colone)
{
	t_bool	good;

	good = True;
	if (!checkmur(tab, ligne, colone))
		good = error("Mur error");
	if (!checkFeca(tab, ligne, colone))
		good = error("Position depart error");
	if (!checkSortie(tab, ligne, colone))
		good = error("Sortie Error");
	if (!checkDofus(tab, ligne, colone))
		good = error("Dofus error");
	return (good * checkDofus(tab, ligne, colone));
}

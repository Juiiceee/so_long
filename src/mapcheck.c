#include "../Include/map.h"

int	checkmur(char **tab, int ligne, int colonne)
{
	int	i;
	int	j;

	i = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colonne)
		{
			if (tab[0][j] != 'W' || tab[ligne - 1][j] != 'W' || tab[i][0] != 'W' || tab[i][colonne - 1] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	checkall(char **tab, int ligne, int colonne)
{
	t_bool	good;

	good = True;
	if (!checkmur(tab, ligne, colonne))
		good = error("Mur error");
	if (!checkFeca(tab, ligne, colonne))
		good = error("Position depart error");
	if (!checkSortie(tab, ligne, colonne))
		good = error("Sortie Error");
	if (!checkDofus(tab, ligne, colonne))
		good = error("Dofus error");
	return (good * checkDofus(tab, ligne, colonne));
}

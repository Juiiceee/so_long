#include "../Include/map.h"

int	checkSortie(char **area, int ligne, int colonne)
{
	int	i;
	int	j;
	int	sortie;

	i = 0;
	sortie = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colonne)
		{
			if (area[i][j] == 'S')
				sortie++;
			j++;
		}
		i++;
	}
	return (sortie == 1);
}

int	checkFeca(char **area, int ligne, int colonne)
{
	int	i;
	int	j;
	int	feca;

	i = 0;
	feca = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colonne)
		{
			if (area[i][j] == 'F')
				feca++;
			j++;
		}
		i++;
	}
	return (feca == 1);
}

int	checkDofus(char **area, int ligne, int colonne)
{
	int	i;
	int	j;
	int	dofus;

	i = 0;
	dofus = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colonne)
		{
			if (area[i][j] == 'D')
				dofus++;
			j++;
		}
		i++;
	}
	return ((dofus > 0) * dofus);
}

int	checkRoublard(char **area, int ligne, int colonne)
{
	int	i;
	int	j;
	int	roublard;

	i = 0;
	roublard = 0;
	while (i < ligne)
	{
		j = 0;
		while (j < colonne)
		{
			if (area[i][j] == 'R')
				roublard++;
			j++;
		}
		i++;
	}
	return (roublard == 1);
}
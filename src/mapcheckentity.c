#include "../Include/map.h"

int	checkSortie(t_game *game)
{
	int		i;
	size_t	j;
	int		sortie;

	i = 0;
	sortie = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'S')
				sortie++;
			j++;
		}
		i++;
	}
	return (sortie == 1);
}

int	checkFeca(t_game *game)
{
	int	i;
	size_t	j;
	int	feca;

	i = 0;
	feca = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'F')
			{
				game->game_pos.x = i;
				game->game_pos.y = (int)j;
				feca++;
			}
			j++;
		}
		i++;
	}
	return (feca == 1);
}

int	checkDofus(t_game *game)
{
	int	i;
	size_t	j;
	int	dofus;

	i = 0;
	dofus = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'D')
				dofus++;
			j++;
		}
		i++;
	}
	game->game_obj.nbdofus = dofus;
	return (dofus > 0);
}

int	checkRoublard(t_game *game)
{
	int	i;
	size_t	j;
	int	roublard;

	i = 0;
	roublard = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'R')
				roublard++;
			j++;
		}
		i++;
	}
	return (roublard == 1);
}

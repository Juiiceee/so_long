#include "../Include/map.h"

int	checkmur(t_game *game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[0][j] != 'W' || game->area[game->game_mesure.ligne - 1][j] != 'W' || game->area[i][0] != 'W' || game->area[i][game->game_mesure.colonne - 1] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	checkall(t_game *game)
{
	t_bool	good;

	good = True;
	if (!checkmur(game))
		good = error("Mur error");
	if (!checkFeca(game))
		good = error("Position depart error");
	if (!checkSortie(game))
		good = error("Sortie Error");
	if (!checkDofus(game))
		good = error("Dofus error");
	return (good * checkDofus(game));
}

#include "../Include/graphique.h"

void	filltexturesortie(t_game game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'S')
				mlx_put_image_to_window(game.mlx, game.win, game.game_obj.sortie, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

void	filltexturemur(t_game game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'W')
				mlx_put_image_to_window(game.mlx, game.win, game.game_obj.mur, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

void	filltextureempty(t_game game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.game_obj.empty, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

void	filltexturedofus(t_game game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'D')
				mlx_put_image_to_window(game.mlx, game.win, game.game_obj.dofus, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

void	filltexturefeca(t_game game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'F')
				mlx_put_image_to_window(game.mlx, game.win, game.game_obj.feca.fecaface, j * 30, i * 30);
			j++;
		}
		i++;
	}
}
#include "../Include/graphique.h"

void	destroytexture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->game_obj.sortie);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecaface);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecadroite);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecagauche);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecados);
	mlx_destroy_image(game->mlx, game->game_obj.dofus);
	mlx_destroy_image(game->mlx, game->game_obj.mur);
	mlx_destroy_image(game->mlx, game->game_obj.empty);
}

void	freetab(char **area, int ligne)
{
	int	i;

	i = 0;
	while (i < ligne)
	{
		free(area[i]);
		i++;
	}
	free(area);
}

void	freeall(t_game *game)
{
	destroytexture(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	freetab(game->area, game->game_mesure.ligne);
	exit(0);
}

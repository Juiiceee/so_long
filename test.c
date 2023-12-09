#include "Include/global.h"
//#include "Include/graphique.h"
#define XK_Left		0xff51
#define XK_Up		0xff52
#define XK_Right	0xff53
#define XK_Down		0xff54
#define XK_Escape	0xff1b

void	calculmap(int	ligne, int colonne, int	*width, int	*height)
{
	*width = colonne * 30;
	*height = ligne * 30;
}

void	settexture(t_game *game)
{
	int	width;
	int	height;

	game->game_obj.sortie = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/sortie.xpm", &width, &height);
	game->game_obj.feca.fecaface = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/skinface.xpm", &width, &height);
	game->game_obj.feca.fecadroite = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/skindroite.xpm", &width, &height);
	game->game_obj.feca.fecagauche = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/skingauche.xpm", &width, &height);
	game->game_obj.feca.fecados = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/skindos.xpm", &width, &height);
	game->game_obj.dofus = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/dofusvulbis.xpm", &width, &height);
	game->game_obj.mur = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/mur.xpm", &width, &height);
	game->game_obj.empty = mlx_xpm_file_to_image(game->mlx, "tsrc/texture/case_vide.xpm", &width, &height);
}

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

void	freeall(t_game *game)
{
	destroytexture(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	freetab(game->area, game->game_mesure.ligne);
	exit(0);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	calculmap(game->game_mesure.ligne, game->game_mesure.colonne, &game->game_mesure.width, &game->game_mesure.height);
	game->win = mlx_new_window(game->mlx, game->game_mesure.width, game->game_mesure.height, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		return (0);
	}
	settexture(game);
	return (1);
}

int	key(int keycode, t_game *game)
{
	if (keycode == XK_Up)
		printf("UP\n");
	else if(keycode == XK_Down)
		printf("DOWN\n");
	else if (keycode == XK_Left)
		printf("LEFT\n");
	else if (keycode == XK_Right)
		printf("RIGHT\n");
	else if (keycode == XK_Escape)
		freeall(game);
	return (0);
}

int main(void) {
	t_game	game;

	game.game_mesure.ligne = repsize("map.ber", &game.game_mesure.colonne);
	if (game.game_mesure.ligne < 0)
		return (error("La saisie n'est pas un rectangle"));
	game.area = inputarea("map.ber", game.game_mesure.ligne, game.game_mesure.colonne);
	if (!checkall(game.area, game.game_mesure.ligne, game.game_mesure.colonne))
	{
		freetab(game.area, game.game_mesure.ligne);
		return (0);
	}
	if (!game_init(&game))
	{
		freetab(game.area, game.game_mesure.ligne);
		return (0);
	}
	fillalltexture(game);
	mlx_hook(game.win, 2, 1L<<0, key, &game);
	mlx_loop(game.mlx);
	freeall(&game);
	return 0;
}

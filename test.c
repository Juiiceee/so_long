#include "Include/global.h"
//#include "Include/graphique.h"
#define XK_Left		0xff51
#define XK_Up		0xff52
#define XK_Right	0xff53
#define XK_Down		0xff54
#define XK_Escape	0xff1b

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

#include "Include/global.h"
#include "Include/ft_printf.h"

int main(/*int argc, char **argv*/)
{
	t_game	game;
	char	map[] = "map.ber";

	if (!checkextension(map))
		return (0);
	game.game_mesure.ligne = repsize(map, &game.game_mesure.colonne);
	if (game.game_mesure.ligne < 0)
		return (error("La saisie n'est pas un rectangle"));
	game.area = inputarea(map, game.game_mesure.ligne, game.game_mesure.colonne);
	if (!checkall(&game))
	{
		freetab(game.area, game.game_mesure.ligne);
		return (0);
	}
	if (!game_init(&game))
	{
		freetab(game.area, game.game_mesure.ligne);
		return (0);
	}
	fillalltexture(game, game.game_obj.feca.fecaface);
	mlx_hook(game.win, 2, 1L<<0, key, &game);
	mlx_hook(game.win, 17, 1L<<17, closecross, &game);
	mlx_loop(game.mlx);
	freeall(&game);
	return (0);
}

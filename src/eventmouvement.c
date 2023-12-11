#include "../Include/graphique.h"

void	mUp(t_game *game)
{
	if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'W' || issortie(*game, game->area[game->game_pos.y - 1][game->game_pos.x]))
		return;
	else if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'D')
		game->game_obj.nbdofus--;
	if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'D' || game->area[game->game_pos.y - 1][game->game_pos.x] == '0')
	{
		game->area[game->game_pos.y - 1][game->game_pos.x] = 'F';
		game->area[game->game_pos.y][game->game_pos.x ] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y - 1);
	}
	fillalltexture(*game, game->game_obj.feca.fecados);
}

void	mDown(t_game *game)
{
	if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'W' || issortie(*game, game->area[game->game_pos.y + 1][game->game_pos.x]))
		return;
	else if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'D')
		game->game_obj.nbdofus--;
	if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'D' || game->area[game->game_pos.y + 1][game->game_pos.x] == '0')
	{
		game->area[game->game_pos.y + 1][game->game_pos.x] = 'F';
		game->area[game->game_pos.y][game->game_pos.x ] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y + 1);
	}
	fillalltexture(*game, game->game_obj.feca.fecaface);
}

void	mLeft(t_game *game)
{
	if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'W' || issortie(*game, game->area[game->game_pos.y][game->game_pos.x - 1]))
		return;
	else if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'D')
		game->game_obj.nbdofus--;
	if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'D' || game->area[game->game_pos.y][game->game_pos.x - 1] == '0')
	{
		game->area[game->game_pos.y][game->game_pos.x - 1] = 'F';
		game->area[game->game_pos.y][game->game_pos.x ] = '0';
		putpos(game, game->game_pos.x - 1, game->game_pos.y);
	}
	fillalltexture(*game, game->game_obj.feca.fecagauche);
}

void	mRight(t_game *game)
{
	if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'W' || issortie(*game, game->area[game->game_pos.y][game->game_pos.x + 1]))
		return;
	else if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'D')
		game->game_obj.nbdofus--;
	if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'D' || game->area[game->game_pos.y][game->game_pos.x + 1] == '0')
	{
		game->area[game->game_pos.y][game->game_pos.x + 1] = 'F';
		game->area[game->game_pos.y][game->game_pos.x ] = '0';
		putpos(game, game->game_pos.x + 1, game->game_pos.y);
	}
	fillalltexture(*game, game->game_obj.feca.fecadroite);
}

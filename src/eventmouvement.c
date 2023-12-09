#include "../Include/graphique.h"

void	mfront(t_game *game)
{
	if (game->area[game->game_pos.x][game->game_pos.y - 1] == 'W' || issortie(*game, game->area[game->game_pos.x][game->game_pos.y - 1]))
		return;
	else if (game->area[game->game_pos.x][game->game_pos.y - 1] == 'D')
		game->game_obj.nbdofus--;
	if (game->area[game->game_pos.x][game->game_pos.y - 1] == 'D' || game->area[game->game_pos.x][game->game_pos.y - 1] == '0')
	{
		game->area[game->game_pos.x][game->game_pos.y - 1] = 'F';
		game->area[game->game_pos.x][game->game_pos.y] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y - 1);
	}
}

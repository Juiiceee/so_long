#include "../Include/graphique.h"
#include "unistd.h"

int	key(int keycode, t_game *game)
{
	if (keycode == XK_Up || keycode == XK_w)
		mUp(game);
	else if(keycode == XK_Down || keycode == XK_s)
		mDown(game);
	else if (keycode == XK_Left || keycode == XK_a)
		mLeft(game);
	else if (keycode == XK_Right || keycode == XK_d)
		mRight(game);
	else if (keycode == XK_Escape)
		freeall(game);
	printf("nombre de dofus = %d \n", game->game_obj.nbdofus);
	return (0);
}
int	closecross(t_game *game)
{
	freeall(game);
	return (0);
}

int	iswall(char c)
{
	return (c == 'W');
}
int	issortie(t_game game, char c, int i)
{
	if (i == 0)
		return (c == 'S' && game.game_obj.nbdofus != 0);
	if (i == 1)
		return (c == 'S' && game.game_obj.nbdofus == 0);
	return (0);
}

void	endgame(t_game *game)
{
	write(1,"Tu es sortie GG!!!!",20);
	freeall(game);
}
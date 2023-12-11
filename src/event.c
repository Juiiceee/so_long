#include "../Include/graphique.h"

int	key(int keycode, t_game *game)
{
	int i = 0;
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
	while (i < game->game_mesure.ligne)
		{
			printf("%s\n",game->area[i]);
			i++;
		}
	printf("\n nomre de dofus = %d \n", game->game_obj.nbdofus);
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
int	issortie(t_game game, char c)
{
	return (c == 'S' && game.game_obj.nbdofus != 0);
}
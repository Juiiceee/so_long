#include "../Include/graphique.h"

int	key(int keycode, t_game *game)
{
	if (keycode == XK_Up || keycode == XK_w)
		mfront(game);
	else if(keycode == XK_Down || keycode == XK_s)
		printf("DOWN\n");
	else if (keycode == XK_Left || keycode == XK_a)
		printf("LEFT\n");
	else if (keycode == XK_Right || keycode == XK_d)
		printf("RIGHT\n");
	else if (keycode == XK_Escape)
		freeall(game);
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
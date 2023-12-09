#include "../Include/graphique.h"

#define XK_w		0x0077
#define XK_a		0x0061
#define XK_d		0x0064
#define XK_s		0x0073
#define XK_Up		0xff52
#define XK_Left		0xff51
#define XK_Right	0xff53
#define XK_Down		0xff54
#define XK_Escape	0xff1b

int	key(int keycode, t_game *game)
{
	if (keycode == XK_Up || keycode == XK_w)
		printf("UP\n");
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
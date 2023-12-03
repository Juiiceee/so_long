#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minilibx-linux/mlx.h"


typedef	struct s_pos
{
	int	x;
	int	y;
}	t_pos;
typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_data;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	createline(t_data data, t_pos first, t_pos second, int color)
{
	while(first.x < second.x)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, first.x, first.y,color);
		first.x++;
	}
}

int	main(void)
{
	t_data	data;
	t_pos	first;
	t_pos	second;

	first.x = 10;
	first.y = 100;
	second.x = 300;
	second.y = 100;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 300, "My first window!");
	//mlx_pixel_put(data.mlx_ptr, data.mlx_win, 100, 100,create_trgb(0,0,0,255));
	createline(data, first, second, create_trgb(0,255,0,0));
	if (data.mlx_win == NULL)
	{
		free(data.mlx_win);
		return (1);
	}
	while (1)
		;
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
//gcc *.c minilibx-linux/libmlx_Linux.a -lX11 -lXext && ./a.out
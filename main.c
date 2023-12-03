#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_data;

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 300, "My first window!");
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
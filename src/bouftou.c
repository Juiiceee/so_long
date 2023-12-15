/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouftou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:40 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/15 16:10:19 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

int	settexturebouftou(t_game *game)
{
	game->game_obj.bouftou = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/bouftou.xpm", &game->poub, &game->poub);
	if (!game->game_obj.bouftou)
		return (error("Probleme avec la texture bouftou"));
	game->nbtexture++;
	return (1);
}

void	filltexturebouftou(t_game game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'M')
				mlx_put_image_to_window(game.mlx,
					game.win, game.game_obj.bouftou, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	mouvementbouftou(t_game *game)
{
	int	i;

	i = 0;
	if (game->area[game->game_posbouf.y][game->game_posbouf.x + 1] == '0')
		mouvgeneral(game, game->game_posbouf.x + 1, game->game_posbouf.y);
	else if (game->area[game->game_posbouf.y - 1][game->game_posbouf.x] == '0')
		mouvgeneral(game, game->game_posbouf.x, game->game_posbouf.y - 1);
	else if (game->area[game->game_posbouf.y][game->game_posbouf.x - 1] == '0')
		mouvgeneral(game, game->game_posbouf.x - 1, game->game_posbouf.y);
	else if (game->area[game->game_posbouf.y + 1][game->game_posbouf.x] == '0')
		mouvgeneral(game, game->game_posbouf.x, game->game_posbouf.y + 1);
}

void	putposbouf(t_game *game, int x, int y)
{
	game->game_posbouf.x = x;
	game->game_posbouf.y = y;
}

void	mouvgeneral(t_game *game, int x, int y)
{
	game->area[y][x] = 'M';
	game->area[game->game_posbouf.y][game->game_posbouf.x] = '0';
	putposbouf(game, x, y);
}

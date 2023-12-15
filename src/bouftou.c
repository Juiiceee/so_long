/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouftou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:40 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/15 13:56:54 by lbehr            ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphiqueutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:34 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 14:14:35 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

void	destroytexture(t_game *game)
{
	mlx_destroy_image(game->mlx, game->game_obj.sortie);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecaface);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecadroite);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecagauche);
	mlx_destroy_image(game->mlx, game->game_obj.feca.fecados);
	mlx_destroy_image(game->mlx, game->game_obj.dofus);
	mlx_destroy_image(game->mlx, game->game_obj.mur);
	mlx_destroy_image(game->mlx, game->game_obj.empty);
}

void	freetab(char **area, int ligne)
{
	int	i;

	i = 0;
	while (i < ligne)
	{
		free(area[i]);
		i++;
	}
	free(area);
}

void	freeall(t_game *game)
{
	destroytexture(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	freetab(game->area, game->game_mesure.ligne);
	exit(0);
}

void	putpos(t_game *game, int x, int y)
{
	game->game_pos.x = x;
	game->game_pos.y = y;
}
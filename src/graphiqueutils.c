/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphiqueutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:34 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/14 14:39:10 by lbehr            ###   ########.fr       */
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

void	freetab(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->game_mesure.ligne)
	{
		free(game->area[i]);
		free(game->areacpy[i]);
		i++;
	}
	free(game->area);
	free(game->areacpy);
}

void	freeall(t_game *game)
{
	destroytexture(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	freetab(game);
	exit(0);
}

void	putpos(t_game *game, int x, int y)
{
	game->game_pos.x = x;
	game->game_pos.y = y;
}

void	destroytexturem(t_game *game)
{
	if (game->nbtexture > 0)
		mlx_destroy_image(game->mlx, game->game_obj.sortie);
	if (game->nbtexture > 1)
		mlx_destroy_image(game->mlx, game->game_obj.dofus);
	if (game->nbtexture > 2)
		mlx_destroy_image(game->mlx, game->game_obj.mur);
	if (game->nbtexture > 3)
		mlx_destroy_image(game->mlx, game->game_obj.empty);
	if (game->nbtexture > 4)
		mlx_destroy_image(game->mlx, game->game_obj.feca.fecaface);
	if (game->nbtexture > 5)
		mlx_destroy_image(game->mlx, game->game_obj.feca.fecadroite);
	if (game->nbtexture > 6)
		mlx_destroy_image(game->mlx, game->game_obj.feca.fecagauche);
	if (game->nbtexture > 7)
		mlx_destroy_image(game->mlx, game->game_obj.feca.fecados);
}

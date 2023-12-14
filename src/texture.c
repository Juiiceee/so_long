/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:59 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/14 17:08:27 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

void	filltexturesortie(t_game game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'S')
				mlx_put_image_to_window(game.mlx, game.win,
					game.game_obj.sortie, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	filltexturemur(t_game game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'W')
				mlx_put_image_to_window(game.mlx,
					game.win, game.game_obj.mur, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	filltextureempty(t_game game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == '0')
				mlx_put_image_to_window(game.mlx,
					game.win, game.game_obj.empty, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	filltexturedofus(t_game game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'D')
				mlx_put_image_to_window(game.mlx,
					game.win, game.game_obj.dofus, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	filltexturefeca(t_game game, void *chara)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game.game_mesure.ligne)
	{
		j = 0;
		while (j < game.game_mesure.colonne)
		{
			if (game.area[i][j] == 'F')
				mlx_put_image_to_window(game.mlx,
					game.win, chara, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

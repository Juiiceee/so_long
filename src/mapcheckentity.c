/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckentity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:10 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/14 17:55:57 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/map.h"

int	checksortie(t_game *game)
{
	int		i;
	size_t	j;
	int		sortie;

	i = 0;
	sortie = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'S')
				sortie++;
			j++;
		}
		i++;
	}
	return (sortie == 1);
}

int	checkfeca(t_game *game)
{
	int		i;
	size_t	j;
	int		feca;

	i = 0;
	feca = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'F')
			{
				putpos(game, (int)j, i);
				feca++;
			}
			j++;
		}
		i++;
	}
	return (feca == 1);
}

int	checkdofus(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	game->game_obj.nbdofus = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'D')
				game->game_obj.nbdofus++;
			j++;
		}
		i++;
	}
	game->game_obj.nbdofuscpy = game->game_obj.nbdofus;
	return (game->game_obj.nbdofus > 0);
}

int	checkbouftou(t_game *game)
{
	int		i;
	size_t	j;
	int		bouftou;

	i = 0;
	bouftou = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[i][j] == 'R')
				bouftou++;
			j++;
		}
		i++;
	}
	return (bouftou <= 1);
}

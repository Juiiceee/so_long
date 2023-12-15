/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheckpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:52:24 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/15 10:49:35 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/map.h"

int	fillrec(t_game *game, int x, int y)
{
	if (game->areacpy[x][y] == 'D')
		game->game_obj.nbdofuscpy--;
	game->areacpy[x][y] = 'F';
	return (1);
}

int	putvaleur(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->areacpy[x][y] == 'F' &&
		(game->areacpy[x + 1][y] == 'D' || game->areacpy[x + 1][y] == '0'
		|| game->areacpy[x + 1][y] == 'M'))
		i += fillrec(game, x + 1, y);
	if (game->areacpy[x][y] == 'F' &&
		(game->areacpy[x - 1][y] == 'D' || game->areacpy[x - 1][y] == '0'
		|| game->areacpy[x - 1][y] == 'M'))
		i += fillrec(game, x - 1, y);
	if (game->areacpy[x][y] == 'F' &&
		(game->areacpy[x][y + 1] == 'D' || game->areacpy[x][y + 1] == '0'
		|| game->areacpy[x][y + 1] == 'M'))
		i += fillrec(game, x, y + 1);
	if (game->areacpy[x][y] == 'F' &&
		(game->areacpy[x][y - 1] == 'D' || game->areacpy[x][y - 1] == '0'
		|| game->areacpy[x][y - 1] == 'M'))
		i += fillrec(game, x, y - 1);
	return (i != 0);
}

int	checkpath(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->game_mesure.ligne)
	{
		y = 0;
		while (game->areacpy[x][y])
		{
			if (putvaleur(game, x, y))
				x = 0;
			y++;
		}
		x++;
	}
	if (game->game_obj.nbdofuscpy != 0)
		return (0);
	return (1);
}

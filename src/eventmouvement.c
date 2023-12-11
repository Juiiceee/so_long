/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventmouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:13:54 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 17:16:03 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

void	mup(t_game *game)
{
	if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'W'
	|| issortie(*game, game->area[game->game_pos.y - 1][game->game_pos.x], 0))
		return ;
	else if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'D')
		game->game_obj.nbdofus--;
	else if (issortie(*game,
			game->area[game->game_pos.y - 1][game->game_pos.x], 1))
		endgame(game);
	if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'D'
	|| game->area[game->game_pos.y - 1][game->game_pos.x] == '0')
	{
		game->area[game->game_pos.y - 1][game->game_pos.x] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y - 1);
	}
	fillalltexture(*game, game->game_obj.feca.fecados);
}

void	mdown(t_game *game)
{
	if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'W'
	|| issortie(*game, game->area[game->game_pos.y + 1][game->game_pos.x], 0))
		return ;
	else if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'D')
		game->game_obj.nbdofus--;
	else if (issortie(*game,
			game->area[game->game_pos.y + 1][game->game_pos.x], 1))
		endgame(game);
	if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'D'
	|| game->area[game->game_pos.y + 1][game->game_pos.x] == '0')
	{
		game->area[game->game_pos.y + 1][game->game_pos.x] = 'F';
		game->area[game->game_pos.y][game->game_pos.x ] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y + 1);
	}
	fillalltexture(*game, game->game_obj.feca.fecaface);
}

void	mleft(t_game *game)
{
	if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'W'
	|| issortie(*game, game->area[game->game_pos.y][game->game_pos.x - 1], 0))
		return ;
	else if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'D')
		game->game_obj.nbdofus--;
	else if (issortie(*game,
			game->area[game->game_pos.y][game->game_pos.x - 1], 1))
		endgame(game);
	if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'D'
	|| game->area[game->game_pos.y][game->game_pos.x - 1] == '0')
	{
		game->area[game->game_pos.y][game->game_pos.x - 1] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x - 1, game->game_pos.y);
	}
	fillalltexture(*game, game->game_obj.feca.fecagauche);
}

void	mright(t_game *game)
{
	if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'W'
	|| issortie(*game, game->area[game->game_pos.y][game->game_pos.x + 1], 0))
		return ;
	else if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'D')
		game->game_obj.nbdofus--;
	else if (issortie(*game,
			game->area[game->game_pos.y][game->game_pos.x + 1], 1))
		endgame(game);
	if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'D'
	|| game->area[game->game_pos.y][game->game_pos.x + 1] == '0')
	{
		game->area[game->game_pos.y][game->game_pos.x + 1] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x + 1, game->game_pos.y);
	}
	fillalltexture(*game, game->game_obj.feca.fecadroite);
}

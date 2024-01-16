/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventmouvement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:13:54 by lbehr             #+#    #+#             */
/*   Updated: 2024/01/16 15:11:49 by lbehr            ###   ########.fr       */
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
	else if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'M')
		endgame(game, 1);
	else if (issortie(*game,
			game->area[game->game_pos.y - 1][game->game_pos.x], 1))
		endgame(game, 0);
	if (game->area[game->game_pos.y - 1][game->game_pos.x] == 'D'
	|| game->area[game->game_pos.y - 1][game->game_pos.x] == '0')
	{
		game->area[game->game_pos.y - 1][game->game_pos.x] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y - 1);
	}
	game->nbmouv++;
	ft_printf("Tu as fait %d mouvements\n", game->nbmouv);
	mouvementbouftou(game);
	fillalltexture(*game, game->game_obj.feca.fecados);
}

void	mdown(t_game *game)
{
	if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'W'
	|| issortie(*game, game->area[game->game_pos.y + 1][game->game_pos.x], 0))
		return ;
	else if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'D')
		game->game_obj.nbdofus--;
	else if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'M')
		endgame(game, 1);
	else if (issortie(*game,
			game->area[game->game_pos.y + 1][game->game_pos.x], 1))
		endgame(game, 0);
	if (game->area[game->game_pos.y + 1][game->game_pos.x] == 'D'
	|| game->area[game->game_pos.y + 1][game->game_pos.x] == '0')
	{
		game->area[game->game_pos.y + 1][game->game_pos.x] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x, game->game_pos.y + 1);
	}
	game->nbmouv++;
	ft_printf("Tu as fait %d mouvements\n", game->nbmouv);
	mouvementbouftou(game);
	fillalltexture(*game, game->game_obj.feca.fecaface);
}

void	mleft(t_game *game)
{
	if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'W'
	|| issortie(*game, game->area[game->game_pos.y][game->game_pos.x - 1], 0))
		return ;
	else if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'D')
		game->game_obj.nbdofus--;
	else if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'M')
		endgame(game, 1);
	else if (issortie(*game,
			game->area[game->game_pos.y][game->game_pos.x - 1], 1))
		endgame(game, 0);
	if (game->area[game->game_pos.y][game->game_pos.x - 1] == 'D'
	|| game->area[game->game_pos.y][game->game_pos.x - 1] == '0')
	{
		game->area[game->game_pos.y][game->game_pos.x - 1] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x - 1, game->game_pos.y);
	}
	game->nbmouv++;
	ft_printf("Tu as fait %d mouvements\n", game->nbmouv);
	mouvementbouftou(game);
	fillalltexture(*game, game->game_obj.feca.fecagauche);
}

void	mright(t_game *game)
{
	if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'W'
	|| issortie(*game, game->area[game->game_pos.y][game->game_pos.x + 1], 0))
		return ;
	else if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'D')
		game->game_obj.nbdofus--;
	else if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'M')
		endgame(game, 1);
	else if (issortie(*game,
			game->area[game->game_pos.y][game->game_pos.x + 1], 1))
		endgame(game, 0);
	if (game->area[game->game_pos.y][game->game_pos.x + 1] == 'D'
	|| game->area[game->game_pos.y][game->game_pos.x + 1] == '0')
	{
		game->area[game->game_pos.y][game->game_pos.x + 1] = 'F';
		game->area[game->game_pos.y][game->game_pos.x] = '0';
		putpos(game, game->game_pos.x + 1, game->game_pos.y);
	}
	game->nbmouv++;
	ft_printf("Tu as fait %d mouvements\n", game->nbmouv);
	mouvementbouftou(game);
	fillalltexture(*game, game->game_obj.feca.fecadroite);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

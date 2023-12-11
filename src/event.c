/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:18 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 17:54:32 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

int	key(int keycode, t_game *game)
{
	if (keycode == XK_UP || keycode == XK_W)
		mup(game);
	else if (keycode == XK_DOWN || keycode == XK_S)
		mdown(game);
	else if (keycode == XK_LEFT || keycode == XK_A)
		mleft(game);
	else if (keycode == XK_RIGHT || keycode == XK_D)
		mright(game);
	else if (keycode == XK_ESCAPE)
		freeall(game);
	return (0);
}

int	closecross(t_game *game)
{
	freeall(game);
	return (0);
}

int	iswall(char c)
{
	return (c == 'W');
}

int	issortie(t_game game, char c, int i)
{
	if (i == 0)
		return (c == 'S' && game.game_obj.nbdofus != 0);
	if (i == 1)
		return (c == 'S' && game.game_obj.nbdofus == 0);
	return (0);
}

void	endgame(t_game *game)
{
	if (game->nbmouv < 30)
		ft_printf("GG tu as trouve la sortie en seulement %d coups\n", game->nbmouv);
	else if (game->nbmouv < 60)
		ft_printf("GG tu as trouve la sortie en %d coups\n", game->nbmouv);
	else if (game->nbmouv < 90)
		ft_printf("Ouais tu as trouve la sortie tu as un peu force avec tes %d coups\n", game->nbmouv);
	freeall(game);
}

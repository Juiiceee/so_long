/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:18 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 17:38:15 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"
#include "unistd.h"

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
	write(1, "Tu es sortie GG!!!!", 20);
	freeall(game);
}

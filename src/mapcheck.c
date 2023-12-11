/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:50 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 15:46:18 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/map.h"

int	checkmur(t_game *game)
{
	int	i;
	size_t	j;

	i = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[0][j] != 'W' || game->area[game->game_mesure.ligne - 1][j] != 'W' || game->area[i][0] != 'W' || game->area[i][game->game_mesure.colonne - 1] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	checkall(t_game *game)
{
	t_bool	good;

	good = True;
	if (!checkmur(game))
		good = error("Mur error");
	if (!checkFeca(game))
		good = error("Position depart error");
	if (!checkSortie(game))
		good = error("Sortie Error");
	if (!checkDofus(game))
		good = error("Dofus error");
	return (good * checkDofus(game));
}

int		checkextension(char	*str)
{
	int	cb;
	int	i;
	char *ext = ".ber";

	cb = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i + cb] == ext[cb] && str[i + cb] && ext[cb])
		cb++;
	if (cb == 4)
		return (1);
	return (0);	
}

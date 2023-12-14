/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:50 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/14 18:10:22 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/map.h"

int	checkmur(t_game *game)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < game->game_mesure.ligne)
	{
		j = 0;
		while (j < game->game_mesure.colonne)
		{
			if (game->area[0][j] != 'W'
					|| game->area[game->game_mesure.ligne - 1][j] != 'W'
					|| game->area[i][0] != 'W'
					|| game->area[i][game->game_mesure.colonne - 1] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		nb;
	int		i;

	i = 0;
	nb = ft_strlen(src);
	new = (char *)malloc((nb + 1) * sizeof(char));
	if (new == 0)
		return (new);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	checkall(t_game *game)
{
	t_bool	good;

	good = True;
	if (!checkmur(game))
		good = error("Mur error");
	if (!checkfeca(game))
		good = error("Position depart error");
	if (!checksortie(game))
		good = error("Sortie Error");
	if (!checkdofus(game))
		good = error("Dofus error");
	if (!checkbouftou(game))
		good = error("Dofus error");
	if (!checkpath(game))
		good = error("Tout les collectibles ne sont pas accessibles");
	return (good);
}

int	checkextension(char	*str)
{
	int		cb;
	int		i;
	char	*ext;
	int		fd;

	ext = ft_strdup(".ber");
	cb = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i + cb] == ext[cb] && str[i + cb] && ext[cb])
		cb++;
	free(ext);
	if (cb == 4)
	{
		fd = open(str, O_RDONLY);
		if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
			return (error("Le fichier ne peut pas etre ouvert"));
		close(fd);
		return (1);
	}
	return (error("La map n'a pas la bonne extension"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:45 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/14 14:45:09 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/map.h"

size_t	strlenno(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

size_t	repsize(char *map, size_t *colonne)
{
	int		fd;
	char	*str;
	int		ligne;
	int		test;

	ligne = 0;
	test = 0;
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	*colonne = strlenno(str);
	while (1)
	{
		ligne++;
		free(str);
		str = get_next_line(fd);
		if (*colonne != strlenno(str) && str)
			test = 1;
		if (!str)
			break ;
	}
	close(fd);
	if (test == 1)
		return (freereturn(str));
	free(str);
	return (ligne);
}

char	**createarea(int ligne, size_t colonne)
{
	char	**area;
	int		i;

	i = 0;
	area = ft_calloc(ligne, sizeof(char *));
	while (i < ligne)
	{
		area[i] = ft_calloc(colonne + 1, 1);
		i++;
	}
	return (area);
}

void	inputarea(char *map, t_game *game)
{
	int		fd;
	int		i;
	char	*text;

	i = 0;
	fd = open(map, O_RDONLY);
	game->area = createarea(game->game_mesure.ligne,
			game->game_mesure.colonne);
	game->areacpy = createarea(game->game_mesure.ligne,
			game->game_mesure.colonne);
	while (i < game->game_mesure.ligne)
	{
		text = get_next_line(fd);
		game->area[i] = ft_strncpy(game->area[i],
				text, game->game_mesure.colonne);
		game->areacpy[i] = ft_strncpy(game->areacpy[i],
				text, game->game_mesure.colonne);
		free(text);
		i++;
	}
	close(fd);
}

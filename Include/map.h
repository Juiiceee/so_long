/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:19 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/14 14:01:15 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "global.h"
# include "graphique.h"

//map.c
size_t	repsize(char *map, size_t *colonne);
char	**createarea(int ligne, size_t colonne);
void	inputarea(char *map, t_game *game);

//mapcheck.c + strdup
int		checkmur(t_game *game);
int		checkall(t_game *game);
int		checkextension(char	*str);

//mapcheckentity.c
int		checksortie(t_game *game);
int		checkfeca(t_game *game);
int		checkdofus(t_game *game);
int		checkroublard(t_game *game);

//checkpath
int		checkpath(t_game *game);
int		putvaleur(t_game *game, int x, int y);
int		fillrec(t_game *game, int x, int y);

#endif
#ifndef MAP_H
# define MAP_H

# include "global.h"
# include "graphique.h"

size_t	repsize(char *map, size_t *colonne);

char 	**createarea(int ligne, size_t colonne);
char 	**inputarea(char *map, int ligne, size_t colonne);

int		checkmur(t_game *game);
int		checkall(t_game *game);

int		checkSortie(t_game *game);
int		checkFeca(t_game *game);
int		checkDofus(t_game *game);
int		checkRoublard(t_game *game);

#endif
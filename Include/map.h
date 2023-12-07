#ifndef MAP_H
# define MAP_H

# include "global.h"

size_t	repsize(char *map, size_t *colonne);

char 	**createarea(int ligne, size_t colonne);
char 	**inputarea(char *map, int ligne, size_t colonne);

int		checkmur(char **tab, int ligne, int colonne);
int		checkall(char **tab, int ligne, int colonne);

int		checkSortie(char **tab, int ligne, int colonne);
int		checkFeca(char **tab, int ligne, int colonne);
int		checkDofus(char **tab, int ligne, int colonne);
int		checkRoublard(char **tab, int ligne, int colonne);

#endif
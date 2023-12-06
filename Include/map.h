#ifndef MAP_H
# define MAP_H

# include "global.h"

size_t	repsize(char *map, size_t *colone);

char 	**createarea(int ligne, size_t colone);
char 	**inputarea(char *map, int ligne, size_t colone);

int		checkmur(char **tab, int ligne, int colone);
int		checkall(char **tab, int ligne, int colone);

int		checkSortie(char **tab, int ligne, int colone);
int		checkFeca(char **tab, int ligne, int colone);
int		checkDofus(char **tab, int ligne, int colone);
int		checkRoublard(char **tab, int ligne, int colone);

#endif
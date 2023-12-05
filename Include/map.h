#ifndef MAP_H
# define MAP_H

# include "global.h"

size_t	repsize(char *map, size_t *colone);
int		checksize(int ligne, size_t colone);
int		checkmur(char **tab, int ligne, int colone);

char **createarea(int ligne, size_t colone);
char **inputarea(char *map, int ligne, size_t colone);

#endif
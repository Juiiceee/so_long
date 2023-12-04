#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../Include/get_next_line.h"

size_t	checksize(char *map, size_t *colone);
char **createarea(int ligne, size_t colone);
char **inputarea(char *map, int ligne, size_t colone);


#endif
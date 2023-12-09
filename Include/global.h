#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "utils.h"
# include "map.h"
# include "graphique.h"
//# include "ft_printf.h"

typedef enum e_bool
{
	False,
	True
}	t_bool;

/*typedef	struct s_game_chara
{
	void	*fecaface;
	void	*fecadroite;
	void	*fecagauche;
	void	*fecados;
}	t_game_chara;

typedef	struct s_game_obj
{
	void			*sortie;
	t_game_chara	feca;
	void			*dofus;
	int				nbdofus;
	void			*mur;
	void			*empty;
}	t_game_obj;

typedef	struct s_game_mesure
{
	int			width;
	int			height;
	int			ligne;
	size_t		colonne;
}	t_game_mesure;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_game_mesure	game_mesure;
	char			**area;
	t_game_obj		game_obj;
}	t_game;*/

#endif

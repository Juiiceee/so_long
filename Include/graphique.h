#ifndef GRAPHIQUE_H
# define GRAPHIQUE_H

//# include "global.h"

typedef	struct s_game_chara
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
}	t_game;

//texture.c
void	filltexturesortie(t_game game);
void	filltexturemur(t_game game);
void	filltextureempty(t_game game);
void	filltexturedofus(t_game game);
void	filltexturefeca(t_game game);

//graphique.c
void	fillalltexture(t_game game);


#endif

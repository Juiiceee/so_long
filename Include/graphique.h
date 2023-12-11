#ifndef GRAPHIQUE_H
# define GRAPHIQUE_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define XK_w		0x0077
# define XK_a		0x0061
# define XK_d		0x0064
# define XK_s		0x0073
# define XK_Up		0xff52
# define XK_Left	0xff51
# define XK_Right	0xff53
# define XK_Down	0xff54
# define XK_Escape	0xff1b

typedef	struct s_game_pos
{
	int	x;
	int	y;
}	t_game_pos;

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
	t_game_pos		game_pos;
}	t_game;

//texture.c
void	filltexturesortie(t_game game);
void	filltexturemur(t_game game);
void	filltextureempty(t_game game);
void	filltexturedofus(t_game game);
void	filltexturefeca(t_game game, void *chara);

//graphique.c
void	fillalltexture(t_game game, void *chara);
void	calculmap(int ligne, int colonne, int *width, int *height);
void	settexture(t_game *game);
int		game_init(t_game *game);

//graphiqueutils.c
void	freeall(t_game *game);
void	destroytexture(t_game *game);
void	freetab(char **area, int ligne);
void	putpos(t_game *game, int x, int y);

//eventmouvement.c
void	mUp(t_game *game);
void	mDown(t_game *game);
void	mLeft(t_game *game);
void	mRight(t_game *game);

//event.c
int		key(int keycode, t_game *game);
int		closecross(t_game *game);
int		iswall(char c);
int		issortie(t_game game, char c, int i);
void	endgame(t_game *game);

#endif

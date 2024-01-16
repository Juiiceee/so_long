/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:15:13 by lbehr             #+#    #+#             */
/*   Updated: 2024/01/16 15:09:34 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIQUE_H
# define GRAPHIQUE_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "utils.h"

# define XK_W		0x0077
# define XK_A		0x0061
# define XK_D		0x0064
# define XK_S		0x0073
# define XK_UP		0xff52
# define XK_LEFT	0xff51
# define XK_RIGHT	0xff53
# define XK_DOWN	0xff54
# define XK_ESCAPE	0xff1b

typedef struct s_game_pos
{
	int	x;
	int	y;
}	t_game_pos;

typedef struct s_game_posbouf
{
	int	x;
	int	y;
}	t_game_posbouf;

typedef struct s_game_chara
{
	void	*fecaface;
	void	*fecadroite;
	void	*fecagauche;
	void	*fecados;
}	t_game_chara;

typedef struct s_game_obj
{
	void			*sortie;
	t_game_chara	feca;
	void			*dofus;
	int				nbdofus;
	int				nbdofuscpy;
	void			*mur;
	void			*empty;
	void			*bouftou;
}	t_game_obj;

typedef struct s_game_mesure
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
	char			**area;
	char			**areacpy;
	int				nbmouv;
	int				nbtexture;
	t_game_mesure	game_mesure;
	t_game_obj		game_obj;
	t_game_pos		game_pos;
	t_game_posbouf	game_posbouf;
	int				poub;
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
int		game_init(t_game *game);
int		settexturechara(t_game *game);
int		settexture(t_game *game);

//graphiqueutils.c
void	freeall(t_game *game);
void	destroytexture(t_game *game);
void	destroytexturem(t_game *game);
void	freetab(t_game *game);
void	putpos(t_game *game, int x, int y);

//eventmouvement.c
void	mup(t_game *game);
void	mdown(t_game *game);
void	mleft(t_game *game);
void	mright(t_game *game);
int		create_trgb(int t, int r, int g, int b);

//event.c
int		key(int keycode, t_game *game);
int		closecross(t_game *game);
int		iswall(char c);
int		issortie(t_game game, char c, int i);
void	endgame(t_game *game, int i);

//bouftou.c
int		settexturebouftou(t_game *game);
void	filltexturebouftou(t_game game);
void	putposbouf(t_game *game, int x, int y);
void	mouvementbouftou(t_game *game);
void	mouvgeneral(t_game *game, int x, int y);

#endif

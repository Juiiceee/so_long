/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:29 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/11 17:40:44 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

void	fillalltexture(t_game game, void *chara)
{
	filltexturesortie(game);
	filltexturemur(game);
	filltextureempty(game);
	filltexturedofus(game);
	filltexturefeca(game, chara);
}

void	calculmap(int ligne, int colonne, int	*width, int	*height)
{
	*width = colonne * 30;
	*height = ligne * 30;
}

void	settexture(t_game *game)
{
	int	width;
	int	height;

	game->game_obj.sortie = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/sortie.xpm", &width, &height);
	game->game_obj.feca.fecaface = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skinface.xpm", &width, &height);
	game->game_obj.feca.fecadroite = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skindroite.xpm", &width, &height);
	game->game_obj.feca.fecagauche = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skingauche.xpm", &width, &height);
	game->game_obj.feca.fecados = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skindos.xpm", &width, &height);
	game->game_obj.dofus = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/dofusvulbis.xpm", &width, &height);
	game->game_obj.mur = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/mur.xpm", &width, &height);
	game->game_obj.empty = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/case_vide.xpm", &width, &height);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	calculmap(game->game_mesure.ligne, game->game_mesure.colonne,
		&game->game_mesure.width, &game->game_mesure.height);
	game->win = mlx_new_window(game->mlx, game->game_mesure.width,
			game->game_mesure.height, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		return (0);
	}
	game->nbmouv = 0;
	settexture(game);
	return (1);
}

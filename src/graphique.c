/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:14:29 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/15 13:31:28 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/graphique.h"

void	fillalltexture(t_game game, void *chara)
{
	char	*str;

	str = ft_itoa(game.nbmouv);
	filltexturesortie(game);
	filltexturemur(game);
	filltextureempty(game);
	filltexturedofus(game);
	filltexturefeca(game, chara);
	filltexturebouftou(game);
	mlx_string_put(game.mlx, game.win, game.game_mesure.width - 40,
		25, create_trgb(0, 0, 0, 0), str);
	free(str);
}

void	calculmap(int ligne, int colonne, int	*width, int	*height)
{
	*width = colonne * 50;
	*height = ligne * 50;
}

int	settexturechara(t_game *game)
{
	game->game_obj.feca.fecaface = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skinface.xpm", &game->poub, &game->poub);
	if (!game->game_obj.feca.fecaface)
		return (error("Probleme avec la texture skinface"));
	game->nbtexture++;
	game->game_obj.feca.fecadroite = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skindroite.xpm", &game->poub, &game->poub);
	if (!game->game_obj.feca.fecadroite)
		return (error("Probleme avec la texture fecadroite"));
	game->nbtexture++;
	game->game_obj.feca.fecagauche = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skingauche.xpm", &game->poub, &game->poub);
	if (!game->game_obj.feca.fecagauche)
		return (error("Probleme avec la texture skingauche"));
	game->nbtexture++;
	game->game_obj.feca.fecados = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/skindos.xpm", &game->poub, &game->poub);
	if (!game->game_obj.feca.fecados)
		return (error("Probleme avec la texture skindos"));
	game->nbtexture++;
	return (1);
}

int	settexture(t_game *game)
{
	game->game_obj.sortie = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/sortie.xpm", &game->poub, &game->poub);
	if (!game->game_obj.sortie)
		return (error("Probleme avec la texture sortie"));
	game->nbtexture++;
	game->game_obj.dofus = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/dofusvulbis.xpm", &game->poub, &game->poub);
	if (!game->game_obj.dofus)
		return (error("Probleme avec la texture dofusvulbis"));
	game->nbtexture++;
	game->game_obj.mur = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/mur.xpm", &game->poub, &game->poub);
	if (!game->game_obj.mur)
		return (error("Probleme avec la texture mur"));
	game->nbtexture++;
	game->game_obj.empty = mlx_xpm_file_to_image(game->mlx,
			"tsrc/texture/case_vide.xpm", &game->poub, &game->poub);
	if (!game->game_obj.empty)
		return (error("Probleme avec la texture case_vide"));
	game->nbtexture++;
	if (!settexturechara(game))
		return (0);
	if (!settexturebouftou(game))
		return (0);
	return (1);
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error("L'affichage n'affiche pas"));
	calculmap(game->game_mesure.ligne, game->game_mesure.colonne,
		&game->game_mesure.width, &game->game_mesure.height);
	game->win = mlx_new_window(game->mlx, game->game_mesure.width,
			game->game_mesure.height, "so_long");
	if (!game->win)
		return (free(game->mlx), error("La fenetre ne fenetre pas"));
	game->nbmouv = 0;
	game->nbtexture = 0;
	if (!settexture(game))
	{
		destroytexturem(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	return (1);
}

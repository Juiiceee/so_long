/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:13 by lbehr             #+#    #+#             */
/*   Updated: 2023/12/13 11:12:20 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/global.h"
#include "../Include/ft_printf.h"

int	main(int argc, char **argv)
{
	t_game	game;
	/*int	argc = 2;
	char *argv[] = {"oui","tsrc/map/valide/mapcool.ber"};*/

	if (argc == 2)
	{
		if (!checkextension(argv[1]))
			return (0);
		game.game_mesure.ligne = repsize(argv[1], &game.game_mesure.colonne);
		if (game.game_mesure.ligne < 0)
			return (error("La saisie n'est pas un rectangle"));
		game.area = inputarea(argv[1],
				game.game_mesure.ligne, game.game_mesure.colonne);
		if (!checkall(&game))
			return (freetab(game.area, game.game_mesure.ligne), 0);
		if (!game_init(&game))
			return (freetab(game.area, game.game_mesure.ligne), 0);
		fillalltexture(game, game.game_obj.feca.fecaface);
		mlx_hook(game.win, 2, 1L << 0, key, &game);
		mlx_hook(game.win, 17, 1L << 17, closecross, &game);
		mlx_loop(game.mlx);
		freeall(&game);
		return (0);
	}
	return (0);
}

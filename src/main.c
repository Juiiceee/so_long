/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:13 by lbehr             #+#    #+#             */
/*   Updated: 2024/01/17 12:47:05 by lbehr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/global.h"
#include "../Include/ft_printf.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!checkextension(argv[1]))
			return (0);
		game.game_mesure.ligne = repsize(argv[1], &game.game_mesure.colonne);
		if (!checksize(game))
			return (0);
		inputarea(argv[1], &game);
		if (!checkall(&game))
			return (freetab(&game), 0);
		if (!checkpath(&game))
			return (freetab(&game), error("Collectible non accessible"));
		if (!game_init(&game))
			return (freetab(&game), 0);
		fillalltexture(game, game.game_obj.feca.fecaface);
		mlx_hook(game.win, 2, 1L << 0, key, &game);
		mlx_hook(game.win, 17, 1L << 17, closecross, &game);
		mlx_loop(game.mlx);
		freeall(&game);
		return (0);
	}
	return (error("Argument error"));
}

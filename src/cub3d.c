/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 18:01:37 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_global_settings	game;

	(void)argv;
	if (argc != 2)
		fatal_error("Program must have 1 argument!");
	if (set_up_game(&game) == EXIT_FAILURE)
		fatal_error("Error setting up mlx settings!");
	parse(&game, argv[1]);
	printf("%d:%d",game.map.ceiling_color, game.map.floor_color);
	// mlx_hook(game.mlxset.win_ptr, 2, 0, key_press, &game);
	// mlx_loop_hook(game.mlxset.mlx, execution, &game);
	// mlx_loop(game.mlxset.mlx);
	return (0);
}

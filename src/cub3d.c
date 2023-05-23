/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 14:06:19 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_global_settings	game;

	if (argc != 2)
		fatal_error("Program must have 1 argument!");
	parse(&game, argv[1]);
	if (set_up_game(&game) == EXIT_FAILURE)
		fatal_error("Error setting up mlx settings!");
	if (init_textures(&game) == FAIL)
		fatal_error("Error initializing textures!");
	mlx_hook(game.mlxset.win_ptr, 2, 0, key_press, &game);
	//mlx_hook(game.mlxset.win_ptr, 2, 0, key_press_rotate, &game);
	mlx_loop_hook(game.mlxset.mlx, execution, &game);
	mlx_loop(game.mlxset.mlx);
	return (0);
}

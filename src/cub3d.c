/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 17:58:12 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int key_pressed, t_global_settings *game)
{
	if (key_pressed == ESCAPE_KEY)
		free_and_exit(game);
	else if (key_pressed == LEFT_ARROW_KEY)
		game->press.press_rotate_left = 0;
	else if (key_pressed == RIGHT_ARROW_KEY)
		game->press.press_rotate_right = 0;
	else if (key_pressed == UP_KEY)
		game->press.press_forward = 0;
	else if (key_pressed == DOWN_KEY)
		game->press.press_backward = 0;
	else if (key_pressed == LEFT_KEY)
		game->press.press_left = 0;
	else if (key_pressed == RIGHT_KEY)
		game->press.press_right = 0;
	else
		return (1);
	return (0);
}

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
	mlx_hook(game.mlxset.win_ptr, 3, 0, key_release, &game);
	mlx_hook(game.mlxset.win_ptr, 17, 0, free_and_exit, NULL);
	mlx_loop_hook(game.mlxset.mlx, execution, &game);
	mlx_loop(game.mlxset.mlx);
	return (0);
}

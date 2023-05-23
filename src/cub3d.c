/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 19:01:33 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key_pressed, t_global_settings *game)
{
	if (key_pressed == ESCAPE_KEY)
		free_and_exit(game);
	if (key_pressed == LEFT_ARROW_KEY)
		game->press.press_rotate_left = 1;
	if (key_pressed == RIGHT_ARROW_KEY)
		game->press.press_rotate_right = 1;
	if (key_pressed == UP_KEY)
		game->press.press_forward = 1;
	if (key_pressed == DOWN_KEY)
		game->press.press_backward = 1;
	if (key_pressed == LEFT_KEY)
		game->press.press_left = 1;
	if (key_pressed == RIGHT_KEY)
		game->press.press_right = 1;
	return (0);
}

int	key_release(int key_pressed, t_global_settings *game)
{
	if (key_pressed == ESCAPE_KEY)
		free_and_exit(game);
	if (key_pressed == LEFT_ARROW_KEY)
		game->press.press_rotate_left = 0;
	if (key_pressed == RIGHT_ARROW_KEY)
		game->press.press_rotate_right = 0;
	if (key_pressed == UP_KEY)
		game->press.press_forward = 0;
	if (key_pressed == DOWN_KEY)
		game->press.press_backward = 0;
	if (key_pressed == LEFT_KEY)
		game->press.press_left = 0;
	if (key_pressed == RIGHT_KEY)
		game->press.press_right = 0;
	return (0);
}

int	key_wait(t_global_settings *game)
{
	if (game->press.press_rotate_left == 1)
		key_press_rotate(game);
	else if (game->press.press_rotate_right == 1)
		key_press_rotate(game);
	if (game->press.press_forward == 1)
		go_straight(game);
	if (game->press.press_backward == 1)
		go_back(game);
	if (game->press.press_left == 1)
		go_left(game);
	if (game->press.press_right == 1)
		go_right(game);
	game->x = 0;
	mlx_destroy_image(game->mlxset.mlx, game->mlxset.img.img);
	game->mlxset.img.img = mlx_new_image
		(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT);
	mlx_clear_window(game->mlxset.mlx, game->mlxset.win_ptr);
	execution(game);
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
	execution(&game);
	mlx_hook(game.mlxset.win_ptr, 2, 0, key_press, &game);
	mlx_hook(game.mlxset.win_ptr, 3, 0, key_release, &game);
	mlx_hook(game.mlxset.win_ptr, 17, 0, free_and_exit, NULL);
	mlx_loop_hook(game.mlxset.mlx, key_wait, &game);
	mlx_loop(game.mlxset.mlx);
	return (0);
}

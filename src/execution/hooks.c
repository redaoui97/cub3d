/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:19 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/20 22:06:53 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	There is a problem with the rotation using the initial position of the player
	E and N make the rotation reversed
*/
int	key_press(int key_pressed, t_global_settings *game)
{
	if (key_press_rotate(key_pressed, game) == 0)
		return (0);
	if (key_pressed == ESCAPE_KEY)
		free_and_exit(game);
	else if (key_pressed == UP_KEY)
		go_straight(game);
	else if (key_pressed == DOWN_KEY)
		go_back(game);
	else if (key_pressed == LEFT_KEY)
		go_left(game);
	else if (key_pressed == RIGHT_KEY)
		go_right(game);
	else
		return (1);
	game->x = 0;
	mlx_destroy_image(game->mlxset.mlx, game->mlxset.img.img);
	game->mlxset.img.img = mlx_new_image
		(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT);
	mlx_clear_window(game->mlxset.mlx, game->mlxset.win_ptr);
	execution(game);
	return (0);
}

int	key_press_rotate(int key_pressed, t_global_settings *game)
{
	if (key_pressed == LEFT_ARROW_KEY)
	{
		if (game->map.direction == 'W' || game->map.direction == 'S')
			rotate_left(game);
		else if (game->map.direction == 'N' || game->map.direction == 'E')
			rotate_right(game);
	}
	else if (key_pressed == RIGHT_ARROW_KEY)
	{
		if (game->map.direction == 'W' || game->map.direction == 'S')
			rotate_right(game);
		else if (game->map.direction == 'N' || game->map.direction == 'E')
			rotate_left(game);
	}
	else
		return (1);
	game->x = 0;
	mlx_destroy_image(game->mlxset.mlx, game->mlxset.img.img);
	game->mlxset.img.img = mlx_new_image
		(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT);
	mlx_clear_window(game->mlxset.mlx, game->mlxset.win_ptr);
	execution(game);
	return (0);
}

void	rotate_left(t_global_settings *game)
{
	double	x;
	double	y;
	double	xp;
	double	yp;
	double	angle;

	x = game->dir_x;
	y = game->dir_y;
	xp = game->plane_x;
	yp = game->plane_y;
	angle = ROTATION_ANGLE * -1;
	game->dir_x = x * cos(angle) - y * sin(angle);
	game->dir_y = x * sin(angle) + y * cos(angle);
	game->plane_x = xp * cos(angle) - yp * sin(angle);
	game->plane_y = xp * sin(angle) + yp * cos(angle);
}

void	rotate_right(t_global_settings *game)
{
	double	x;
	double	y;
	double	xp;
	double	yp;
	double	angle;

	x = game->dir_x;
	y = game->dir_y;
	xp = game->plane_x;
	yp = game->plane_y;
	angle = ROTATION_ANGLE;
	game->dir_x = x * cos(angle) - y * sin(angle);
	game->dir_y = x * sin(angle) + y * cos(angle);
	game->plane_x = xp * cos(angle) - yp * sin(angle);
	game->plane_y = xp * sin(angle) + yp * cos(angle);
}

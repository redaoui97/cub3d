/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:19 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 18:58:16 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_rotate(t_global_settings *game)
{
	if (game->press.press_rotate_left)
	{
		if (game->map.direction == 'W' || game->map.direction == 'S')
			rotate_left(game);
		else if (game->map.direction == 'N' || game->map.direction == 'E')
			rotate_right(game);
	}
	else if (game->press.press_rotate_right)
	{
		if (game->map.direction == 'W' || game->map.direction == 'S')
			rotate_right(game);
		else if (game->map.direction == 'N' || game->map.direction == 'E')
			rotate_left(game);
	}
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

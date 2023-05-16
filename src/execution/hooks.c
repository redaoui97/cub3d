/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:19 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/16 20:03:47 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	There is a problem with the rotation using the initial position of the player
	E and N make the rotation reversed
*/
int	key_press(int key_pressed, t_global_settings *game)
{
	if (key_pressed == UP_KEY)
		go_straight(game);
	else if (key_pressed == DOWN_KEY)
		go_back(game);
	else if (key_pressed == LEFT_KEY)
		go_left(game);
	else if (key_pressed == RIGHT_KEY)
		go_right(game);
	else if (key_pressed == LEFT_ARROW_KEY)
		rotate_left(game);
	else if (key_pressed == RIGHT_ARROW_KEY)
		rotate_right(game);
	else
		return (1);
	game->x = 0;
	mlx_destroy_image(game->mlxset.mlx, game->mlxset.img.img);
	game->mlxset.img.img = mlx_new_image(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT);
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
	
	x = game->dirX;
	y = game->dirY;
	xp = game->planeX;
	yp = game->planeY;
	angle = ROTATION_ANGLE * -1;
	game->dirX = x * cos(angle) - y * sin(angle);
	game->dirY = x * sin(angle) + y * cos(angle);
	game->planeX = xp * cos(angle) - yp * sin(angle);
	game->planeY = xp * sin(angle) + yp * cos(angle);
}

void	rotate_right(t_global_settings *game)
{
	double	x;
	double	y;
	double	xp;
	double	yp;
	double	angle;
	
	
	x = game->dirX;
	y = game->dirY;
	xp = game->planeX;
	yp = game->planeY;
	angle = ROTATION_ANGLE;
	game->dirX = x * cos(angle) - y * sin(angle);
	game->dirY = x * sin(angle) + y * cos(angle);
	game->planeX = xp * cos(angle) - yp * sin(angle);
	game->planeY = xp * sin(angle) + yp * cos(angle);
}

void	go_straight(t_global_settings *game)
{
	if ((game->map.map)[(int)(game->posX + game->dirX * SPEED)][(int)(game->posY)] != '1')
	{
		game->posX += game->dirX * SPEED;
	}
	if ((game->map.map)[(int)(game->posX)][(int)(game->posY + game->dirY * SPEED)] != '1')
	{
		game->posY += game->dirY * SPEED;
	}
}

void	go_back(t_global_settings *game)
{
	if ((game->map.map)[(int)(game->posX - game->dirX * SPEED)][(int)(game->posY)] != '1')
	{
		game->posX -= game->dirX * SPEED;
	}
	if ((game->map.map)[(int)(game->posX)][(int)(game->posY - game->dirY * SPEED)] != '1')
	{
		game->posY -= game->dirY * SPEED;
	}
}

void	go_left(t_global_settings *game)
{
	if ((game->map.map[(int)(game->posX + game->dirX - game->planeX)][(int)(game->posY)] != '1'))
	{
		game->posX -= game->planeX * SPEED;
	}
	if ((game->map.map[(int)(game->posX)][(int)(game->posY + game->dirY - game->planeY)] != '1'))
	{
		game->posY -= game->planeY * SPEED;
	}
}

void	go_right(t_global_settings *game)
{
	if ((game->map.map[(int)(game->posX + game->dirX + game->planeX)][(int)(game->posY)] != '1'))
	{
		game->posX += game->planeX * SPEED;
	}
	if ((game->map.map[(int)(game->posX)][(int)(game->posY + game->dirY + game->planeY)] != '1'))
	{
		game->posY += game->planeY * SPEED;
	}
}
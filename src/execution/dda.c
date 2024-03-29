/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:11:33 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/24 17:54:34 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_global_settings *game)
{
	init_ray(game);
	find_wall(game);
}

void	find_wall(t_global_settings *game)
{
	(void)game;
}

void	init_ray(t_global_settings *game)
{
	//recheck all the values are ok 
	game->cameraX = 2 * (game->x / (double)(GAME_WIDTH)) - 1;
	game->ray.rayDirX = game->dirX + game->planeX * game->cameraX;
	game->ray.rayDirY = game->dirY + game->planeY * game->cameraX;
	game->mapX = (int)game->posX;
	game->mapY = (int)game->posY;
	if (game->ray.rayDirX == 0)
		game->ray.deltaDistX = 1e30;
	else
		game->ray.deltaDistX = fabs(1 / game->ray.rayDirX);
	if (game->ray.rayDirY == 0)
		game->ray.deltaDistY = 1e30;
	else
		game->ray.deltaDistY = fabs(1 / game->ray.rayDirY);
	game->hit = 0;
	if (game->ray.rayDirX < 0)
	{
		game->stepX = -1;
		game->sideDistX *= (game->posX - game->mapX);
	}
	else
	{
		game->stepX = 1;
		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->ray.deltaDistX;
	}
	if (game->ray.rayDirY < 0)
	{
		game->stepY = -1;
		game->sideDistY = (game->posY - game->mapY) * game->ray.deltaDistY;
	}
	else
	{
		game->stepY = 1;
		game->sideDistY = (game->mapY + 1.0 - game->posY) * game->ray.deltaDistY;
	}

	//part2
	while (game->hit == 0)
	{
		if (game->sideDistX < game->sideDistY)
		{
			game->sideDistX += game->ray.deltaDistX;
			game->mapX += game->stepX;
			game->side = 0;
		}
		else
		{
			game->sideDistY += game->ray.deltaDistY;
			game->mapY += game->stepY;
			game->side = 1;
		}
		if (game->map[game->mapX][game->mapY] == '1')
			game->hit = 1;
	}

	//part3
	if (game->side == 0)
		game->perp_wall_dist = fabs((game->mapX - game->posX + \
		(1 - game->stepX) / 2) / game->ray.rayDirX);
	else
		game->perp_wall_dist = fabs((game->mapY - game->posY + \
		(1 - game->stepY) / 2) / game->ray.rayDirY);

	//part4
	if (!game->perp_wall_dist)
		game->perp_wall_dist = 1;
	game->line_height = (int)(GAME_WIDTH / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + GAME_WIDTH / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + GAME_WIDTH / 2;
	if (game->draw_end >= GAME_WIDTH)
		game->draw_end = GAME_WIDTH - 1;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:11:33 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/16 17:44:35 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Initializes the values used to calculate the ray:
	+cameraX is the x coordinate to the camera depending on ray X
	+rayDirX is the x coordinate 
*/
void	init_ray(t_global_settings *game)
{
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
}

void	init_ray2(t_global_settings *game)
{
	if (game->ray.rayDirX < 0)
	{
		game->stepX = -1;
		game->sideDistX = (game->posX - game->mapX) * game->ray.deltaDistX;
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
}
void	find_wall(t_global_settings *game)
{
	game->hit = 0;
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
		if (game->map.map[game->mapX][game->mapY] == '1')
			game->hit = 1;
	}
}

void set_border(t_global_settings *game)
{
	if (game->side == 0)
		game->perp_wall_dist = fabs((game->mapX - game->posX + (1 - game->stepX) / 2) / game->ray.rayDirX);
	else
		game->perp_wall_dist = fabs((game->mapY - game->posY + (1 - game->stepY) / 2) / game->ray.rayDirY);
	if (!game->perp_wall_dist)
		game->perp_wall_dist = 1;
	game->line_height = (int)(GAME_HEIGHT / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + GAME_HEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + GAME_HEIGHT / 2;
	if (game->draw_end >= GAME_HEIGHT)
		game->draw_end = GAME_HEIGHT - 1;
}

void	set_colors(t_global_settings *game)
{
	int	i;
	
	i = -1;
	while (++i < game->draw_start)
		game->mlxset.img.arr[i * GAME_WIDTH + game->x] = game->map.ceiling_color;	
	i = game->draw_end;
	while (++i < GAME_HEIGHT)
		game->mlxset.img.arr[i * GAME_WIDTH + game->x] = game->map.floor_color;
	
}

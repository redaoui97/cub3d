/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mriskyin <Mriskyin-team@student.42.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:11:33 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/16 15:17:28 by Mriskyin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
redo the raycasting algorithm:
visualize the algorithm; make a representation on how it works
try to implement it diffrently
*/
#include "cub3d.h"

void	raycasting(t_global_settings *game)
{
	/*loops through each vertical line of the screen, for a total of*/
	while (game->x < GAME_WIDTH)
	{
		init_ray(game);
		(game->x)++;
	}
	mlx_put_image_to_window(game->mlxset.mlx, game->mlxset.win_ptr, game->mlxset.img.img, 0, 0);
}

void	find_wall(t_global_settings *game)
{
	(void)game;
}

void	init_ray(t_global_settings *game)
{
	int	i;
	
	while (game->x < GAME_WIDTH)
	{
		game->cameraX = 2 * (game->x / (double)(GAME_WIDTH)) - 1;
		game->ray.rayDirX = game->dirX + game->planeX * game->cameraX;
		game->ray.rayDirY = game->dirY + game->planeY * game->cameraX;
		game->mapX = (int)game->posX;
		game->mapY = (int)game->posY;
		game->ray.deltaDistX = sqrt(1 + pow(game->ray.rayDirY, 2) / pow(game->ray.rayDirX, 2));
		game->ray.deltaDistY = sqrt(1 + pow(game->ray.rayDirX, 2) / pow(game->ray.rayDirY, 2));
		game->hit = 0;
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
		i = -1;
		while (++i < game->draw_start)
			game->mlxset.img.arr[i * GAME_WIDTH + game->x] = rgb_to_color(100,10,10);	
		i = game->draw_end;
		while (++i < GAME_HEIGHT)
			game->mlxset.img.arr[i * GAME_WIDTH + game->x] = 0x7CFC00;
		game->x++;
	}
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:11:33 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/24 15:37:25 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_ray(t_global_settings *game)
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
		game->ray.deltaDistX = abs(1 / game->ray.rayDirX);
	if (game->ray.rayDirY == 0)
		game->ray.deltaDistY = 1e30;
	else
		game->ray.deltaDistY = abs(1 / game->ray.rayDirY);
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
}
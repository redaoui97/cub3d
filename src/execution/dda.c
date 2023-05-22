/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:11:33 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/22 11:41:24 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_global_settings *game)
{
	game->camera_x = 2 * (game->x / (double)(GAME_WIDTH)) - 1;
	game->ray.ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray.ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}

void	init_raydir(t_global_settings *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->step_y = -1;
			game->side_dist_y = (game->pos_y - game->map_y) * game->ray.delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y)
			* game->ray.delta_dist_y;
	}
}

void	find_wall(t_global_settings *game)
{
	game->hit = 0;
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->ray.delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->ray.delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		//printf("mapy: %d mapx: %d\n", game->map_y, game->map_x);
		if (game->map.map[game->map_x][game->map_y] == '1')
			game->hit = 1;
	}
}

void	calculate_distance(t_global_settings *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->side_dist_x - game->ray.delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->ray.delta_dist_y);
	if (!game->perp_wall_dist)
		game->perp_wall_dist = 1;
	game->line_height = (int)(GAME_HEIGHT / (game->perp_wall_dist * 1.5));
	game->draw_start = (GAME_HEIGHT - game->line_height) / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = (GAME_HEIGHT + game->line_height) / 2;
	if (game->draw_end >= GAME_HEIGHT)
		game->draw_end = GAME_HEIGHT - 1;
	if (game->x == 0)
		game->perp_wall_dist_left = game->perp_wall_dist;
}

void	set_colors(t_global_settings *game)
{
	int	i;

	i = -1;
	while (++i < game->draw_start)
	{
		game->mlxset.img.arr[i * GAME_WIDTH + game->x]
			= game->map.ceiling_color;
	}
	i = game->draw_end;
	while (++i < GAME_HEIGHT)
	{
		game->mlxset.img.arr[i * GAME_WIDTH + game->x]
			= game->map.floor_color;
	}
}
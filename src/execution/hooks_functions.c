/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:25:05 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/17 18:48:37 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//change those values == '0'
void	go_straight(t_global_settings *game)
{
	if (game->perp_wall_dist < 0.2 || game->perp_wall_dist_left < 0.2)
		return ;
	if ((game->map.map)[(int)(game->pos_x + game->dir_x * SPEED)]
		[(int)(game->pos_y)] == '0')
	{
		game->pos_x += game->dir_x * SPEED;
	}
	if ((game->map.map)[(int)(game->pos_x)]
		[(int)(game->pos_y + game->dir_y * SPEED)] == '0')
	{
		game->pos_y += game->dir_y * SPEED;
	}
}

void	go_back(t_global_settings *game)
{
	if ((game->map.map)[(int)(game->pos_x - game->dir_x * SPEED)]
		[(int)(game->pos_y)] != '1')
	{
		game->pos_x -= game->dir_x * SPEED;
	}
	if ((game->map.map)[(int)(game->pos_x)]
		[(int)(game->pos_y - game->dir_y * SPEED)] != '1')
	{
		game->pos_y -= game->dir_y * SPEED;
	}
}

void	go_left(t_global_settings *game)
{
	if (game->perp_wall_dist_left < 0.2)
		return ;
	if ((game->map.map[(int)(game->pos_x + game->dir_x - game->plane_x)]
		[(int)(game->pos_y)] != '1'))
	{
		game->pos_x -= game->plane_x * SPEED;
	}
	if ((game->map.map[(int)(game->pos_x)]
		[(int)(game->pos_y + game->dir_y - game->plane_y)] != '1'))
	{
		game->pos_y -= game->plane_y * SPEED;
	}
}

void	go_right(t_global_settings *game)
{
	if (game->perp_wall_dist < 0.2)
		return ;
	if ((game->map.map[(int)(game->pos_x + game->dir_x + game->plane_x)]
		[(int)(game->pos_y)] != '1'))
	{
		game->pos_x += game->plane_x * SPEED;
	}
	if ((game->map.map[(int)(game->pos_x)]
		[(int)(game->pos_y + game->dir_y + game->plane_y)] != '1'))
	{
		game->pos_y += game->plane_y * SPEED;
	}
}

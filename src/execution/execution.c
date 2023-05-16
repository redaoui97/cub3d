/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:47:07 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/16 18:31:21 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	execution(t_global_settings *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlxset.mlx, game->mlxset.win_ptr,
		game->mlxset.img.img, 0, 0);
	return(0);
}

/*
	loops through each vertical line of the screen, for a total 
	of game window_width size
*/
void	raycasting(t_global_settings *game)
{
	while (game->x < GAME_WIDTH)
	{
		init_ray(game);
		init_ray2(game);
		find_wall(game);
		set_border(game);
		set_colors(game);
		(game->x)++;
	}	
}
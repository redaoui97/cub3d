/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:47:07 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/21 18:55:25 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	execution(t_global_settings *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlxset.mlx, game->mlxset.win_ptr,
		game->mlxset.img.img, 0, 0);
	return (0);
}

void	raycasting(t_global_settings *game)
{
	while (game->x < GAME_WIDTH)
	{
		if (init_textures(game) == FAIL)
			fatal_error("Error initializing textures!");
		init_ray(game);
		init_raydir(game);
		find_wall(game);
		calculate_distance(game);
		set_colors(game);
		//add textures to mlx
		(game->x)++;
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:37:02 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/27 11:10:35 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//delete this later
static void	init_map(t_global_settings *game)
{
	
	game->map = {
		{'1','1','1','1','1','1','1','1'},
		{'1','0','0','0','0','0','0','1'},
		{'1','0','1','0','0','1','0','1'},
		{'1','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','1'},
		{'1','0','0','N','0','0','0','1'},
		{'1','0','0','0','0','0','0','1'},
		{'1','1','1','1','1','1','1','1'},
	};
}

/*initializes mlx; opens a window; sets up the img and img array*/
int	set_up_game(t_global_settings *game)
{
	game->mlxset.mlx = mlx_init();
	if (game->mlxset.mlx == NULL)
		return (EXIT_FAILURE);
	game->mlxset.win_ptr = mlx_new_window(game->mlxset.mlx, GAME_WIDTH,
		GAME_HEIGHT, "LBENJENSTEIN64");
	if (game->mlxset.win_ptr == NULL)
		return (EXIT_FAILURE);
	game->mlxset.img.img = mlx_new_image(game->mlxset.mlx, GAME_WIDTH, 
		GAME_HEIGHT);
	if (game->mlxset.img.img == NULL)
		return (EXIT_FAILURE);
	game->mlxset.img.arr = (int *)mlx_get_data_addr(game->mlxset.img.img,
		&(game->mlxset.img.bits_per_pixel),
		&(game->mlxset.img.size_line),
		&(game->mlxset.img.endian));
	if (game->mlxset.img.arr == NULL)
		return (EXIT_FAILURE);
	init_map(game);
	return (EXIT_SUCCESS);
}

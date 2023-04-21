/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/21 13:36:05 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_up_game(t_global_settings *game)
{
	game->mlxset.mlx = mlx_init();
	game->mlxset.win_ptr = mlx_new_window(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT, "LBENJENSTEIN64");
	game->mlxset.img->img = mlx_new_image(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT);
	// game->img.arr = (int *)mlx_get_data_addr(game->img.ptr, &(game->img.bpp),&(game->img.len), &(game->img.endian));
	game->mlxset.img->arr = (int *)mlx_get_data_addr(game->mlxset.img->img, &(game->mlxset.img->bits_per_pixel), &(game->mlxset.img->size_line), &(game->mlxset.img->endian));
}

int main(int argc, char **argv)
{
	t_global_settings game;
	
	//argc protection
	//map reading
	//map parsing
	set_up_game(&game);
}
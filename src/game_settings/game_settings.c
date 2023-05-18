/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:37:02 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 20:07:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//to delete: hard coded initial values; retrieve from parser instead
// static void	init_map(t_global_settings *game)
// {
// 	//manually setting up the map struct values
// 	//map**
// 	//starting position
// 	//player direction
// 	// char map[8][8] = {
// 	// 	{'1','1','1','1','1','1','1','1'},
// 	// 	{'1','0','0','1','0','0','0','1'},
// 	// 	{'1','0','0','1','0','0','0','1'},
// 	// 	{'1','0','0','1','0','0','0','1'},
// 	// 	{'1','0','0','1','0','0','0','1'},
// 	// 	{'1','0','0','0','0','0','0','1'},
// 	// 	{'1','0','0','0','0','0','0','1'},
// 	// 	{'1','1','1','1','1','1','1','1'},
// 	// };
// 	// game->map.map = malloc(sizeof(char *) * 9);
// 	// for(int i=0; i<8; i++)
// 	// {
// 	// 	(game->map.map)[i] = malloc(sizeof(char) * 9);
// 	// 	ft_memcpy((game->map.map)[i], map[i], 8);
// 	// 	(game->map.map)[i][8] = '\0';
// 	// }
// 	// (game->map.map)[8] = NULL;
// 	game->map.starting_x = 5;
// 	game->map.starting_y = 2;
// 	// game->map.direction = 'S';
// 	// game->map.ceiling_color = 100000;
// 	// game->map.floor_color = 10000;
// }

static void	init_game_values(t_global_settings *game)
{
	game->pos_x = game->map.starting_x;
	game->pos_y = game->map.starting_y;
	if (game->map.direction == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (game->map.direction == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
}

static void	init_game_values1(t_global_settings *game)
{
	if (game->map.direction == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (game->map.direction == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
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
	//init_map(game);
	game->map.starting_x = 5;
	game->map.starting_y = 2;
	init_game_values(game);
	init_game_values1(game);
	return (EXIT_SUCCESS);
}

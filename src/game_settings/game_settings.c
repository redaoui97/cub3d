/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:37:02 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/16 14:36:12 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//to delete : hard coded map and starting values
static void	init_map(t_global_settings *game)
{
	//manually setting up the map struct values
	char map[8][8] = {
		{'1','1','1','1','1','1','1','1'},
		{'1','0','0','1','0','0','0','1'},
		{'1','0','0','1','0','0','0','1'},
		{'1','0','0','1','0','0','0','1'},
		{'1','0','0','1','0','0','0','1'},
		{'1','0','0','N','0','0','0','1'},
		{'1','0','0','0','0','0','0','1'},
		{'1','1','1','1','1','1','1','1'},
	};
	game->map.map = malloc(sizeof(char *) * 8);
	for(int i=0; i<8; i++)
	{
		(game->map.map)[i] = malloc(sizeof(int)*8);
		ft_memcpy((game->map.map)[i], map[i], 8);
	}
	game->map.starting_x = 5;
	game->map.starting_y = 3;
	game->map.direction = 'W';
}

static void	init_game_values(t_global_settings *game)
{
	game->posX = game->map.starting_x;
	game->posY = game->map.starting_y;
	if (game->map.direction == 'N')
	{
		game->dirX = -1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = 0.66;
	}
	else if (game->map.direction == 'S')
	{
		game->dirX = 1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = 0.66;
	}
}

static void	init_game_values2(t_global_settings *game)
{
	if (game->map.direction == 'E')
	{
		game->dirX = 0;
		game->dirY = 1;
		game->planeX = 0.66;
		game->planeY = 0;
	}
	else if (game->map.direction == 'W')
	{
		game->dirX = 0;
		game->dirY = -1;
		game->planeX = 0.66;
		game->planeY = 0;
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
	//delete later this line as it must be in parser
	init_map(game);
	init_game_values(game);
	init_game_values2(game);
	return (EXIT_SUCCESS);
}

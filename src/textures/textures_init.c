/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:57:41 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/22 11:40:53 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_texture_n(t_global_settings *game)
{
	void	*mlx_image;

	mlx_image = mlx_xpm_file_to_image(game->mlxset.mlx, game->map.n_t, (int *)GAME_WIDTH, (int *)GAME_HEIGHT);
	if (!mlx_image)
		return (FAIL);
	game->n_texture.texture_array = (int *)mlx_get_data_addr(game->mlxset.img.img, &game->mlxset.img.bits_per_pixel
		,&game->mlxset.img.size_line, &game->mlxset.img.endian);
	return (0);
}

// static int	init_texture_s(t_global_settings *game)
// {
// 	void	*mlx_image;

// 	mlx_image = mlx_xpm_file_to_image(game->mlxset.mlx, game->map.n_t, GAME_WIDTH, GAME_HEIGHT);
// 	if (!mlx_image)
// 		return (FAIL);
// 	game->s_texture.texture_array = (int *)mlx_get_data_addr(game->mlxset.img.img, game->mlxset.img.bits_per_pixel
// 		,game->mlxset.img.size_line, game->mlxset.img.endian);
// }

// static int	init_texture_w(t_global_settings *game)
// {
// 	void	*mlx_image;

// 	mlx_image = mlx_xpm_file_to_image(game->mlxset.mlx, game->map.n_t, GAME_WIDTH, GAME_HEIGHT);
// 	if (!mlx_image)
// 		return (FAIL);
// 	game->w_texture.texture_array = (int *)mlx_get_data_addr(game->mlxset.img.img, game->mlxset.img.bits_per_pixel
// 		,game->mlxset.img.size_line, game->mlxset.img.endian);
// }

// static int	init_texture_e(t_global_settings *game)
// {
// 	void	*mlx_image;

// 	mlx_image = mlx_xpm_file_to_image(game->mlxset.mlx, game->map.n_t, GAME_WIDTH, GAME_HEIGHT);
// 	if (!mlx_image)
// 		return (FAIL);
// 	game->e_texture.texture_array = (int *)mlx_get_data_addr(game->mlxset.img.img, game->mlxset.img.bits_per_pixel
// 		,game->mlxset.img.size_line, game->mlxset.img.endian);	
// }

int	init_textures(t_global_settings *game)
{
	return (SUCCESS);
	if (init_texture_n(game) == FAIL)
		return (FAIL);
	// else if (init_texture_s(game) == FAIL)
	// 	return (FAIL);
	// else if (init_texture_w(game) == FAIL)
	// 	return (FAIL);
	// else if (init_texture_e(game) == FAIL)
	// 	return (FAIL);
	else
		return (SUCCESS);
}

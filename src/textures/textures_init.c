/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:57:41 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/22 18:49:09 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//textures are hardcoded!!
static int	init_texture_n(t_global_settings *game)
{
	game->n_texture.texture_img_ptr = mlx_xpm_file_to_image(game->mlxset.mlx
		, "./textures/wood0.xpm", &(game->n_texture.texture_width)
			, &(game->n_texture.texture_height));
	if (!(game->n_texture.texture_img_ptr))
		return (FAIL);
	game->n_texture.texture_array = (int *)mlx_get_data_addr(
		game->n_texture.texture_img_ptr, &(game->n_texture.bits_per_pixel)
			, &(game->n_texture.size_line), &(game->n_texture.endian));
	return (SUCCESS);
}

static int	init_texture_s(t_global_settings *game)
{
	game->s_texture.texture_img_ptr = mlx_xpm_file_to_image(game->mlxset.mlx
		, "./textures/wood1.xpm", &(game->s_texture.texture_width)
			, &(game->s_texture.texture_height));
	if (!(game->s_texture.texture_img_ptr))
		return (FAIL);
	game->s_texture.texture_array = (int *)mlx_get_data_addr(
		game->s_texture.texture_img_ptr, &(game->s_texture.bits_per_pixel)
			, &(game->s_texture.size_line), &(game->s_texture.endian));
	return (SUCCESS);
}

static int	init_texture_w(t_global_settings *game)
{
	game->w_texture.texture_img_ptr = mlx_xpm_file_to_image(game->mlxset.mlx
		, "./textures/wood2.xpm", &(game->w_texture.texture_width)
			, &(game->w_texture.texture_height));
	if (!(game->w_texture.texture_img_ptr))
		return (FAIL);
	game->w_texture.texture_array = (int *)mlx_get_data_addr(
		game->w_texture.texture_img_ptr, &(game->w_texture.bits_per_pixel)
			, &(game->w_texture.size_line), &(game->w_texture.endian));
	return (SUCCESS);
}

static int	init_texture_e(t_global_settings *game)
{
	game->e_texture.texture_img_ptr = mlx_xpm_file_to_image(game->mlxset.mlx
		, "./textures/wood3.xpm", &(game->e_texture.texture_width)
			, &(game->e_texture.texture_height));
	if (!(game->e_texture.texture_img_ptr))
		return (FAIL);
	game->e_texture.texture_array = (int *)mlx_get_data_addr(
		game->e_texture.texture_img_ptr, &(game->e_texture.bits_per_pixel)
			, &(game->e_texture.size_line), &(game->e_texture.endian));
	return (SUCCESS);
}

int	init_textures(t_global_settings *game)
{
	if (init_texture_n(game) == FAIL)
		return (FAIL);
	else if (init_texture_s(game) == FAIL)
		return (FAIL);
	else if (init_texture_w(game) == FAIL)
		return (FAIL);
	else if (init_texture_e(game) == FAIL)
		return (FAIL);
	else
		return (SUCCESS);
}

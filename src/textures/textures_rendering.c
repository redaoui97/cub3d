/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_rendering.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:56:49 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 14:02:37 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*locate_wall_texture(t_global_settings *game)
{
	t_texture	*current_texture;

	current_texture = NULL;
	if (game->side == 0 && game->step_x == -1)
		current_texture = &(game->n_texture);
	else if (game->side == 0 && game->step_x == 1)
		current_texture = &(game->s_texture);
	else if (game->side == 1 && game->step_y == -1)
		current_texture = &(game->w_texture);
	else if (game->side == 1 && game->step_y == 1)
		current_texture = &(game->e_texture);
	game->current_texture = current_texture;	
	return (current_texture);
}

static void	calc_attr_textures(t_global_settings *game)
{
	t_texture	*current_texture;

	current_texture = locate_wall_texture(game);
	if (!game->current_texture)
		fatal_error("Error handling textures!\n");
	if (game->side == 0)
		game->wall_hit_pos = game->pos_y + game->perp_wall_dist * game->ray.ray_dir_y;
	else
		game->wall_hit_pos = game->pos_x + game->perp_wall_dist * game->ray.ray_dir_x;
	game->wall_hit_pos -= floor(game->wall_hit_pos);
	game->x_tex = (int)(game->wall_hit_pos * current_texture->texture_width);
	if (game->side == 0 && game->ray.ray_dir_x > 0)
		game->x_tex = current_texture->texture_width - game->x_tex - 1;
	else if (game->side == 1 && game->ray.ray_dir_y < 0)
		game->x_tex = current_texture->texture_width - game->x_tex - 1;
}

void	apply_textures(t_global_settings *game)
{
	double	step;
	double	texture_position;
	int		y_tex;
	int		i;
	int		color;
	
	(void)y_tex;
	calc_attr_textures(game);
	step = game->current_texture->texture_height / game->line_height;
	texture_position = (game->draw_start - GAME_HEIGHT / 2 + game->line_height / 2) * step;
	i = game->draw_start;
	while (i < game->draw_end)
	{
		y_tex = (int)texture_position & (game->current_texture->texture_height - 1);
		texture_position += step;
		color = game->current_texture->texture_array[game->current_texture->texture_height * y_tex + game->x_tex];
		game->mlxset.img.arr[i * GAME_WIDTH + game->x] = color;
		i++;
	}
}
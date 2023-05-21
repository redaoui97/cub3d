/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:57:41 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/21 16:03:31 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d"

int init_textures(t_global_settings *game)
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

static int	init_texture_n(t_global_settings *game)
{
	
}
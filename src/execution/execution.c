/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:47:07 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/24 17:51:18 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	execution(t_global_settings *game)
{
	while (game->x < GAME_WIDTH)
	{
		raycasting(game);
		(game->x)++;
	}
}
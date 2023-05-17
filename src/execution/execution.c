/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mriskyin <Mriskyin-team@student.42.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:47:07 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/16 18:31:05 by Mriskyin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	execution(t_global_settings *game)
{
	while (game->x < GAME_WIDTH)
	{
		raycasting(game);
		(game->x)++;
	}
	return(0);
}
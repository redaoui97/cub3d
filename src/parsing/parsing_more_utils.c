/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_more_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:34:46 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/23 19:38:01 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_position_and_check(t_global_settings *game)
{
	if (check_if_done(game) != 1)
		fatal_error("error setting a crucial element!\n");
	if (get_player_position(game) != SUCCESS)
		fatal_error("error getting player position and/or direction.");
	if (map_sanity_check(game) != SUCCESS)
		fatal_error("error parsing the map!");
}

int	player_pos(t_global_settings *s, int *count, int i, int j)
{
	(*count)++;
	if ((*count) == 2)
		return (FAIL);
	if (check_surroundings(s, i, j) == FAIL)
		return (FAIL);
	s->map.direction = s->map.map[j][i];
	s->map.starting_x = j;
	s->map.starting_y = i;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:03:13 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/18 19:14:40 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	condition_direction(t_global_settings *s, int i, int j)
{
	return (s->map.map[j][i] == 'N' || s->map.map[j][i] == 'E'
			|| s->map.map[j][i] == 'W' || s->map.map[j][i] == 'S');
}

int	get_player_position(t_global_settings *s)
{
	size_t	j;
	size_t	i;

	if (check_first_last(s) == FAIL)
		return (FAIL);
	j = 1;
	while (j < s->map.y - 1)
	{
		i = 0;
		while (s->map.map[j][i] != '\x00')
		{
			if (condition_direction(s, i, j))
			{
				if (check_surroundings(s, i, j) == FAIL)
					return (FAIL);
				s->map.direction = s->map.map[j][i];
				s->map.starting_x = i;
				s->map.starting_y = j;
				return (SUCCESS);
			}
			i++;
		}
		j++;
	}
	return (FAIL);
}

// Map sanity check

int	map_check(t_global_settings *s, size_t i, size_t j)
{
	if (i == 0 || i > ft_strlen(s->map.map[j - 1])
		|| i > ft_strlen(s->map.map[j + 1]))
		return (FAIL);
	if (s->map.map[j - 1][i] != '0' && s->map.map[j - 1][i] != '1'
	&& s->map.map[j - 1][i] != s->map.direction)
		return (FAIL);
	if (s->map.map[j + 1][i] != '0' && s->map.map[j + 1][i] != '1'
	&& s->map.map[j + 1][i] != s->map.direction)
		return (FAIL);
	if (s->map.map[j][i + 1] != '0' && s->map.map[j][i + 1] != '1'
	&& s->map.map[j][i + 1] != s->map.direction)
		return (FAIL);
	if (s->map.map[j][i - 1] != '0' && s->map.map[j][i - 1] != '1'
	&& s->map.map[j][i - 1] != s->map.direction)
		return (FAIL);
	return (SUCCESS);
}

int	map_sanity_check(t_global_settings *s)
{
	size_t	j;
	size_t	i;

	if (check_first_last(s) == FAIL)
		return (FAIL);
	j = 1;
	while (j < s->map.y - 1)
	{
		i = 0;
		while (s->map.map[j][i] != '\x00')
		{
			if (s->map.map[j][i] == '0')
			{
				if (map_check(s, i, j) == FAIL)
					return (FAIL);
			}
			i++;
		}
		j++;
	}
	return (SUCCESS);
}

// conditions to check for parsing
int	is_texture(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \n\v\r\t\f");
	if (!ft_strncmp(tmp, "NO ", 3) || !ft_strncmp(tmp, "SO ", 3)
		|| !ft_strncmp(tmp, "WE ", 3) || !ft_strncmp(tmp, "EA ", 3))
	{
		free(tmp);
		return (1);
	}
	else
		return (0);
}

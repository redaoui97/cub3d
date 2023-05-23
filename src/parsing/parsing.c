/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:59:44 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/23 11:06:28 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_floor(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \n\v\r\t\f");
	if (!ft_strncmp(tmp, "F ", 2))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int	is_ceiling(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \n\v\r\t\f");
	if (!ft_strncmp(tmp, "C ", 2))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int	check_if_done(t_global_settings *game)
{
	if (
		game->map.e_t != NULL && game->map.n_t != NULL
		&& game->map.s_t != NULL && game->map.w_t != NULL
		&& game->map.ceiling_color != 0 && game->map.floor_color != 0
		&& game->map.map != NULL
	)
		return (1);
	return (0);
}

int	parse_core(t_global_settings *game, int fd)
{
	char	*line;

	while (check_if_done(game) != 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (is_texture(line))
			parse_textures(game, line);
		else if (is_floor(line))
			game->map.floor_color = parse_f_or_c(line, "F");
		else if (is_ceiling(line))
			game->map.ceiling_color = parse_f_or_c(line, "C");
		else
			read_raw_map(game, line, fd);
		free(line);
	}
	if (check_if_done(game) != 1)
		fatal_error("error setting a crucial element!\n");
	if (get_player_position(game) != SUCCESS)
		fatal_error("error getting player position and/or direction.");
	if (map_sanity_check(game) != SUCCESS)
		fatal_error("error parsing the map!");
	return (SUCCESS);
}

int	parse(t_global_settings *game, char *file)
{
	int	map;

	ft_memset(&game->map, 0, sizeof game->map);
	map = open_file(file);
	parse_core(game, map);
	return (0);
}

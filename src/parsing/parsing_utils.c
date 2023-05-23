/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:03:24 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/23 19:38:10 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		fatal_error("Check if the map exists and is accessible!\n");
	return (fd);
}

void	parse_textures_core(t_global_settings *s, char **dir_path)
{
	dir_path[1][ft_strlen(dir_path[1]) - 1] = 0;
	if (!ft_strncmp(dir_path[0], "NO", 3))
		s->map.n_t = ft_strjoin(ft_strdup("./"), dir_path[1]);
	else if (!ft_strncmp(dir_path[0], "SO", 3))
		s->map.s_t = ft_strjoin(ft_strdup("./"), dir_path[1]);
	else if (!ft_strncmp(dir_path[0], "WE", 3))
		s->map.w_t = ft_strjoin(ft_strdup("./"), dir_path[1]);
	else if (!ft_strncmp(dir_path[0], "EA", 3))
		s->map.e_t = ft_strjoin(ft_strdup("./"), dir_path[1]);
	else
		fatal_error("Error parsing textures!");
}

int	parse_textures(t_global_settings *s, char *line)
{
	char	**dir_path;

	dir_path = ft_split(line, ' ');
	parse_textures_core(s, dir_path);
	free(dir_path[0]);
	free(dir_path[1]);
	free(dir_path);
	return (0);
}

int	count_p(char **p)
{
	int	i;

	i = 0;
	if (p == NULL)
		return (0);
	while (p[i])
		i++;
	return (i);
}

int	rgb_to_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

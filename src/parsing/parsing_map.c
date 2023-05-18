/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:03:20 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/18 18:52:40 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rgb_calc(t_rgb *r, char **rgb)
{
	r->r = ft_atoi(rgb[0]);
	r->g = ft_atoi(rgb[1]);
	r->b = ft_atoi(rgb[2]);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
}

int	parse_f_or_c(char *line, char *f_or_c)
{
	char	*tmp;
	char	**p;
	char	**rgb;
	t_rgb	r;

	tmp = ft_strtrim(line, " \n\v\r\t\f");
	p = ft_split(tmp, ' ');
	if (p == NULL || ft_strncmp(p[0], f_or_c, 2) || p[1] == NULL)
		fatal_error("something went wrong parsing the map!\n");
	rgb = ft_split(p[1], ',');
	free(p[0]);
	free(p[1]);
	free(p);
	if (rgb == NULL || count_p(rgb) != 3)
		fatal_error("Error parsing rgb format.");
	rgb_calc(&r, rgb);
	return (rgb_to_color(r.r, r.g, r.b));
}

void	read_raw_map(t_global_settings *s, char *line, int map)
{
	char	*tmp;
	char	*row;
	int		y;

	tmp = ft_strdup(line);
	y = 0;
	while (1)
	{
		row = get_next_line(map);
		if (row == NULL)
			break ;
		tmp = ft_strjoin(tmp, row);
		y++;
		free(row);
	}
	s->map.map = ft_split(tmp, '\n');
	s->map.y = y;
}

int	check_surroundings(t_global_settings *s, size_t i, size_t j)
{
	if (i == 0 || i > ft_strlen((const char *)s->map.map[j - 1])
		|| i > ft_strlen((const char *)s->map.map[j + 1]))
		return (FAIL);
	if (s->map.map[j - 1][i] != '0' && s->map.map[j - 1][i] != '1')
		return (FAIL);
	if (s->map.map[j + 1][i] != '0' && s->map.map[j + 1][i] != '1')
		return (FAIL);
	if (s->map.map[j][i + 1] != '0' && s->map.map[j][i + 1] != '1')
		return (FAIL);
	if (s->map.map[j][i - 1] != '0' && s->map.map[j][i - 1] != '1')
		return (FAIL);
	return (SUCCESS);
}

int	check_first_last(t_global_settings *s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s->map.map[0]))
	{
		if (s->map.map[0][i] != ' ' && s->map.map[0][i] != '1')
			return (FAIL);
		i++;
	}
	i = 0;
	while (i < ft_strlen(s->map.map[s->map.y]))
	{
		if (s->map.map[s->map.y][i] != ' '
			&& s->map.map[s->map.y][i] != '1')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

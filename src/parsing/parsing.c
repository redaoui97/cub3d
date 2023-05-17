/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:24:18 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/17 14:27:26 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	file_check(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		fatal_error("Error reading map! Check if the map exists \
		and is accessible!");
	return (fd);
}

void	map_check(char *map_file)
{
	int	file_fd;

	(void)file_fd;
	file_fd = file_check(map_file);
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include ""
#include "get_next_line.h"
#include "../libft/libft.h"

#define SUCCESS 0
#define FAIL 	-1 

void	simple_error(char *msg)
{
	int	i;
	
	(void)i;
	i = write (2, msg, ft_strlen(msg));
}

void	fatal_error(char *msg)
{
	simple_error(msg);
	exit(1);
}

static	int	open_file(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		fatal_error("Error reading map! Check if the map exists and is accessible!\n");
	return (fd);
}

int parse_textures(int fd)
{
	char *tmp1, *tmp;
	char **dir_path;
	int i;

	i = 0;
	while (i < 4)
	{
		tmp1 = get_next_line(fd);
		tmp = ft_strtrim(tmp1, " \n\v\r\t\f");
		free(tmp1);
		dir_path = ft_split(tmp, ' ');
		if 		(!ft_strncmp(dir_path[0], "NO", 3))
			m.n_t = dir_path[1];
		else if (!ft_strncmp(dir_path[0], "SO", 3))
			m.s_t = dir_path[1];
		else if (!ft_strncmp(dir_path[0], "WE", 3))
			m.w_t = dir_path[1];
		else if (!ft_strncmp(dir_path[0], "EA", 3))
			m.e_t = dir_path[1];
		else
			fatal_error("Error parsing textures!");
		free(dir_path[0]);
		free(dir_path);
		i++;
	}
	return 0;
}

static int count_p(char **p)
{
	int i;

	i = 0;
	if (p == NULL)
		return 0;
	while (p[i])
		i++;
	return i;
}

static int rgb_to_color(char red, char green, char blue) {
      return (red << 16) | (green << 8) | blue;
}

int parse_f_or_c(int map, char *f_or_c)
{
	char *tmp1, *tmp;
	char **p, **rgb;
	t_rgb r;

	tmp1 = get_next_line(map);
	tmp = ft_strtrim(tmp1, " \n\v\r\t\f");
	free(tmp1);

	p = ft_split(tmp, ' ');
	if (p == NULL || ft_strncmp(p[0], f_or_c, 2) || p[1] == NULL)
		fatal_error("something went wrong parsing the map!\n");
	rgb = ft_split(p[1], ',');
	free(p[0]);
	free(p[1]);
	free(p);
	if (rgb == NULL || count_p(rgb) != 3)
		fatal_error("Error parsing rgb format.");
	r.r = ft_atoi(rgb[0]);
	r.g = ft_atoi(rgb[1]);
	r.b = ft_atoi(rgb[2]);
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	return rgb_to_color(r.r, r.g, r.b);
}

int parse_floor_ceiling(int map)
{
	int ret;
	
	m.floor = parse_f_or_c(map, "F");
	m.ceiling = parse_f_or_c(map, "C");
}

// map parsing
int read_raw_map(int map)
{
	char	*tmp;
	char	*row;
	int		y;

	tmp = ft_strdup("");
	y = 0;
	while (1) {
		row = get_next_line(map);
		if (row == NULL)
			break;
		tmp = ft_strjoin(tmp, row);
		y++;
		free(row);
	}
	m.map = ft_split(tmp, '\n');
	m.y = y;
}

// this should be called before the call to map_sanity_check.
int get_player_position() {
	int j;
	int i;
	//First and last line conditions should all be either 1 or space. 

	//If there is 0 check that is surrounded by either 0 or 1.
	j = 1;
	while (j < m.y - 1)
	{
		i = 0;
		while (m.map[j][i] != '\x00')
		{
			if (m.map[j][i] == 'N' || m.map[j][i] == 'E' || m.map[j][i] == 'W' || m.map[j][i] == 'S')
			{
				if (i == 0 || i > ft_strlen(m.map[j - 1]) || i > ft_strlen(m.map[j + 1]))
					return FAIL;
				if (m.map[j - 1][i] != '0' && m.map[j - 1][i] != '1')
					return FAIL;
				if (m.map[j + 1][i] != '0' && m.map[j + 1][i] != '1')
					return FAIL;
				if (m.map[j][i + 1] != '0' && m.map[j][i + 1] != '1')
					return FAIL;
				if (m.map[j][i - 1] != '0' && m.map[j][i - 1] != '1')
					return FAIL;
				
				m.direction = m.map[j][i];
				m.init_x = i;
				m.init_y = j;
				return SUCCESS;
			}
			i++;
		}
		j++;
	}
	return FAIL;
}

int map_sanity_check() {
	int j;
	int i;
	//First and last line conditions should all be either 1 or space. 

	//If there is 0 check that is surrounded by either 0 or 1.
	j = 1;
	while (j < m.y - 1)
	{
		i = 0;
		while (m.map[j][i] != '\x00')
		{
			if (m.map[j][i] == '0')
			{
				if (i == 0 || i > ft_strlen(m.map[j - 1]) || i > ft_strlen(m.map[j + 1]))
					return FAIL;
				if (m.map[j - 1][i] != '0' && m.map[j - 1][i] != '1' && m.map[j - 1][i] != m.direction)
					return FAIL;
				if (m.map[j + 1][i] != '0' && m.map[j + 1][i] != '1' && m.map[j + 1][i] != m.direction)
					return FAIL;
				if (m.map[j][i + 1] != '0' && m.map[j][i + 1] != '1' && m.map[j][i + 1] != m.direction)
					return FAIL;
				if (m.map[j][i - 1] != '0' && m.map[j][i - 1] != '1' && m.map[j][i - 1] != m.direction)
					return FAIL;
			}
			i++;
		}
		j++;
	}
	return SUCCESS;
}

int parse(char *file) {
	int map;

	printf("main to test the parser!\n");
	if (argc != 2)
		fatal_error("provide a map to parse.");
	map = open_file(file);
	parse_textures(map);
	free(get_next_line(map));
	parse_floor_ceiling(map);
	free(get_next_line(map));
	read_raw_map(map);
	if (get_player_position() != SUCCESS)
		fatal_error("error getting player position and/or direction.");
	if (map_sanity_check() != SUCCESS)
		fatal_error("error parsing the map!");
}

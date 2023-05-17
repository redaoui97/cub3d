/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mriskyin <Mriskyin-team@student.42.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:40 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/17 14:54:41 by Mriskyin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/errno.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define GAME_HEIGHT 1024
# define GAME_WIDTH 1024
# define SPEED 0.1
# define ROTATION_ANGLE 0.11
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define SUCCESS 0
# define FAIL 	-1

typedef struct s_rgb {
	int r;
	int g;
	int b;
} t_rgb;

// parsing struct
typedef struct s_map {
	char *n_t;
	char *s_t;
	char *w_t;
	char *e_t;

	int floor_color;
	int ceiling_color;

	char **map;
	// how many rows in the map.
	size_t y;

	// player
	char direction;
	int starting_x;
	int starting_y;
}	t_map;

typedef	struct	s_ray
{
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
	int			map_x;
	int			map_y;
}				t_ray;

typedef struct s_img
{
	void		*img;
	int			*arr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_mlx_settings
{
	void		*mlx;
	void		*win_ptr;
	t_img		img;
}				t_mlx_settings;

typedef struct s_global_settings
{
	t_mlx_settings	mlxset;
	t_ray			ray;
	double			cameraX;
	double			posX;
	double			posY;
	double			planeX;
	double			planeY;
	double			dirX;
	double			dirY;
	double			stepX;
	double			stepY;
	double			sideDistX;
	double			sideDistY;
	double			perp_wall_dist;
	double			line_height;
	double			draw_start;
	double			draw_end;
	t_map			map;
	int				ceiling_color;
	int				floor_color;
	// player initial position
	int				mapX;
	int				mapY;
	int				hit;
	int				x;
	int				side;
}			 	t_global_settings;

/*=============FUNCTION PROTOTYPES=============*/

/*===============main functions================*/

/*===========execution functions===========*/
int		execution(t_global_settings *game);
void	init_ray(t_global_settings *game);
void	raycasting(t_global_settings *game);
void	find_wall(t_global_settings *game);

int   	key_press(int key_pressed, t_global_settings *game);
void    go_straight(t_global_settings *game);
void    go_back(t_global_settings *game);
void    go_left(t_global_settings *game);
void    go_right(t_global_settings *game);
void	rotate_left(t_global_settings *game);
void	rotate_right(t_global_settings *game);


/*==============parsing functions==============*/
int		open_file(char *mapfile);
void	parse_textures_core(t_global_settings *s, char **dir_path);
int		parse_textures(t_global_settings *s, char *line);
int		count_p(char **p);
int		rgb_to_color(char red, char green, char blue);

void	rgb_calc(t_rgb *r, char **rgb);
int		parse_f_or_c(char *line, char *f_or_c);
void	read_raw_map(t_global_settings *s, char *line, int map);
int		check_surroundings(t_global_settings *s, size_t i, size_t j);
int		check_first_last(t_global_settings *s);

int		condition_direction(t_global_settings *s, int i, int j);
int		get_player_position(t_global_settings *s);
int		map_check(t_global_settings *s, size_t i, size_t j);
int		map_sanity_check(t_global_settings *s);
int		is_texture(char *line);

int		is_floor(char *line);
int		is_ceiling(char *line);
int		check_if_done(t_global_settings *game);
int		parse_core(t_global_settings *game, int fd);
int		parse(t_global_settings *game, char *file);
/*===============error functions===============*/
void	fatal_error(char *msg);
void	simple_error(char *msg);

/*===============utils functions===============*/

/*===========game settings functions===========*/
int		set_up_game(t_global_settings *game);

/*===========END FUNCTION PROTOTYPES===========*/
#endif
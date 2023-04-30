/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:40 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/30 13:58:54 by rnabil           ###   ########.fr       */
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

# define GAME_HEIGHT 1024
# define GAME_WIDTH 1024
# define SPEED 0.4
# define ANGLE 0.2
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 2
# define RIGHT_KEY 0
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124

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

typedef	struct	s_ray
{
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
	int			map_x;
	int			map_y;
}				t_ray;

typedef struct	s_map
{
	char		**map;
	int			starting_x;
	int			starting_y;
	char		direction;
}				t_map;

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
	
	//type			ceiling_color;
	//type			floor_color;
	t_map			map;
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
int 	rgb_to_color(unsigned int red, unsigned int green, unsigned int blue);

/*==============parsing functions==============*/
void	map_check(char *map_file);
/*===============error functions===============*/
void	fatal_error(char *msg);
void	simple_error(char *msg);

/*===============utils functions===============*/
int		ft_strlen(char *msg);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*===========game settings functions===========*/
int		set_up_game(t_global_settings *game);

/*===========END FUNCTION PROTOTYPES===========*/
#endif
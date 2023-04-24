/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:40 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/24 17:53:33 by rnabil           ###   ########.fr       */
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
# include "../../mlx_linux/mlx.h"

#ifndef GAME_HEIGHT
# define GAME_HEIGHT 1024
#endif

#ifndef GAME_WIDTH
# define GAME_WIDTH 1024
#endif

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
	char			**map;
	int				mapX;
	int				mapY;
	int				hit;
	int				x;
	int				side;
	
}			 	t_global_settings;

/*=============FUNCTION PROTOTYPES=============*/

/*===============main functions================*/

/*===========execution functions===========*/
void	execution(t_global_settings *game);
void	init_ray(t_global_settings *game);
void	raycasting(t_global_settings *game);
void	find_wall(t_global_settings *game);
/*==============parsing functions==============*/
void	map_check(char *map_file);

/*===============error functions===============*/
void	fatal_error(char *msg);
void	simple_error(char *msg);

/*===============utils functions===============*/
int		ft_strlen(char *msg);

/*===========game settings functions===========*/
int		set_up_game(t_global_settings *game);

/*===========END FUNCTION PROTOTYPES===========*/
#endif
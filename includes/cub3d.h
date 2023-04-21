/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:40 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/21 13:35:11 by rnabil           ###   ########.fr       */
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
	t_img		*img;
}				t_mlx_settings;

typedef struct s_global_settings
{
	t_mlx_settings	mlxset;
	
}			 	t_global_settings;

#endif
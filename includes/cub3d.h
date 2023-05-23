/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:27:40 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 10:56:30 by mazzouzi         ###   ########.fr       */
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
# define SPEED 0.1
# define ROTATION_ANGLE 0.17444444444444446
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define ESCAPE_KEY 53
# define SUCCESS 0
# define FAIL 	-1

typedef struct s_texture {
	void		*texture_img_ptr;
	int			*texture_array;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			texture_width;
	int			texture_height;
}				t_texture;

typedef struct s_rgb {
	int r;
	int g;
	int b;
}				t_rgb;

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

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			map_x;
	int			map_y;
}				t_ray;

typedef struct s_map
{
	size_t 		y;
	char 		*n_t;
	char 		*s_t;
	char 		*w_t;
	char 		*e_t;
	char		**map;
	char		direction;
	int			starting_x;
	int			starting_y;
	int			ceiling_color;
	int			floor_color;
}				t_map;

typedef struct s_global_settings
{
	t_mlx_settings	mlxset;
	t_ray			ray;
	t_map			map;
	t_texture		n_texture;
	t_texture		s_texture;
	t_texture		e_texture;
	t_texture		w_texture;
	double			camera_x;
	double			pos_x;
	double			pos_y;
	double			plane_x;
	double			plane_y;
	double			dir_x;
	double			dir_y;
	double			step_x;
	double			step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	double			perp_wall_dist_left;
	double			line_height;
	double			draw_start;
	double			draw_end;
	int				map_x;
	int				map_y;
	int				hit;
	int				x;
	int				side;
}				t_global_settings;

/*=============FUNCTION PROTOTYPES=============*/

/*===============main functions================*/

/*===========execution functions===========*/
int		execution(t_global_settings *game);
void	raycasting(t_global_settings *game);
void	init_ray(t_global_settings *game);
void	init_raydir(t_global_settings *game);
void	find_wall(t_global_settings *game);
void	calculate_distance(t_global_settings *game);
void	set_colors(t_global_settings *game);

/*===========textures functions===========*/
int		init_textures(t_global_settings *game);
void	locate_wall_texture(t_global_settings *game);

/*===========hooks functions===========*/
int		key_press(int key_pressed, t_global_settings *game);
int		key_press_rotate(int key_pressed, t_global_settings *game);
void	free_and_exit(t_global_settings *game);
void	go_straight(t_global_settings *game);
void	go_back(t_global_settings *game);
void	go_left(t_global_settings *game);
void	go_right(t_global_settings *game);
void	rotate_left(t_global_settings *game);
void	rotate_right(t_global_settings *game);

/*==============parsing functions==============*/
int		open_file(char *mapfile);
void	parse_textures_core(t_global_settings *s, char **dir_path);
int		parse_textures(t_global_settings *s, char *line);
int		count_p(char **p);
int		rgb_to_color(int red, int green, int blue);

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

/*===========LIBFT functions===========*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*===========Get_next_line functions===========*/
char	*get_next_line(int fd);
int		ft_core(char **buf, char **line, int *i, char **reminder);
char	*ft_clean(char *buf, char *line);
char	*ft_strndup(char *s, size_t size);
int		return_endl_index(char *s);
char	*strnjoin(char *s1, char *s2, int n);
char	*ft_strcat(char *dest, char *src);

/*===========END FUNCTION PROTOTYPES===========*/
#endif
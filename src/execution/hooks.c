/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:19 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/30 16:20:51 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    key_press(int key_pressed, t_global_settings *game)
{
    printf("key pressed:%d\n",key_pressed);
    if (key_pressed == UP_KEY)
        go_straight(game);
    else if (key_pressed == DOWN_KEY)
        go_back(game);
    else if (key_pressed == LEFT_KEY)
        go_left(game);
    else if (key_pressed == RIGHT_KEY)
        go_right(game);
    else if (key_pressed == LEFT_ARROW_KEY)
        rotate_left(game);
    else if (key_pressed == RIGHT_ARROW_KEY)
        rotate_right(game);
    else
        return (1);
    game->x = 0;
    mlx_destroy_image(game->mlxset.mlx, game->mlxset.img.img);
	game->mlxset.img.img = mlx_new_image(game->mlxset.mlx, GAME_WIDTH, GAME_HEIGHT);
    mlx_clear_window(game->mlxset.mlx, game->mlxset.win_ptr);
    execution(game);
    return (0);
}

void    rotate_left(t_global_settings *game)
{
    (void)game;
}

void    rotate_right(t_global_settings *game)
{
    (void)game;
}

void    go_straight(t_global_settings *game)
{
    if ((game->map.map)[(int)(game->posX + game->dirX * SPEED)][(int)(game->posY)] != '1')
    {
        game->posX += game->dirX * SPEED;
    }
	if ((game->map.map)[(int)(game->posX)][(int)(game->posY + game->dirY * SPEED)] != '1')
	{
		game->posY += game->dirY * SPEED;
	}
}

void    go_back(t_global_settings *game)
{
	if ((game->map.map)[(int)(game->posX - game->dirX * SPEED)][(int)(game->posY)] != '1')
    {
        game->posX -= game->dirX * SPEED;
    }
	if ((game->map.map)[(int)(game->posX)][(int)(game->posY - game->dirY * SPEED)] != '1')
	{
		game->posY -= game->dirY * SPEED;
	}
}

void    go_left(t_global_settings *game)
{
	if ((game->map.map[(int)(game->posX + game->dirX - game->planeX)][(int)(game->posY)] != '1'))
	{
		game->posX -= game->planeX * SPEED;
	}
	if ((game->map.map[(int)(game->posX)][(int)(game->posY + game->dirY - game->planeY)] != '1'))
	{
		game->posY -= game->planeY * SPEED;
	}
}

void    go_right(t_global_settings *game)
{
		printf("hh");
	if ((game->map.map[(int)(game->posX + game->dirX + game->planeX)][(int)(game->posY)] != '1'))
	{
		game->posX += game->planeX * SPEED;
	}
	if ((game->map.map[(int)(game->posX)][(int)(game->posY + game->dirY + game->planeY)] != '1'))
	{
		game->posY += game->planeY * SPEED;
	}
}
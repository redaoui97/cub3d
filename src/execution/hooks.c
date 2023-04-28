/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:58:19 by rnabil            #+#    #+#             */
/*   Updated: 2023/04/28 16:36:59 by rnabil           ###   ########.fr       */
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
    game->posX += SPEED;
}

void    go_back(t_global_settings *game)
{
    game->posX -= SPEED;
}

void    go_left(t_global_settings *game)
{
    game->posY += SPEED;
}

void    go_right(t_global_settings *game)
{
    game->posY -= SPEED;
}
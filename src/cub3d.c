/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mriskyin <Mriskyin-team@student.42.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/17 12:11:56 by Mriskyin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_global_settings game;
	
	if (argc != 2)
		fatal_error("Program must have 1 argument!");
	/*game init*/
	if (set_up_game(&game) == EXIT_FAILURE)
		fatal_error("Error setting up mlx settings!");
	parse(&game, argv[1]);
	printf("%s\n", game.map.map[15]);
	printf("%c\n", game.map.direction);
	printf("%d\n", game.map.starting_x);
	printf("%d\n", game.map.starting_y);

	printf("%s\n", game.map.w_t);
	printf("%s\n", game.map.e_t);
	printf("%s\n", game.map.s_t);
	printf("%s\n", game.map.n_t);
	mlx_hook(game.mlxset.win_ptr, 2, 0, key_press, &game);
	mlx_loop_hook(game.mlxset.mlx, execution, &game);
	mlx_loop(game.mlxset.mlx);
}
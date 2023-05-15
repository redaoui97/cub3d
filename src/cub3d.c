/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mriskyin <Mriskyin-team@student.42.ma>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:34:14 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/15 19:16:56 by Mriskyin         ###   ########.fr       */
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
	(void)argv;
	/*map check*/
	//add protection
	//map_check(argv[1]);
	mlx_hook(game.mlxset.win_ptr, 2, 0, key_press, &game);
	mlx_loop_hook(game.mlxset.mlx ,execution, &game);
	mlx_loop(game.mlxset.mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:08:32 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/20 15:13:07 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fatal_error(char *msg)
{
	simple_error(msg);
	exit(1);
}

void	simple_error(char *msg)
{
	int	i;

	(void)i;
	i = write (2, msg, ft_strlen(msg));
}

void	free_and_exit(t_global_settings *game)
{
	(void)game;
	//free_attributes(game);
	exit(0);
}
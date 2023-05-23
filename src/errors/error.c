/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:08:32 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/23 16:18:00 by rnabil           ###   ########.fr       */
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

int	free_and_exit()
{
	exit(0);
	return (0);
}

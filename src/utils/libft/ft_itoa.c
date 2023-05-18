/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:23:05 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 16:37:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_size(unsigned int a)
{
	int	size;

	size = 0;
	if (a == 0)
		size++;
	while (a >= 1)
	{
		size++;
		a /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*a;
	int				size;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	size = get_size(nbr);
	if (n < 0)
		size++;
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (!a)
		return (NULL);
	a[size] = '\0';
	size--;
	while (size >= 0)
	{
		a[size] = nbr % 10 + '0';
		nbr /= 10;
		size--;
	}
	if (n < 0)
		a[0] = '-';
	return (a);
}

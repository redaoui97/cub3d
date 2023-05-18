/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:43:47 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 16:40:50 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (*a)
	{
		if (*a == (unsigned char)c)
			return ((char *)a);
		a++;
	}
	if (c == '\0')
		return ((char *)a);
	return (NULL);
}

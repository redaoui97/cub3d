/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:05:17 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 16:41:16 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*a;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(s + i) == (unsigned char)c)
		{
			a = (unsigned char *)(s + i);
			return ((char *)a);
		}
		i--;
	}
	return (NULL);
}

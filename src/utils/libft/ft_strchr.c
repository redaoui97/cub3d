/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:43:47 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/05 16:31:41 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:12:49 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 16:38:53 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (len - i && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			while (j < ft_strlen (needle))
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}

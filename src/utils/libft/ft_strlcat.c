/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 08:49:38 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 16:38:38 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	return_value;

	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize < ft_strlen(dest))
		return_value = (ft_strlen(src) + dstsize);
	else
		return_value = (ft_strlen(src) + ft_strlen(dest));
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && i + 1 < dstsize)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (return_value);
}

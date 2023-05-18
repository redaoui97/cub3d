/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 08:49:38 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/05 16:19:28 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

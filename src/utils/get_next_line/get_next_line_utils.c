/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:00:25 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/22 11:30:19 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncat(char *dst, char *src, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n != 0)
	{
		while (dst[i])
			i++;
		while (j < n && src[j])
		{
			dst[i++] = src[j++];
		}
		dst[i] = 0;
	}
	return (dst);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i++] = src[j++];
	}
	dest[i] = src[j];
	return (dest);
}

char	*strnjoin(char *s1, char *s2, int n)
{
	int		len;
	char	*p;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc((len + 2) * sizeof(char));
	p[0] = 0;
	ft_strcat(p, s1);
	if (n == -1)
		ft_strcat(p, s2);
	else
		ft_strncat(p, s2, n + 1);
	free(s1);
	return (p);
}

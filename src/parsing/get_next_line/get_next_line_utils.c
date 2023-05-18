/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:00:25 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/18 16:15:34 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size * count);
	if (res == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

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

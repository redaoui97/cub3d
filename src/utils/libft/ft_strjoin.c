/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <rnabil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:57:17 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/18 16:38:36 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

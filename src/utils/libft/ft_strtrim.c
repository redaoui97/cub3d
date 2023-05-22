/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:04:50 by rnabil            #+#    #+#             */
/*   Updated: 2023/05/22 15:09:46 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	exists(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	size_t	i;
	size_t	first;
	size_t	last;

	if (!*s1)
		return (ft_strdup(""));
	first = 0;
	i = 0;
	while (s1[first] && exists(s1[first], set))
		first++;
	last = ft_strlen(s1) - 1;
	while (last > first && exists(s1[last], set))
		last--;
	a = (char *)malloc((last - first + 2) * sizeof(char));
	if (!a)
		return (NULL);
	while (first <= last)
		a[i++] = s1[first++];
	a[i] = 0;
	return (a);
}

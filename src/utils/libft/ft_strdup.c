/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 05:01:31 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/05 17:49:00 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!a)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

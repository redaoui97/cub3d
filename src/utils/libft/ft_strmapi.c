/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:16:38 by rnabil            #+#    #+#             */
/*   Updated: 2021/12/05 17:53:22 by rnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*a;

	if (!s || !f)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = 0;
	return (a);
}

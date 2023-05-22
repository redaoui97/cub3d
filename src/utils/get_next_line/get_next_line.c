/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:57:38 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/22 11:20:33 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_endl_index(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *s, size_t size)
{
	char	*p;
	int		i;
	size_t	len;

	len = ft_strlen(s);
	if (len < size)
		len = size;
	p = (char *)malloc((size + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_clean(char *buf, char *line)
{
	free(buf);
	if (line[0] != 0)
		return (line);
	free(line);
	return (NULL);
}

int	ft_core(char **buf, char **line, int *i, char **reminder)
{
	*i = return_endl_index(*buf);
	*line = strnjoin(*line, *buf, *i);
	if (*i != -1)
	{
		if (*(*buf + *i + 1) != 0)
			*reminder = ft_strndup(*buf + *i + 1, 1024);
		else
		{
			if (*reminder != *buf)
				free(*reminder);
			*reminder = 0;
		}
		free(*buf);
		return (1);
	}
	else
	{
		if (*buf != *reminder)
			free(*reminder);
		*reminder = 0;
		return (0);
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			i;
	static char	*reminder;
	char		*line;
	int			ret;

	buf = (char *)ft_calloc(1, (1024 + 1) * sizeof(char));
	line = (char *)ft_calloc(1, sizeof(char));
	while (1)
	{
		if (!reminder)
		{
			ret = read(fd, buf, 1024);
			if (ret <= 0)
				return (ft_clean(buf, line));
			buf[ret] = 0;
		}
		else
		{
			free(buf);
			buf = reminder;
		}
		if (ft_core(&buf, &line, &i, &reminder))
			return (line);
	}
}

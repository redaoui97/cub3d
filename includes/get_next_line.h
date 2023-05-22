/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazzouzi <mazzouzi@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:27:24 by mazzouzi          #+#    #+#             */
/*   Updated: 2023/05/22 15:27:27 by mazzouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_core(char **buf, char **line, int *i, char **reminder);
char	*ft_clean(char *buf, char *line);
char	*ft_strndup(char *s, size_t size);
int		return_endl_index(char *s);
char	*strnjoin(char *s1, char *s2, int n);
char	*ft_strcat(char *dest, char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
#endif

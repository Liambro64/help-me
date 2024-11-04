/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:35:42 by librooke          #+#    #+#             */
/*   Updated: 2024/11/04 17:15:27 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freenjoin(char *buff, char *tmp)
{
	char	*ret;

	ret = ft_strjoin(buff, tmp);
	free(buff);
	return (ret);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	how_many_nl(char *a)
{
	int		i;
	size_t	j;

	if (a == NULL)
		return (0);
	j = 0;
	i = 0;
	while (a[i] != 0)
		if (a[i++] == '\n')
			j++;
	return (j);
}

int	is_there_a_nl(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		if (a[i++] == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s[2][BUFF_SIZE];
	char		*a;
	char		*b;

	if (fd < 0)
		return (0);
	if (s[0][fd] == NULL)
	{
		s[0][fd] = get_buffer(fd);
		s[1][fd] = 0;
	}
	else if (how_many_nl(s[0][fd]) <= (size_t)s[1][fd])
	{
		a = s[0][fd];
		b = get_buffer(fd);
		s[0][fd] = ft_strjoin(s[0][fd], b);
		free(a);
		free(b);
	}
	if ((size_t)s[1][fd] > how_many_nl(s[0][fd]) || s[0][fd] == NULL)
		return (0);
	a = get_line_j((size_t)s[1][fd]++, s[0][fd]);
	if (a != 0 && *a == 0)
		a = 0;
	return (a);
}

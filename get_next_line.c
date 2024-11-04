/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:35:42 by librooke          #+#    #+#             */
/*   Updated: 2024/11/03 23:03:27 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	how_many_nl(char *a)
{
	int i;
	size_t	j;

	j = 0;
	i = 0;
	while (a[i] != 0){
		if (a[i++] == '\n')
			j++;
	}
	return (j);
}

int	is_there_a_nl(char *a)
{
	int i;

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
	if (fd <= -1)
		return (0);
	if (s[0][fd] == NULL)
	{
		s[0][fd] = get_buffer(fd);
		s[1][fd] = 0;
	}
	else if (how_many_nl(s[0][fd]) <= (size_t)s[1][fd])
	{
		a = s[0][fd];
		s[0][fd] = ft_strjoin(s[0][fd], get_buffer(fd));
		free(a);
	}
	a = get_line_j((size_t)s[1][fd]++, s[0][fd]);
	if (a != 0)
		if (*a == 0)
			a = 0;
	return (a);
}
/*
int main()
{
	int fd = open("test.txt", O_RDWR);
	char *a;
	while (a = get_next_line(fd))
	{printf("%s", a);}
	printf("\n");
}
*/
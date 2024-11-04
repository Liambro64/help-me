/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:35:42 by librooke          #+#    #+#             */
/*   Updated: 2024/11/04 19:48:30 by librooke         ###   ########.fr       */
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
	static char	*s[BUFF_SIZE];
	char		*a;

	if (fd < 0)
		return (0);
	if (s[fd] == NULL)
	{
		s[fd] = get_buffer(fd);
	}
	if (s[fd] == NULL || *s[fd] == 0)
		return (freenset(&s[fd]));
	a = get_line_j(&s[fd]);
	if (a != 0 && *a == 0)
		freenset(&a);
	return (a);
}
/*
int main()
{
	int fd = open("test.txt", O_RDWR);
	//int fd2 = open("test2.txt", O_RDWR);
	//int fd3 = open("test3.txt", O_RDWR);
	char *a;
	while (a = get_next_line(fd))
	{printf("%i, %s", a == "\n", a); free(a);}
}
*/
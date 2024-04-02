/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:35:42 by librooke          #+#    #+#             */
/*   Updated: 2024/04/02 14:49:17 by librooke         ###   ########.fr       */
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

int	is_there_a_nl(char *a)
{
	int i;

	i = 0;
	while (a[i])
		if (a[i] != '\n')
			return (1);
	return 0;
}

char	*get_next_line(int fd)
{
	static char	*s[2][BUFF_SIZE];
	int			*i;
	char		*a;

	if (s[0][fd] == NULL)
		s[0][fd] = get_buffer(fd);
	
}

#include <stdio.h>
int main()
{
	int fd = open("test.txt", O_RDWR);
	char *a;
	while ((a = get_next_line(fd)) != NULL)
	{
		printf("%s", a);
	}
}

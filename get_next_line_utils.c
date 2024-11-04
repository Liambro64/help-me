/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:19:08 by librooke          #+#    #+#             */
/*   Updated: 2024/11/04 16:23:35 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i++] = (unsigned char) '\0';
	}
	return (ptr);
}

char	*get_buffer(int fd)
{
	char	*buff;
	char	*tmp;
	int		i;
	int		last;

	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	i = read(fd, buff, BUFFER_SIZE);
	if (i == -1)
		return (0);
	while (!is_there_a_nl(buff))
	{
		last = i;
		i += read(fd, tmp, BUFFER_SIZE);
		if (tmp[0] == '\0' || i <= last)
			break ;
		buff = freenjoin(buff, tmp);
	}
	free(tmp);
	buff[i] = 0;
	return (buff);
}

char	*get_line_j(size_t j, char *buff)
{
	int		i;
	int		k;
	size_t	starting;

	starting = j;
	i = 0;
	k = 0;
	while ((long)j > -1l)
	{
		k = i;
		while (buff[i++] != '\n')
			if (buff[i] == '\0' && (j == 0 || j == starting))
				return (make_new_string(buff, k, i - k));
		j--;
	}
	return (make_new_string(buff, k, i - k));
}

char	*make_new_string(char *str, int st, int len)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc((len + 1) * sizeof(char));
	str += st;
	while (str[i] && i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	char	*ret;

	newstr = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!newstr)
		return (NULL);
	ret = newstr;
	while (*s1 != 0)
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	while (*s2 != 0)
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = '\0';
	return (ret);
}

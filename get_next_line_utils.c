/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:19:08 by librooke          #+#    #+#             */
/*   Updated: 2024/04/02 14:48:32 by librooke         ###   ########.fr       */
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

	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	i = read(fd, buff, BUFFER_SIZE);
	if (i == -1)
		return (0);
	if (!is_there_a_nl(buff))
		while (!is_there_a_nl(tmp))
		{
			i += read(fd, tmp, BUFFER_SIZE);
			buff = ft_strjoin(buff, tmp);
		}
	buff[i - 1] = 0;
	return (buff);
}

int	*use_buffer(int j, char *buff)
{
	int		i;
	int		k;
	int		*ret;

	ret = malloc(sizeof(int) * 2 + sizeof(char **));
	i = 0;
	while (j > -1)
	{
		k = i;
		while (buff[i] != '\0' && buff[i] != '\n')
			i++;
		j--;
	}
	ret[0] = k;
	ret[1] = i - k;
	((char **)ret)[1] = buff;
	return (ret);
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

	newstr = malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
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

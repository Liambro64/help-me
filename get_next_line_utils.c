/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:19:08 by librooke          #+#    #+#             */
/*   Updated: 2024/11/04 19:28:21 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freenset(char **a)
{
	free(*a);
	*a = 0;
	return (0);
}

char	*get_buffer(int fd)
{
	char	*buff;
	char	*tmp;
	int		i;
	int		last;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	i = read(fd, buff, BUFFER_SIZE);
	if (i <= 0)
	{
		free(buff);
		return (0);
	}
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
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

char	*get_line_j(char **buff)
{
	char	*a;
	char	*old;
	int		i;
	int		k;
	
	if (*buff == NULL || **buff == 0)
		return (0);
	i = 0;
	k = 0;
	while ((*buff)[i] != '\n')
		if ((*buff)[i++] == '\0')
			break;
	a = make_new_string(*buff, i + 1, 0);
	old = *buff;
	while ((*buff)[i + k++])
		;
	*buff = make_new_string(*buff, k, i + 1);
	free(old);
	return (a);
}

char	*make_new_string(char *str, int len, int st)
{
	char	*newstr;
	int		i;

	str += st;
	i = 0;
	newstr = malloc((len + 1) * sizeof(char));
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

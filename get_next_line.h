/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:19:48 by librooke          #+#    #+#             */
/*   Updated: 2024/04/02 14:48:40 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#define BUFF_SIZE 1024

void	*ft_calloc(size_t count, size_t size);
int		*get_buffer(int fd);
int		*use_buffer(int j, char *buff);
char	*make_new_string(char *str, int st, int len);

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(char *s);
int		is_there_a_nl(char *a);

#endif
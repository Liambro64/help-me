/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:19:48 by librooke          #+#    #+#             */
/*   Updated: 2024/11/04 19:00:35 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 1024

char	*freenset(char **a);
char	*get_buffer(int fd);
char	*get_line_j(char **buff);
char	*make_new_string(char *str, int len, int st);

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strlen(char *s);
int		is_there_a_nl(char *a);

char	*freenjoin(char *s1, char *s2);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:10:15 by jelarose          #+#    #+#             */
/*   Updated: 2019/12/06 19:10:18 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_stock
{
	int			fd;
	char		*str;
}				t_stock;

int				get_next_line(int fd, char **line);
int				ft_strlen_set(char *str, char set);
char			*ft_strdup(char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat_mal(char *s1, char *s2, unsigned size);

#endif

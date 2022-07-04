/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:28:18 by jelarose          #+#    #+#             */
/*   Updated: 2020/01/26 15:49:02 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_list(t_stock st[255], int fd, char **line)
{
	char	*tmp;
	char	*org;
	int		i;

	i = 0;
	tmp = st[fd].str;
	org = tmp;
	if (!(*line = malloc(sizeof(char*) * (ft_strlen_set(tmp, '\n') + 1))))
		return (-1);
	while (*tmp && *tmp != '\n')
		(*line)[i++] = *tmp++;
	(*line)[i] = '\0';
	if (*tmp == '\n')
	{
		st[fd].str = ft_strdup(++tmp);
		free(org);
		org = NULL;
		return (1);
	}
	free(st[fd].str);
	st[fd].str = NULL;
	return (0);
}

static int	read_fd(int fd, t_stock st[255], char **line)
{
	int		rd;
	char	*buff;

	rd = 0;
	if (!(buff = malloc(sizeof(*buff) * BUFFER_SIZE)))
		return (-1);
	while (!ft_strchr(st[fd].str, '\n') &&
	((rd = read(fd, buff, BUFFER_SIZE)) > 0))
		if (!(st[fd].str = ft_strcat_mal(st[fd].str, buff, rd)))
			return (-1);
	free(buff);
	buff = NULL;
	if (rd == -1)
		return (-1);
	if (!st[fd].str && rd == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (read_list(st, fd, line));
}

int			get_next_line(int fd, char **line)
{
	static	t_stock st[255];

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	return (read_fd(fd, st, line));
}

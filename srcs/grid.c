/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:04:46 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 16:46:09 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char		*str_sup_set(char *str, char set)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (ft_strlen(str)))))
		exit(-1);
	if (str)
		while (*str)
		{
			if (*str == set)
				str++;
			else
				ret[i++] = *str++;
		}
	ret[i] = '\0';
	return (ret);
}

int			is_one(char *s, char *set)
{
	int		i;

	if (s)
		while (*s)
		{
			if (set)
			{
				i = 0;
				while (set[i])
				{
					if (*s == set[i])
						break ;
					i++;
				}
				if (!set[i])
					return (0);
			}
			s++;
		}
	return (1);
}

char		*size_grid(t_window *win)
{
	int		len;
	int		i;
	char	*pars;

	pars = str_sup_set(win->line, ' ');
	len = ft_strlen(pars);
	i = 1;
	if (!is_one(pars, "1"))
		error(NULL, "probleme premiere ligne\n");
	while (get_next_line(win->fd, &win->line))
	{
		i++;
		win->line = str_sup_set(win->line, ' ');
		if (ft_strlen(win->line) != len || win->line[0] != '1' ||
		win->line[len - 1] != '1' || !is_one(win->line, "012NEOS"))
			error(NULL, "probleme taille ligne ou de caractere\n");
		pars = ft_strjoin(pars, win->line);
		free(win->line);
		win->line = NULL;
	}
	if (!is_one(pars + ((i - 1) * len), "1"))
		error(NULL, "probleme dernier ligne\n");
	win->map.h = i;
	win->map.w = len;
	return (pars);
}

void		init_grid(t_window *win)
{
	int		x;
	int		y;

	win->line = size_grid(win);
	if (!(win->map.grid = malloc(sizeof(int*) * win->map.h)))
		exit(-1);
	y = -1;
	while (++y < win->map.h)
	{
		if (!(win->map.grid[y] = malloc(sizeof(int) * win->map.w)))
			exit(-1);
		x = -1;
		while (++x < win->map.w)
		{
			if (*win->line == 'N' || *win->line == 'E' ||
			*win->line == 'S' || *win->line == 'O')
				if (win->perso.sens)
					error(NULL, "position perso en double");
				else
					init_perso(win, x, y, *win->line);
			else
				win->map.grid[y][x] = *win->line - '0';
			win->line++;
		}
	}
}

void		init_map(t_window *win)
{
	win->map.wall = init_img(win);
	if (!(init_tex(win, &win->map.texno)))
		error(NULL, "probleme chargement de texno");
	if (!(init_tex(win, &win->map.texso)))
		error(NULL, "probleme chargement de texso");
	if (!(init_tex(win, &win->map.texwe)))
		error(NULL, "probleme chargement de texwe");
	if (!(init_tex(win, &win->map.texea)))
		error(NULL, "probleme chargement de texea");
	if (!(win->map.tab = malloc(sizeof(double) * (win->w + 1))))
		exit(-1);
	win->list = NULL;
}

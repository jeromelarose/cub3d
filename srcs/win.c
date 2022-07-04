/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:00:09 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 16:33:04 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		xclose(t_window *win)
{
	mlx_destroy_window(win->mlx, win->win);
	ft_lstclear(win->list);
	free(win->perso.texsprite);
	free(win->map.texno.tex);
	free(win->map.texso.tex);
	free(win->map.texwe.tex);
	free(win->map.texea.tex);
	exit(0);
	return (0);
}

void	init_win(t_window *win)
{
	win->agl = 60;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->w, win->h, "Cube3D");
	win->camera.ratio = win->agl / win->w;
}

void	error(t_window *win, char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	if (win)
	{
		mlx_destroy_window(win->mlx, win->win);
		ft_lstclear(win->list);
	}
	exit(-1);
}

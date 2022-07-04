/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:12:42 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/21 19:37:52 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		move(t_window *win)
{
	double	tmpx;
	double	tmpy;

	win->perso.angle += win->perso.rotate_speed * win->perso.r;
	if (win->perso.angle >= 360)
		win->perso.angle -= 360;
	if (win->perso.angle < 0)
		win->perso.angle += 360;
	tmpx = (cos(((win->perso.angle) * M_PI) / 180))
	* win->perso.speed * win->perso.vx;
	tmpy = (sin(((win->perso.angle) * M_PI) / 180))
	* win->perso.speed * win->perso.vx;
	tmpx += (cos(((win->perso.angle + 90) * M_PI) / 180))
	* (win->perso.speed / 2) * win->perso.vy;
	tmpy += (sin(((win->perso.angle + 90) * M_PI) / 180))
	* (win->perso.speed / 2) * win->perso.vy;
	if (win->perso.x + tmpx > 1.2 && win->perso.x + tmpx + 1.2 < win->map.w)
		win->perso.x += tmpx;
	if (win->perso.y + tmpy > 1.2 && win->perso.y + tmpy + 1.2 < win->map.h)
		win->perso.y += tmpy;
	return (0);
}

int		move_perso(int key, t_window *win)
{
	if (key == 53)
		xclose(win);
	if (key == 124)
	{
		if (win->perso.vx == -1)
			win->perso.r = -1;
		else
			win->perso.r = 1;
	}
	if (key == 123)
	{
		if (win->perso.vx == -1)
			win->perso.r = 1;
		else
			win->perso.r = -1;
	}
	if (key == 1)
		win->perso.vx = -1;
	if (key == 13)
		win->perso.vx = 1;
	if (key == 0)
		win->perso.vy = -1;
	if (key == 2)
		win->perso.vy = 1;
	return (0);
}

int		stop_perso(int key, t_window *win)
{
	if (key == 124 || key == 123)
		win->perso.r = 0;
	if (key == 1 || key == 13)
		win->perso.vx = 0;
	if (key == 0 || key == 2)
		win->perso.vy = 0;
	return (0);
}

void	init_perso(t_window *win, int x, int y, char sens)
{
	win->perso.sens = sens;
	if (sens == 'N')
		win->perso.angle = 270;
	else if (sens == 'S')
		win->perso.angle = 90;
	else if (sens == 'O')
		win->perso.angle = 180;
	else
		win->perso.angle = 0;
	win->perso.r = 0;
	win->perso.vx = 0;
	win->perso.vy = 0;
	win->perso.speed = 0.18;
	win->perso.rotate_speed = 3;
	win->perso.x = (double)x + 0.5;
	win->perso.y = (double)y + 0.5;
	win->map.grid[y][x] = 0;
}

int		print_perso(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->perso.tile.img,
	win->perso.x * 5, win->perso.y * 5);
	return (0);
}

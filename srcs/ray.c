/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:48:20 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 11:16:08 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_sidedist(t_window *win)
{
	if (win->camera.dirx < 0)
	{
		win->camera.stepx = -1;
		win->camera.sidedistx = (win->perso.x - win->map.px)
		* win->camera.deltadistx;
	}
	else
	{
		win->camera.stepx = 1;
		win->camera.sidedistx = (win->map.px + 1 - win->perso.x)
		* win->camera.deltadistx;
	}
	if (win->camera.diry < 0)
	{
		win->camera.stepy = -1;
		win->camera.sidedisty = (win->perso.y - win->map.py)
		* win->camera.deltadisty;
	}
	else
	{
		win->camera.stepy = 1;
		win->camera.sidedisty = (win->map.py + 1 - win->perso.y)
		* win->camera.deltadisty;
	}
}

void	init_direction_ray(t_window *win, int pix)
{
	win->map.px = (int)win->perso.x;
	win->map.py = (int)win->perso.y;
	win->camera.dirx = cos(((win->perso.angle - (win->agl / 2)
	+ (pix * win->camera.ratio)) * M_PI) / 180);
	win->camera.diry = sin(((win->perso.angle - (win->agl / 2)
	+ (pix * win->camera.ratio)) * M_PI) / 180);
	win->camera.deltadistx = sqrt(1 + ((win->camera.diry * win->camera.diry)
	/ (win->camera.dirx * win->camera.dirx)));
	win->camera.deltadisty = sqrt(1 + ((win->camera.dirx * win->camera.dirx)
	/ (win->camera.diry * win->camera.diry)));
	init_sidedist(win);
	lance_ray(win, pix);
}

double	ret_dist(t_window *win, char c)
{
	if (c == 'x')
		return (floor(win->map.px) - win->perso.x + 0.5);
	return (floor(win->map.py) - win->perso.y + 0.5);
}

void	lance_ray(t_window *win, int pix)
{
	pix = 0;
	while (1)
	{
		if (win->camera.sidedistx < win->camera.sidedisty)
		{
			win->camera.sidedistx += win->camera.deltadistx;
			win->map.px += win->camera.stepx;
			win->camera.side = 0;
		}
		else
		{
			win->camera.sidedisty += win->camera.deltadisty;
			win->map.py += win->camera.stepy;
			win->camera.side = 1;
		}
		if (win->map.grid[(int)win->map.py][(int)win->map.px] == 1)
			break ;
		else if (win->map.grid[(int)win->map.py][(int)win->map.px] == 2 &&
		!ft_islst(win->list, win->map.px, win->map.py))
			gest_sprite(win);
	}
}

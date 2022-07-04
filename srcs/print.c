/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:45:57 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 11:36:43 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_fond(t_window *win)
{
	int y;
	int x;

	y = win->h / 2;
	while (++y < win->h)
	{
		x = -1;
		while (++x < win->w)
			my_mlx_pixel_put(&win->map.wall, x, y, win->map.ground.color);
	}
	y = -1;
	while (++y < win->h / 2)
	{
		x = -1;
		while (++x < win->w)
			my_mlx_pixel_put(&win->map.wall, x, y, win->map.sky.color);
	}
}

void	draw_square(t_img *img, int color)
{
	int x;
	int y;

	y = -1;
	while (++y < img->h)
	{
		x = -1;
		while (++x < img->w)
			my_mlx_pixel_put(img, x, y, color);
	}
}

void	print_sidex(t_window *win, int pix, double px)
{
	double	x;
	int		tx;

	x = win->perso.y + px * win->camera.diry;
	px *= cos(((-(win->agl / 2) + (pix * win->camera.ratio)) * M_PI) / 180);
	x = x - (int)x;
	if (win->camera.dirx > 0)
	{
		tx = (int)(x * win->map.texea.w);
		tx = win->map.test->w - tx - 1;
		win->map.test = &win->map.texea;
	}
	else
	{
		win->map.test = &win->map.texwe;
		tx = (int)(x * win->map.texwe.w);
	}
	win->map.tab[pix] = sqrtf(powf((floor(win->map.px) - win->perso.x + 0.5), 2)
	+ (powf((floor(win->map.py) - win->perso.y + 0.5), 2)));
	print_band(win, pix, px, tx);
}

void	print_sidey(t_window *win, int pix, double px)
{
	double	x;
	int		tx;

	x = win->perso.x + px * win->camera.dirx;
	px *= cos(((-(win->agl / 2) + (pix * win->camera.ratio)) * M_PI) / 180);
	x = x - (int)x;
	if (win->camera.diry > 0)
	{
		tx = (int)(x * win->map.texso.w);
		win->map.test = &win->map.texso;
	}
	else
	{
		tx = (int)(x * win->map.texno.w);
		win->map.test = &win->map.texno;
		tx = win->map.test->w - tx - 1;
	}
	win->map.tab[pix] = sqrtf(powf((floor(win->map.px) - win->perso.x + 0.5), 2)
	+ (powf((floor(win->map.py) - win->perso.y + 0.5), 2)));
	print_band(win, pix, px, tx);
}

void	print_band(t_window *win, int x, double dist, int tx)
{
	double	start;
	double	end;
	double	step;
	double	ty;

	start = (win->h / 2) - ((win->w / 2.15) / dist);
	end = (win->h / 2) + ((win->w / 2.15) / dist);
	step = win->map.test->h / (end - start);
	ty = 0.0;
	while (start < end)
	{
		if (start >= 0 && start < win->h)
			my_mlx_pixel_put(&win->map.wall, x, start,
			get_pixel(win->map.test, tx, (int)ty));
		ty += step;
		start++;
	}
}

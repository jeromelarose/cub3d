/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:21:36 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 16:12:48 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			get_pixel(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int			init_tex(t_window *win, t_img *img)
{
	if (!(img->img = mlx_xpm_file_to_image(win->mlx, img->tex,
	&img->w, &img->h)))
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	&img->line_length, &img->endian);
	return (1);
}

t_img		init_img(t_window *win)
{
	t_img	img;

	img.w = win->w;
	img.h = win->h;
	img.img = mlx_new_image(win->mlx, img.w, img.h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	draw_square(&img, 0x00000000);
	return (img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:03:57 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 17:52:31 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		write_info_header(t_window *win, int fd)
{
	int		header_size;
	short	nb_plane;
	int		img_size;

	header_size = 40;
	nb_plane = 1;
	img_size = win->map.wall.w * win->map.wall.h *
	(win->map.wall.bits_per_pixel / 8);
	write(fd, &header_size, 4);
	write(fd, &win->map.wall.w, 4);
	write(fd, &win->map.wall.h, 4);
	write(fd, &nb_plane, 2);
	write(fd, &win->map.wall.bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, "\0\0\0\0", 4);
}

void		write_header(t_window *win, int fd)
{
	int		fsize;
	int		data_start;

	fsize = 13 + 40 + ((win->map.wall.w * win->map.wall.h) *
	win->map.wall.bits_per_pixel / 8);
	data_start = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &fsize, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	write(fd, &data_start, 4);
	write_info_header(win, fd);
}

void		fill_img(t_window *win, int fd)
{
	int		y;
	char	*dst;

	y = win->map.wall.h;
	while (--y >= 0)
	{
		dst = win->map.wall.addr + (y * win->map.wall.line_length);
		write(fd, dst, win->map.wall.line_length);
	}
}

void		ft_save(t_window *win)
{
	int		fd;

	if ((fd = open("./screen.bmp", O_WRONLY | O_CREAT |
	O_APPEND | O_TRUNC, 0666)) == -1)
		error(NULL, "problem open file\n");
	write_header(win, fd);
	fill_img(win, fd);
	close(fd);
	xclose(win);
}

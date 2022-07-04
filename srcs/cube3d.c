/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:44:54 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/21 19:56:33 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		print_all(t_window *win)
{
	int	pix;

	pix = -1;
	mlx_clear_window(win->mlx, win->win);
	move(win);
	draw_fond(win);
	while (++pix < win->w)
	{
		init_direction_ray(win, pix);
		if (win->camera.side == 0)
			print_sidex(win, pix, ((win->map.px - win->perso.x
			+ (1 - win->camera.stepx) / 2) / win->camera.dirx));
		else
			print_sidey(win, pix, ((win->map.py - win->perso.y +
			(1 - win->camera.stepy) / 2) / win->camera.diry));
	}
	gest_list(win);
	if (win->save == 1)
		ft_save(win);
	mlx_put_image_to_window(win->mlx, win->win, win->map.wall.img, 0, 0);
	return (0);
}

int		is_cub(char *str)
{
	if (str)
	{
		while (*str && *str != '.')
			str++;
		if (*str)
			if (ft_strcmp(&(*str), ".cub") == 0)
				return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_window	win;

	win.save = 0;
	if (ac == 3 || ac == 2)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
			win.save = 1;
		else if (ac == 3)
			error(NULL, "probleme nom d'argument\n");
		if (!is_cub(av[1]) || (win.fd = open(av[1], O_RDONLY)) == -1)
			error(NULL, "probleme ouverture de la map\n");
		parsing(&win);
		verif(&win);
		close(win.fd);
		init_win(&win);
		init_map(&win);
		mlx_hook(win.win, 2, 0, move_perso, &win);
		mlx_hook(win.win, 17, 0, xclose, &win);
		mlx_hook(win.win, 3, 0, stop_perso, &win);
		mlx_loop_hook(win.mlx, print_all, &win);
		mlx_loop(win.mlx);
	}
	else
		error(NULL, "probleme nombre argument\n");
	return (0);
}

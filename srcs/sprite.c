/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:40:57 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 11:20:57 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	create_sprite(t_window *win, double ytmp)
{
	t_list	*new;

	new = ft_lstnew();
	new->sprite.mapx = win->map.px;
	new->sprite.mapy = win->map.py;
	new->sprite.pnj.tex = win->perso.texsprite;
	if (!(init_tex(win, &new->sprite.pnj)))
		error(NULL, "probleme chargement de texture sprite");
	new->sprite.dist = sqrtf(powf(ret_dist(win, 'x'), 2)
	+ (powf(ret_dist(win, 'y'), 2)));
	new->sprite.start = (win->h / 2) - ((win->w / 2.15) / new->sprite.dist);
	new->sprite.end = (win->h / 2) + ((win->w / 2.15) / new->sprite.dist);
	new->sprite.size = (new->sprite.end - new->sprite.start);
	new->sprite.stepx = new->sprite.pnj.w / new->sprite.size;
	new->sprite.xtmp = ytmp * win->w / win->agl - (new->sprite.size / 2);
	new->sprite.stepy = new->sprite.pnj.h / new->sprite.size;
	ft_lstadd_back(&win->list, new);
}

void	gest_sprite(t_window *win)
{
	double ytmp;
	double thetatemp;

	thetatemp = atan2(ret_dist(win, 'y'), ret_dist(win, 'x'));
	thetatemp *= (180 / 3.14);
	if (thetatemp < 0)
		thetatemp += 360;
	ytmp = thetatemp - (win->perso.angle - (win->agl / 2));
	if (thetatemp > 270 && win->perso.angle < 90)
		ytmp = ((win->agl / 2) - win->perso.angle) + thetatemp - 360;
	if (win->perso.angle > 270 && thetatemp < 90)
		ytmp = ((win->agl / 2) - win->perso.angle) + thetatemp + 360;
	create_sprite(win, ytmp);
}

void	print_sprite(t_window *win, t_sprite sprite)
{
	double	tx;
	double	ty;
	int		x;
	int		y;

	tx = 0.0;
	x = sprite.xtmp;
	sprite.size += x;
	while (x < sprite.size)
	{
		ty = 0.0;
		y = sprite.start;
		while (y < sprite.end - 1)
		{
			if (sprite.dist < win->map.tab[x] && y >= 0 &&
			y < win->h && x >= 0 && x < win->w && get_pixel(&sprite.pnj,
			(int)tx, (int)ty) != (int)0xFF000000)
				my_mlx_pixel_put(&win->map.wall, x, y, get_pixel(&sprite.pnj,
				(int)tx, (int)ty));
			ty += sprite.stepy;
			y++;
		}
		x++;
		tx += sprite.stepx;
	}
}

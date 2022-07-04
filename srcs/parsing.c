/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:38:12 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 17:54:24 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_color(char **pars, t_img *img)
{
	pars = ft_split(pars[1], ',');
	if (is_num(pars[0]) && is_num(pars[1]) && is_num(pars[2]) && !pars[3])
	{
		img->color = create_trgb(0, ft_atoi(pars[0]),
		ft_atoi(pars[1]), ft_atoi(pars[2]));
		free_tab(pars);
	}
	else
		error(NULL, "probleme couleur sol ou plafond");
}

void	pars_tex(t_window *win, char **pars)
{
	if (ft_strcmp(pars[0], "NO") == 0 && pars[1] && !pars[2])
		if (win->map.texno.tex != NULL)
			error(NULL, "tex no en doube\n");
		else
			win->map.texno.tex = pars[1];
	else if (ft_strcmp(pars[0], "SO") == 0 && pars[1] && !pars[2])
		if (win->map.texso.tex != NULL)
			error(NULL, "tex so en double\n");
		else
			win->map.texso.tex = pars[1];
	else if (ft_strcmp(pars[0], "WE") == 0 && pars[1] && !pars[2])
		if (win->map.texwe.tex != NULL)
			error(NULL, "tex we en double\n");
		else
			win->map.texwe.tex = pars[1];
	else if (ft_strcmp(pars[0], "EA") == 0 && pars[1] && !pars[2])
	{
		if (win->map.texea.tex != NULL)
			error(NULL, "tex ea en double\n");
		else
			win->map.texea.tex = pars[1];
	}
}

void	verif(t_window *win)
{
	if (win->w < 1 || win->h < 1)
		error(NULL, "taile window null\n");
	if (win->w > 2560)
		win->w = 2560;
	if (win->h > 1400)
		win->h = 1400;
	if (!win->perso.texsprite)
		error(NULL, "tex sprite absent\n");
	if (!win->map.texno.tex)
		error(NULL, "tex no absent\n");
	if (!win->map.texso.tex)
		error(NULL, "tex so absent\n");
	if (!win->map.texwe.tex)
		error(NULL, "tex we absent\n");
	if (!win->map.texea.tex)
		error(NULL, "tex ea absent\n");
	if (win->map.ground.color == 0)
		error(NULL, "tex ground absent\n");
	if (win->map.sky.color == 0)
		error(NULL, "tex sky absent\n");
	if (!win->perso.sens)
		error(NULL, "posistion du joueur absente\n");
	if (!win->map.grid)
		error(NULL, "map absente\n");
}

void	pars_win(t_window *win, char **pars)
{
	if (!ft_strcmp(pars[0], "R") && is_num(pars[1]) &&
	is_num(pars[2]) && !pars[3])
	{
		if (win->w != 0 || win->h != 0)
			error(NULL, "taille fenetre en double\n");
		win->w = ft_atoi(pars[1]);
		win->h = ft_atoi(pars[2]);
	}
	else if (!ft_strcmp(pars[0], "F") && pars[1] && !pars[2])
		if (win->map.ground.color != 0)
			error(NULL, "tex ground en double\n");
		else
			init_color(pars, &win->map.ground);
	else if (!ft_strcmp(pars[0], "C") && pars[1] && !pars[2])
	{
		if (win->map.sky.color != 0)
			error(NULL, "tex sky en double\n");
		else
			init_color(pars, &win->map.sky);
	}
}

void	parsing(t_window *win)
{
	char	**pars;

	win->map.grid = NULL;
	while (get_next_line(win->fd, &win->line) > 0)
	{
		pars = ft_split(win->line, ' ');
		if (pars && pars[0])
		{
			pars_win(win, pars);
			pars_tex(win, pars);
			pars_perso(win, pars);
			if (ft_strcmp(pars[0], "1") == 0)
			{
				if (win->map.grid != NULL)
					error(NULL, "map en double\n");
				init_grid(win);
			}
			free_tab(pars);
		}
	}
}

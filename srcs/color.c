/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 11:35:22 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 16:59:55 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	if (t < 0 || t > 255 || r < 0 || r > 255 || g < 0 ||
	g > 255 || b < 0 || b > 255)
		error(NULL, "erreur taille de couleur");
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_tab(char **pars)
{
	char *org;

	if (ft_strcmp(pars[0], "R") == 0 || ft_strcmp(pars[0], "F") == 0
	|| ft_strcmp(pars[0], "C") == 0)
	{
		while (*pars)
		{
			org = *pars;
			pars++;
			free(org);
			org = NULL;
		}
	}
	else
		free(pars[0]);
}

void	pars_perso(t_window *win, char **pars)
{
	if (ft_strcmp(pars[0], "S") == 0 && pars[1] && !pars[2])
	{
		if (win->perso.texsprite != NULL)
			error(NULL, "tex sprite en double\n");
		else
			win->perso.texsprite = pars[1];
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:37:10 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/20 14:37:44 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	swap_node(t_list *lst, t_list *tmp)
{
	t_sprite cp;

	if (lst && tmp)
	{
		cp = lst->sprite;
		lst->sprite = tmp->sprite;
		tmp->sprite = cp;
	}
}

void	ft_lst_sort(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	if (lst && lst->next)
	{
		while (lst)
		{
			tmp = lst->next;
			max = lst;
			while (tmp)
			{
				if (tmp->sprite.dist > max->sprite.dist)
					max = tmp;
				tmp = tmp->next;
			}
			if (max->sprite.dist > lst->sprite.dist)
				swap_node(lst, max);
			lst = lst->next;
		}
	}
}

void	gest_list(t_window *win)
{
	t_list	*lst;

	lst = win->list;
	if (lst)
	{
		ft_lst_sort(lst);
		while (lst)
		{
			print_sprite(win, lst->sprite);
			lst = lst->next;
		}
		ft_lstclear(win->list);
		win->list = NULL;
	}
}

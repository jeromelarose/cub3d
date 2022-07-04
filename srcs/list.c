/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:28:26 by jelarose          #+#    #+#             */
/*   Updated: 2020/02/24 16:07:45 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_list	*ft_lstnew(void)
{
	t_list	*new;

	if (!(new = malloc(sizeof(*new) * 1)))
		return (NULL);
	new->next = NULL;
	new->back = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && *lst)
	{
		new->back = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
	else if (lst)
		*lst = new;
}

void	ft_lstclear(t_list *lst)
{
	if (lst)
	{
		ft_lstclear(lst->next);
		free(lst);
		lst = NULL;
	}
}

int		ft_islst(t_list *lst, int x, int y)
{
	if (lst)
		while (lst)
		{
			if (x == lst->sprite.mapx && y == lst->sprite.mapy)
				return (1);
			lst = lst->next;
		}
	return (0);
}

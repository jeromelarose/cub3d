/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:37:32 by jelarose          #+#    #+#             */
/*   Updated: 2020/01/26 15:59:37 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static unsigned int		ft_strlen_charset(const char *str, char charset)
{
	unsigned int i;

	i = 0;
	while (*str == charset && *str)
		str++;
	while (*str != charset && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static unsigned int		count_word(const char *str, char charset)
{
	unsigned int i;

	i = 0;
	while (*str)
	{
		while (*str == charset && *str)
			str++;
		if (*str)
		{
			i++;
			while (*str != charset && *str)
				str++;
		}
	}
	return (i);
}

static char				*ret_word(const char *str, char charset)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (!(ret = malloc(sizeof(*ret) * (ft_strlen_charset(str, charset) + 1))))
		return (NULL);
	while (*str == charset && *str)
		str++;
	while (*str != charset && *str)
	{
		ret[i] = *str;
		str++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char				**ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char					**ft_split(const char *str, char charset)
{
	char	**tab;
	int		i;

	if (!str)
		return (NULL);
	if (!(tab = malloc(sizeof(*tab) * (count_word(str, charset) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == charset && *str)
			str++;
		if (*str)
		{
			if (!(tab[i] = ret_word(str, charset)))
				return (ft_free_tab(tab));
			i++;
			while (*str != charset && *str)
				str++;
		}
	}
	tab[i] = 0;
	return (tab);
}

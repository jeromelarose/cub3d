/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:02:57 by jelarose          #+#    #+#             */
/*   Updated: 2020/01/26 16:05:09 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ret_nbc(long *nbr, int *neg)
{
	int		nbc;
	long	nb;

	nbc = 0;
	if (*nbr < 0)
	{
		*nbr = *nbr * -1;
		*neg = 1;
		nbc++;
	}
	nb = *nbr;
	if (nb == 0)
		nbc++;
	while (nb)
	{
		nbc++;
		nb /= 10;
	}
	return (nbc);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		nbc;
	long	nbr;

	nbr = n;
	neg = 0;
	nbc = ret_nbc(&nbr, &neg);
	if (!(ret = malloc(sizeof(*ret) * (nbc + 1))))
		return (NULL);
	ret[nbc] = '\0';
	if (neg)
		ret[0] = '-';
	nbc--;
	if (nbr == 0)
		ret[0] = '0';
	while (nbr > 0)
	{
		ret[nbc--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ret);
}

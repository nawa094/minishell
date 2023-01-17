/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:13:40 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/30 12:29:34 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		len(long i)
{
	int n;

	n = 1;
	if (i < 0)
		n++;
	while (i /= 10)
	{
		n++;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	long i;
	char *ret;
	long j;
	long x;

	if (!(ret = ft_strnew((size_t)len(n))))
		return (NULL);
	i = len(n) - 1;
	j = 0;
	x = (long)n;
	if (x < 0)
	{
		x = -x;
		j = 1;
	}
	while (i >= 0)
	{
		ret[i] = x % 10 + '0';
		x /= 10;
		i--;
	}
	if (j == 1)
		ret[0] = '-';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:22:51 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/05 13:44:52 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_long_l(int j, t_flag *flag, char b, long long c)
{
	while (j-- > 0)
		ft_putnchar(b, flag);
	if (flag->plus == 1 && c > 0)
		ft_putnchar('+', flag);
	ft_putlong_l(c, flag);
	return (flag->ret);
}

int		long_long(t_flag *flag, va_list lst)
{
	long long	c;
	int			i;
	int			j;
	char		b;

	b = (flag->period == 1) ? ' ' : '0';
	c = va_arg(lst, long long);
	i = 1;
	j = c;
	while ((j /= 10) > 0)
		i++;
	j = flag->max_width - i;
	if (flag->minus == 1)
	{
		if (c > 0 && flag->plus == 1)
			ft_putnchar('+', flag);
		ft_putlong_l(c, flag);
		while (j-- > 0)
			ft_putnchar(b, flag);
		return (flag->ret);
	}
	return (right_just_long_l(j, flag, b, c));
}

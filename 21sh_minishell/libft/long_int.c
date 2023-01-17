/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:55:44 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/05 13:45:12 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_long(int j, long c, t_flag *flag, char a)
{
	while (j-- > 0)
		ft_putnchar(a, flag);
	if (flag->plus == 1 && c > 0)
		ft_putnchar('+', flag);
	ft_putlong(c, flag);
	return (flag->ret);
}

int		long_int(t_flag *flag, va_list lst)
{
	long	c;
	int		i;
	int		j;
	char	a;

	c = va_arg(lst, intmax_t);
	a = flag->period ? ' ' : '0';
	i = 1;
	j = c;
	while ((j /= 10) > 0)
		i++;
	j = flag->max_width - i;
	if (flag->minus == 1)
	{
		if (c > 0 && flag->plus == 1)
			ft_putnchar('+', flag);
		ft_putlong(c, flag);
		while (j-- > 0)
			ft_putnchar(a, flag);
		return (flag->ret);
	}
	else
		return (right_just_long(j, c, flag, a));
}

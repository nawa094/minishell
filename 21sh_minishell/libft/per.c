/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:20:10 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/06 14:43:44 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_per(char temp, int i, t_flag *flag)
{
	char a;

	a = flag->zero ? '0' : ' ';
	while (i-- > 0)
		ft_putnchar(a, flag);
	ft_putnchar(temp, flag);
	return (1);
}

int		per(t_flag *flag)
{
	char		temp;
	int			i;

	temp = '%';
	i = flag->max_width > 0 ? flag->width - flag->max_width :
		flag->width - 1;
	if (flag->minus == 1)
	{
		if (flag->max_width > 0)
			while (flag->max_width--)
				ft_putnchar(temp, flag);
		else
			ft_putnchar(temp, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	right_just_per(temp, i, flag);
	return (1);
}

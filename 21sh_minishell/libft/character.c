/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:02:47 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 09:33:10 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_char(char temp, int i, t_flag *flag)
{
	while (i-- > 0)
		ft_putnchar(' ', flag);
	ft_putnchar(temp, flag);
	return (flag->ret);
}

int		character(t_flag *flag, va_list lst)
{
	char		temp;
	int			i;

	temp = (char)va_arg(lst, int);
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
		return (flag->ret);
	}
	right_just_char(temp, i, flag);
	return (flag->ret);
}

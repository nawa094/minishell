/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 10:49:45 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 11:30:49 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_wchar(char temp, int i, t_flag *flag)
{
	while (i-- > 0)
		ft_putnchar(' ', flag);
	ft_wcharput(temp, flag);
	return (flag->ret);
}

int		ft_wputchar(t_flag *flag, va_list lst)
{
	wchar_t		temp;
	int			i;

	temp = (wchar_t)va_arg(lst, wint_t);
	i = flag->max_width > 0 ? flag->width - flag->max_width :
		flag->width - 1;
	if (flag->minus == 1)
	{
		if (flag->max_width > 0)
			while (flag->max_width--)
				ft_wcharput(temp, flag);
		else
			ft_wcharput(temp, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (flag->ret);
	}
	right_just_wchar(temp, i, flag);
	return (flag->ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:43:08 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 11:33:10 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_str(t_flag *flag, wchar_t *temp, int i)
{
	while (i-- > 0)
		ft_putnchar(' ', flag);
	if (flag->max_width > 0)
		while (flag->max_width-- && (*temp))
			ft_wcharput(*temp++, flag);
	else
		while (*temp)
			ft_wcharput(*(temp)++, flag);
	return (flag->ret);
}

int		ft_wputstr(t_flag *flag, va_list lst)
{
	wchar_t		*temp;
	int			i;

	temp = va_arg(lst, wchar_t *);
	i = flag->width - ft_wstrlen(temp);
	if (flag->minus == 1)
	{
		if (flag->max_width > 0)
			while (flag->max_width--)
				ft_wcharput(*temp++, flag);
		else
			while (*(temp))
				ft_wcharput(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (flag->ret);
	}
	else
		return (right_just_str(flag, temp, i));
}

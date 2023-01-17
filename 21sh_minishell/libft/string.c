/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 11:26:52 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 13:32:28 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_sstr(t_flag *flag, char *temp, int i, char a)
{
	if (ft_strlen(temp) == 0)
		i = flag->width;
	while (i-- > 0)
		ft_putnchar(a, flag);
	if (flag->max_width > 0)
		while (flag->max_width-- && (*temp))
			ft_putnchar(*(temp)++, flag);
	else
		while (*temp)
			ft_putnchar(*(temp)++, flag);
	return (flag->ret);
}

int		null_string(t_flag *flag)
{
	char *null;

	null = "(null)";
	while (*null)
		ft_putnchar(*null++, flag);
	return (1);
}

int		string(t_flag *flag, va_list lst)
{
	char		*temp;
	int			i;
	char		a;

	temp = va_arg(lst, char *);
	if (temp == NULL)
		return (null_string(flag));
	i = flag->max_width > 0 ? flag->width - flag->max_width :
		flag->width - ft_strlen(temp);
	a = flag->zero == 1 ? '0' : ' ';
	if (ft_strlen(temp) == 0)
		i = flag->width;
	if (flag->minus == 1)
	{
		if (flag->max_width > 0)
			while (flag->max_width-- && ft_strlen(temp) > 0)
				ft_putnchar(*(temp)++, flag);
		else
			while (*(temp))
				ft_putnchar(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(a, flag);
		return (flag->ret);
	}
	return (right_just_sstr(flag, temp, i, a));
}

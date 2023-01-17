/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:00:45 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/17 16:25:24 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_inte(char *temp, int i, t_flag *flag)
{
	char	a;
	int		b;

	a = flag->zero == 1 ? '0' : ' ';
	b = flag->width - flag->max_width - ft_strlen(temp);
	if (flag->space == 1 && b < 1)
	{
		i--;
		ft_putnchar(' ', flag);
	}
	while (b-- > 0)
		ft_putnchar(' ', flag);
	if (flag->plus == 1 && *temp != '-' && flag->zero == 1)
		ft_putnchar('+', flag);
	while (i-- > 0)
		ft_putnchar(a, flag);
	if (flag->plus == 1 && *temp != '-' && flag->zero == 0)
		ft_putnchar('+', flag);
	while (*temp)
		ft_putnchar(*(temp)++, flag);
	return (1);
}

int		inte_p(char *temp, t_flag *flag, int i)
{
	int b;

	b = flag->width - flag->max_width - ft_strlen(temp);
	if (flag->minus == 1)
	{
		if (flag->plus == 1 && *temp != '-')
		{
			ft_putnchar('+', flag);
			i--;
		}
		while (i-- > 0)
			ft_putnchar('0', flag);
		while (*(temp))
			ft_putnchar(*temp++, flag);
		while (b-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	right_just_inte(temp, i, flag);
	return (1);
}

int		interger(t_flag *flag, va_list lst, t_length *length)
{
	char			*temp;
	int				i;
	int				j;
	int				len;

	j = 0;
	i = get_num(flag, length, lst);
	temp = ft_itoa_base(i, 10);
	len = flag->max_width - ft_strlen(temp);
	if (flag->period == 1 && flag->space == 1)
	{
		flag->zero = 1;
		len = flag->width;
	}
	inte_p(temp, flag, len);
	free(temp);
	return (1);
}

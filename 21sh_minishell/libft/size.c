/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 14:04:03 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 14:19:21 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_size(char *temp, int i, t_flag *flag)
{
	char a;

	if (flag->period == 1)
		flag->zero = 0;
	a = flag->zero == 1 ? '0' : ' ';
	while (i-- > 0)
		ft_putnchar(a, flag);
	if (flag->plus == 1)
		ft_putnchar('+', flag);
	while (*temp)
		ft_putnchar(*(temp)++, flag);
	return (1);
}

int		size_p(char *temp, t_flag *flag)
{
	int	i;

	i = flag->width - ft_strlen(temp);
	if (flag->plus == 1)
		i--;
	if (flag->minus == 1)
	{
		if (flag->plus == 1)
		{
			i--;
			ft_putnchar('+', flag);
		}
		while (*(temp))
			ft_putnchar(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	right_just_size(temp, i, flag);
	return (1);
}

int		size(t_flag *flag, va_list lst, t_length *length)
{
	char			*temp;
	intmax_t		i;
	int				j;
	intmax_t		k;

	j = 0;
	i = get_num(flag, length, lst);
	k = i;
	temp = ft_itoa_base(i, 10);
	size_p(temp, flag);
	free(temp);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:58:29 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 09:28:47 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_short(char *temp, int i, t_flag *flag)
{
	char a;

	if (flag->period == 1)
		flag->zero = 0;
	a = flag->zero == 1 ? '0' : ' ';
	while (i-- > 0)
		ft_putnchar(a, flag);
	if (flag->hash == 1)
		ft_putnchar('0', flag);
	while (*temp)
		ft_putnchar(*(temp)++, flag);
	return (1);
}

int		short_p(char *temp, t_flag *flag)
{
	int	i;

	i = flag->hash ? (flag->width - ft_strlen(temp)) - 1 :
		(flag->width - ft_strlen(temp));
	if (flag->minus == 1)
	{
		if (flag->hash == 1)
			ft_putnchar('0', flag);
		while (*(temp))
			ft_putnchar(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	right_just_short(temp, i, flag);
	return (1);
}

int		short_int(t_flag *flag, va_list lst, t_length *length)
{
	char			*temp;
	short			i;
	int				j;
	short			k;

	j = 0;
	i = get_signed(flag, length, lst);
	k = i;
	temp = ft_itoa_base(i, 10);
	short_p(temp, flag);
	free(temp);
	return (1);
}

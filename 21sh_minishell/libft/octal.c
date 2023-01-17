/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:04:03 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 15:14:55 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_oct(char *temp, int i, t_flag *flag)
{
	char a;

	if (flag->period == 1)
		flag->zero = 0;
	a = flag->zero == 1 ? '0' : ' ';
	while (i-- > 0)
		ft_putnchar(a, flag);
	if (flag->hash == 1 && *temp != '0')
		ft_putnchar('0', flag);
	while (*temp)
		ft_putnchar(*(temp)++, flag);
	return (1);
}

int		oct_p(char *temp, t_flag *flag)
{
	int	i;

	i = flag->hash ? (flag->width - ft_strlen(temp)) - 1 :
		(flag->width - ft_strlen(temp));
	if (flag->minus == 1)
	{
		if (flag->hash == 1 && *temp != 0)
			ft_putnchar('0', flag);
		while (*(temp))
			ft_putnchar(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	right_just_oct(temp, i, flag);
	return (1);
}

int		octal(t_flag *flag, va_list lst, t_length *length)
{
	char			*temp;
	uintmax_t		i;
	int				j;
	uintmax_t		k;

	j = 0;
	i = get_num(flag, length, lst);
	k = i;
	temp = ft_itoa_base(i, 8);
	oct_p(temp, flag);
	free(temp);
	return (1);
}

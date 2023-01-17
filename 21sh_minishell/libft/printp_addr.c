/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:23:05 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 09:27:52 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_addr(char *temp, int i, t_flag *flag)
{
	while (i-- > 0)
		ft_putnchar(' ', flag);
	ft_putnstr("0x", flag);
	while (*temp)
		ft_putnchar(*(temp)++, flag);
	return (1);
}

int		addr(char *temp, t_flag *flag)
{
	int	i;

	i = (flag->width - ft_strlen(temp)) - 2;
	if (flag->minus == 1)
	{
		ft_putnstr("0x", flag);
		while (*(temp))
			ft_putnchar(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	else
		return (right_just_addr(temp, i, flag));
}

int		printp_addr(t_flag *flag, va_list lst)
{
	char	*temp;

	temp = ft_itoa_base(va_arg(lst, long), 16);
	addr(temp, flag);
	free(temp);
	return (1);
}

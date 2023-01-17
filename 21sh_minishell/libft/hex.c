/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:09:25 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 13:53:49 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		right_just_hex(char *temp, int i, t_flag *flag)
{
	char a;

	a = flag->zero == 1 ? '0' : ' ';
	if (flag->zero == 0)
		while (i-- > 0)
			ft_putnchar(a, flag);
	if (flag->hash == 1 && *temp != '0')
	{
		if (flag->type == 'X')
			ft_putnstr("0X", flag);
		else
			ft_putnstr("0x", flag);
	}
	if (flag->zero == 1)
		while (i-- > 0)
			ft_putnchar(a, flag);
	while (*temp)
		ft_putnchar(*(temp)++, flag);
	return (1);
}

int		hex_p(char *temp, t_flag *flag)
{
	int	i;

	i = flag->hash ? (flag->width - ft_strlen(temp)) - 2 :
		flag->width - ft_strlen(temp);
	if (flag->width == 0 && flag->max_width > 0)
	{
		i = flag->max_width - ft_strlen(temp);
		flag->zero = 1;
	}
	if (flag->minus == 1)
	{
		if (flag->hash == 1 && *temp != '0')
		{
			if (flag->type == 'X')
				ft_putnstr("0X", flag);
			else
				ft_putnstr("0x", flag);
		}
		while (*(temp))
			ft_putnchar(*temp++, flag);
		while (i-- > 0)
			ft_putnchar(' ', flag);
		return (1);
	}
	return (right_just_hex(temp, i, flag));
}

void	capitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] -= 32;
		i++;
	}
}

int		hex(t_flag *flag, va_list lst, t_length *length)
{
	char			*temp;
	uintmax_t		i;
	uintmax_t		k;

	i = get_num(flag, length, lst);
	k = i;
	temp = ft_print_hex(i, 16);
	if (flag->period == 1 && *temp == '0' && flag->max_width == 0)
		return (0);
	if (flag->type == 'X')
		capitalize(temp);
	hex_p(temp, flag);
	free(temp);
	return (1);
}

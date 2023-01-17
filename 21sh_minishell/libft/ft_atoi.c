/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:58:35 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/06/14 10:27:54 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_atoi(const char *str)
{
	long	ret;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	ret = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		if ((ret < 0) && (sign == 1))
			return (-1);
		else if ((ret < 0) && (sign == -1))
			return (0);
		i++;
	}
	return (ret * sign);
}

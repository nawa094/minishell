/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:55:31 by exam              #+#    #+#             */
/*   Updated: 2018/08/04 11:46:29 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*num_len(long *nu, int base, long *sign, int *index)
{
	int		i;
	long	num;

	i = 0;
	num = *nu;
	if (base < 2 || base > 16)
		return (NULL);
	if (num == 0)
		i++;
	if (num < 0)
	{
		num *= -1;
		*nu *= -1;
		*sign = 1;
		if (base == 10)
			i++;
	}
	while (num > 0)
	{
		num /= base;
		i++;
	}
	*index = i;
	return ((char *)malloc(sizeof(char) * (1 + i)));
}

char	*ft_itoa_base(intmax_t value, int base)
{
	long	num[2];
	char	*str;
	int		i[2];

	num[1] = 0;
	i[1] = 0;
	str = NULL;
	num[0] = (long)value;
	if ((str = num_len(&num[0], base, &num[1], &i[0])))
	{
		str[i[0]--] = '\0';
		if (num[0] == 0)
			str[0] = '0';
		while (num[0] > 0 && i[0] >= 0)
		{
			str[i[0]--] = '0'
				+ (i[1] = (num[0] % base));
			if (str[1 + i[0]] > '9')
				str[1 + i[0]] += 39;
			num[0] /= base;
		}
		if (base == 10 && num[1] == 1)
			str[0] = '-';
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:27:58 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 12:41:41 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*num_lenn(uintmax_t *nu, int base, uintmax_t *sign, int *index)
{
	int			i;
	uintmax_t	num;

	i = 0;
	num = *nu;
	*sign = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (num == 0)
		i++;
	while (num > 0)
	{
		num /= base;
		i++;
	}
	*index = i;
	return ((char *)malloc(sizeof(char) * (1 + i)));
}

char	*ft_print_hex(unsigned int value, int base)
{
	uintmax_t			num[2];
	char				*str;
	int					i[2];

	num[1] = 0;
	i[1] = 0;
	str = NULL;
	num[0] = (long)value;
	if ((str = num_lenn(&num[0], base, &num[1], &i[0])))
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

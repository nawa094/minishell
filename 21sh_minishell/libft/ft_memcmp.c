/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:15:50 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/28 15:26:44 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *str, const void *str2, size_t n)
{
	int				i;
	int				j;
	unsigned char	*temp;
	unsigned char	*temp2;

	i = 0;
	temp = (unsigned char *)str;
	temp2 = (unsigned char *)str2;
	while (i < (int)n)
	{
		j = (unsigned char)temp[i] - (unsigned char)temp2[i];
		if (j != 0)
			return (j);
		i++;
	}
	return (0);
}

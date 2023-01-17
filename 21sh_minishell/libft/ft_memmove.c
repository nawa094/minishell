/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:47:34 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/24 12:24:12 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;

	temp = (char *)dest;
	temp2 = (char *)src;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			temp[n] = temp2[n];
		}
	}
	else
		ft_memcpy(temp, temp2, n);
	return (dest);
}

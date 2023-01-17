/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:58:53 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/30 14:55:14 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		len_dest;
	int		j;

	len_dest = ft_strlen(dest);
	i = 0;
	j = len_dest;
	if (len_dest >= (int)size)
		return (size + ft_strlen((char *)src));
	while (src[i] != '\0' && len_dest + i < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	if (i == size)
		return (ft_strlen(dest) + ft_strlen(src));
	dest[len_dest + i] = '\0';
	return (len_dest + ft_strlen(src));
}

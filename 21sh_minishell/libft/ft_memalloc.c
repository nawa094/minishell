/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:21:26 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/25 08:53:35 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*free;
	size_t	i;

	i = 0;
	if (!(free = (char *)malloc(sizeof(size))) || size >= 65535)
		return (NULL);
	while (i < size)
	{
		free[i] = '\0';
		i++;
	}
	return (free);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:13:46 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/27 09:44:25 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*free;

	i = 0;
	if (!(free = (char *)malloc(size + 1)) || size >= 65535)
		return (NULL);
	while (i <= (int)size)
	{
		free[i] = '\0';
		i++;
	}
	return (free);
}

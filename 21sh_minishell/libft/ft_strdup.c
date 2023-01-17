/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:08:52 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/29 15:41:47 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dup = ft_strnew((size_t)ft_strlen((char *)str));
	if (!((char *)malloc(ft_strlen((char *)str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[j];
		i++;
		j++;
	}
	dup[i] = '\0';
	return (dup);
}

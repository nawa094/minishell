/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:43:05 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/29 08:51:52 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	int			j[2];
	const char	*temp;

	i = 0;
	j[1] = 0;
	j[0] = 0;
	temp = NULL;
	if (!ft_strlen((char *)needle))
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j[1] = i;
		j[0] = 0;
		while (haystack[j[1]] == needle[j[0]] && j[1] < (int)len)
		{
			temp = &haystack[i];
			j[1]++;
			j[0]++;
			if (needle[j[0]] == '\0')
				return ((char *)temp);
		}
		i++;
	}
	return (NULL);
}

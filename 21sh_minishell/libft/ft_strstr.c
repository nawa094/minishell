/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:45:37 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/27 09:55:52 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i[3];
	int			count;
	const char	*temp;

	i[0] = 0;
	count = 0;
	if (!ft_strlen((char *)needle))
		return ((char *)haystack);
	while (haystack[i[0]] != '\0')
	{
		count = i[0];
		i[1] = 0;
		while (haystack[count] == needle[i[1]])
		{
			temp = &haystack[i[0]];
			count++;
			i[1]++;
			if (needle[i[1]] == '\0')
				return ((char *)temp);
		}
		i[0]++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:28:47 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/30 12:32:27 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				j;
	char			*temp;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)str);
	if (!(temp = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		temp[i] = f(i, str[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

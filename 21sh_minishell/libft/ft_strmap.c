/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:40:24 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/30 12:31:52 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		i;
	int		j;
	char	*temp;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)str);
	if (!(temp = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		temp[i] = f(str[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

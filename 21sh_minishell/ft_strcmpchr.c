/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:23:28 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/31 16:23:32 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_strcmpchr(const char *str1, const char str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i] != '\0' || str2 != '\0')
	{
		j = (unsigned char)str1[i] - (unsigned char)str2;
		if (j > 0)
			return (j);
		if (j < 0)
			return (j);
		break ;
	}
	return (0);
}

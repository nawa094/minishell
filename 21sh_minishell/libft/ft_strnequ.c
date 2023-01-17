/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:43:55 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/31 10:40:19 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *str1, char const *str2, size_t size)
{
	if (!str1 || !str2)
		return (-1);
	if (ft_strncmp(str1, str2, size) != 0)
		return (0);
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:03:57 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/28 14:03:59 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *temp;

	temp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	s1 = temp;
	return (s1);
}

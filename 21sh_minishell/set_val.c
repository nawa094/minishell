/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:07:28 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:36:02 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*set_val(char *str)
{
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) + 1;
	temp = ft_strnew(len);
	temp[0] = '=';
	ft_strcpy(&temp[1], str);
	return (temp);
}

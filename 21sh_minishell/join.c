/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 08:27:57 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:40:42 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

char	*join(char *str)
{
	char	*temp;
	int		len;
	int		i;

	i = 0;
	if (ft_strcmp("/", str) == 0)
		return (str);
	len = ft_strlen(str);
	temp = ft_strnew(len + 1);
	temp[i] = '/';
	ft_strcpy(&temp[1], str);
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 08:48:36 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 09:23:29 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*type(char **str, t_flag *flag)
{
	char	*charset;
	int		i;

	i = 0;
	charset = "sSpdDioOuUxXcC%";
	while (charset[i])
	{
		if (*(*str) == charset[i])
		{
			flag->type = charset[i];
			(*str)++;
			return (*str);
		}
		i++;
	}
	return (NULL);
}

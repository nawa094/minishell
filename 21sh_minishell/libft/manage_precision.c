/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 08:56:57 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/05 08:54:08 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*manage_precision(char **str, t_flag *flag)
{
	if (*(*str) == '.')
	{
		flag->period = 1;
		(*str)++;
		while (ft_isdigit(*(*str)))
		{
			flag->max_width = flag->max_width * 10 + (*(*str) - '0');
			(*str)++;
		}
	}
	return (*str);
}

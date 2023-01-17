/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 08:52:51 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/04 07:30:40 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*manage_width(char **str, t_flag *flag)
{
	while (ft_isdigit(**str))
	{
		flag->width = flag->width * 10 + (*(*str) - '0');
		(*str)++;
	}
	return (*str);
}

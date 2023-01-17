/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:15:33 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/05 09:43:51 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*flags(char **str, t_flag *flag)
{
	int i;

	i = 0;
	if (*(*str) == '#' || *(*str) == '-' || *(*str) == '+' || *(*str) == ' ' ||
			*(*str) == '0')
	{
		if (*(*str) == '#')
			flag->hash = 1;
		else if (*(*str) == '-')
			flag->minus = 1;
		else if (*(*str) == '+')
			flag->plus = 1;
		else if (*(*str) == ' ')
			flag->space = 1;
		else if (*(*str) == '0')
			flag->zero = 1;
		(*str)++;
		flags(str, flag);
	}
	return ((*str));
}

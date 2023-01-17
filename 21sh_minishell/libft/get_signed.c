/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:58:58 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/06 15:54:05 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	get_signed(t_flag *flag, t_length *length, va_list lst)
{
	intmax_t j;

	j = va_arg(lst, intmax_t);
	if (length->hh == 1)
		j = (signed char)j;
	else if (length->ll == 1)
		j = (long long int)j;
	else if (length->h == 1)
		j = (short int)j;
	else if (length->l == 1 || flag->type == 'D')
		j = (long int)j;
	else if (length->z == 1)
		j = (size_t)j;
	return (j);
}

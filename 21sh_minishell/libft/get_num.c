/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:12:36 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 12:46:32 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_num(t_flag *flag, t_length *length, va_list lst)
{
	unsigned int j;

	j = va_arg(lst, uintmax_t);
	if (length->hh == 1)
		j = (unsigned char)j;
	else if (length->ll == 1)
		j = (unsigned long long int)j;
	else if (length->h == 1)
		j = (unsigned short int)j;
	else if (length->l == 1 || flag->type == 'O' || flag->type == 'U')
		j = (unsigned long int)j;
	else if (length->z == 1)
		j = (size_t)j;
	return (j);
}

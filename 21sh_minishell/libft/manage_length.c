/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:00:30 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/06 16:12:14 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*small_length(char **str, t_length *length)
{
	if ((*(*str)) == 'l' || (*(*str)) == 'h' || (*(*str)) == 'z'
			|| (*(*str)) == 'j')
	{
		if ((*(*str)) == 'l')
			length->l = 1;
		else if ((*(*str)) == 'h')
			length->h = 1;
		else if ((*(*str)) == 'z')
			length->z = 1;
		else if ((*(*str)) == 'j')
			length->j = 1;
		(*str)++;
	}
	return (*str);
}

char	*manage_length(char **str, t_length *length)
{
	if (*(*str) == 'h' && *(*str + 1) == 'h')
	{
		length->hh = 1;
		(*str) += 2;
		return (*str);
	}
	if (*(*str) == 'l' && *(*str + 1) == 'l')
	{
		length->ll = 1;
		(*str) += 2;
		return (*str);
	}
	return (small_length(str, length));
}

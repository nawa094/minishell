/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delegate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:41:43 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 14:20:49 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		other(t_flag *flag, t_length *length, va_list lst)
{
	if (flag->type == 'p')
		return (printp_addr(flag, lst));
	else if (flag->type == 'x' || flag->type == 'X')
		return (hex(flag, lst, length));
	else if (flag->type == 'u' || flag->type == 'U')
		return (uns_int(flag, lst, length));
	else if (flag->type == 'o' || flag->type == 'O')
		return (octal(flag, lst, length));
	else if (flag->type == '%')
		return (per(flag));
	else
		return (0);
}

int		num(t_flag *flag, t_length *length, va_list lst)
{
	if (flag->type == 'i' || flag->type == 'd' || flag->type == 'D')
	{
		if ((flag->type == 'i' || flag->type == 'd') && length->l == 1)
			return (long_int(flag, lst));
		else if ((flag->type == 'i' || flag->type == 'd') && length->ll == 1)
			return (long_long(flag, lst));
		else if ((flag->type == 'i' || flag->type == 'd') && length->hh == 1)
			return (signed_char(flag, lst));
		else if ((flag->type == 'i' || flag->type == 'd') && length->h == 1)
			return (short_int(flag, lst, length));
		else if ((flag->type == 'i' || flag->type == 'd') && length->j == 1)
			return (intmax(flag, lst, length));
		else if ((flag->type == 'i' || flag->type == 'd') && length->z == 1)
			return (size(flag, lst, length));
		else if (flag->type == 'D')
			return (long_int(flag, lst));
		else if (flag->type == 'i' || flag->type == 'd')
			return (interger(flag, lst, length));
	}
	return (other(flag, length, lst));
}

int		delegate(t_flag *flag, t_length *length, va_list lst)
{
	if (flag->type == 's' || flag->type == 'S')
	{
		if ((flag->type == 's' && length->l == 1) || flag->type == 'S')
			return (ft_wputstr(flag, lst));
		else
			return (string(flag, lst));
	}
	else if (flag->type == 'c' || flag->type == 'C')
	{
		if ((flag->type == 'c' && length->l == 1) || flag->type == 'C')
			return (ft_wputchar(flag, lst));
		else
			return (character(flag, lst));
	}
	else
		return (num(flag, length, lst));
}

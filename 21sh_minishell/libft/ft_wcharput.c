/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:48:42 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 11:44:50 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		txt_size(unsigned int w)
{
	if (w <= 127)
		return (1);
	else if (w >= 128 && w <= 2047)
		return (2);
	else if (w >= 2048 && w <= 65535)
		return (3);
	else if (w >= 65536 && w <= 2097151)
		return (4);
	else
		return (0);
}

void			ft_wcharput(wchar_t c, t_flag *flag)
{
	int				size;
	unsigned char	byte;

	size = txt_size(c);
	if (size == 1)
	{
		ft_putnchar(c, flag);
		return ;
	}
	byte = (260 << (4 - size)) | (c >> ((size - 1) * 6));
	ft_putnchar(byte, flag);
	size--;
	while (size-- >= 0)
	{
		byte = ((c >> ((size) * 6)) & 63) | 128;
		ft_putnchar(byte, flag);
	}
}

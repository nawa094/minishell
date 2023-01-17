/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 09:25:52 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 13:53:09 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_length	*init_length(void)
{
	t_length	*temp;

	temp = (t_length *)malloc(sizeof(t_length));
	temp->hh = 0;
	temp->ll = 0;
	temp->l = 0;
	temp->h = 0;
	temp->j = 0;
	temp->z = 0;
	return (temp);
}

void		zero_flag(t_flag *tmp)
{
	tmp->hash = 0;
	tmp->plus = 0;
	tmp->minus = 0;
	tmp->space = 0;
	tmp->zero = 0;
	tmp->width = 0;
	tmp->period = 0;
	tmp->max_width = 0;
	tmp->per = 0;
	tmp->type = '\0';
}

void		conv(char *str, t_flag *flag, va_list lst)
{
	t_length		*length;
	char			*start;

	start = str;
	length = init_length();
	flags(&str, flag);
	manage_width(&str, flag);
	manage_precision(&str, flag);
	manage_length(&str, length);
	type(&str, flag);
	delegate(flag, length, lst);
	free(length);
	zero_flag(flag);
	ft_memcpy(start, str, ft_strlen(str) + 1);
}

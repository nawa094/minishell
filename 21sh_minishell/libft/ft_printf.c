/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:12:09 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/07 13:19:13 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				search(const char *format1, t_flag *flag, va_list lst)
{
	int		i;
	char	*format;

	i = 0;
	format = ft_strdup(format1);
	while (format[i])
	{
		if (format[i] == '%')
			conv(&format[i + 1], flag, lst);
		else
			ft_putnchar(format[i], flag);
		i++;
	}
	free(format);
	return (flag->ret);
}

t_flag			*init_flag(void)
{
	t_flag *tmp;

	tmp = (t_flag *)malloc(sizeof(t_flag));
	tmp->hash = 0;
	tmp->plus = 0;
	tmp->minus = 0;
	tmp->space = 0;
	tmp->zero = 0;
	tmp->width = 0;
	tmp->period = 0;
	tmp->ret = 0;
	tmp->max_width = 0;
	tmp->per = 0;
	tmp->type = '\0';
	return (tmp);
}

int				ft_printf(char const *format, ...)
{
	va_list		lst;
	t_flag		*flag;
	int			i;

	va_start(lst, format);
	flag = init_flag();
	search(format, flag, lst);
	i = flag->ret;
	free(flag);
	va_end(lst);
	return (i);
}

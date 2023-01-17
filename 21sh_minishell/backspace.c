/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 08:54:23 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/28 09:51:33 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	backspace(t_term *term)
{
	int		i;
	int		j;
	char	*str;

	if (term->c <= 0)
		return ;
	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(term->str) - 1);
	ft_putstr("\033[s");
	while (i++ < term->c)
		ft_putstr("\b");
	ft_putstr("\033[0K");
	i = 0;
	while (term->str[i])
	{
		if (i == term->c - 1)
			i++;
		else
		{
			str[j] = term->str[i];
			i++;
			j++;
		}
	}
	ft_putstr(str);
	ft_putstr("\033[u");
	ft_putchar('\b');
	ft_strdel(&term->str);
	term->str = str;
	term->c--;
}

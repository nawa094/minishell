/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:11:05 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/27 09:08:07 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int		keys(char *str, t_his *his, t_term *term)
{
	his->str = NULL;

	if (str[1] == '[' && str[2] == 'A')
	{
		ft_putstr("\b\b");
		ft_putendl("up");
		return (1);
	}
	else if (str[1] == '[' && str[2] == 'B')
	{
		ft_putstr("\b\b");
		ft_putstr("down\n");
		return (1);
	}
	else if (str[1] == '[' && str[2] == 'C')
	{
		ft_putstr("\033[1C");
		term->c++;
		return (1);
	}
	else if (str[1] == '[' && str[2] == 'D')
	{
		left(term);
		return (1);
	}
	//if (str[0] == '1')
	//	ft_putendl("enter");
	else if (str[0] == 27 && str[1] == 91 && str[2] == 51)
		ft_putendl("del");
	else if (str[0] == 127)
		backspace(term);
	//if (str[0] == '3')
	//	ft_putendl("last");*/
	return (0);
}
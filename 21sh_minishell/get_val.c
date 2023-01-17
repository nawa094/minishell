/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:54:33 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:41:04 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

char	*get_val(char *str, t_env *env)
{
	char	*temp;
	t_env	*temp2;

	temp2 = env;
	temp = NULL;
	while (env != NULL)
	{
		if (ft_strstr(env->str, str))
		{
			temp = ft_strchr(env->str, '=');
			temp++;
			break ;
		}
		env = env->next;
	}
	if (temp == NULL)
		ft_putstr("there was an error fetching the value\n");
	env = temp2;
	return (temp);
}

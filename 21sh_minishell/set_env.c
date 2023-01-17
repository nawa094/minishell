/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:25:49 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:36:17 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

int		set_env(char *var, char *val, t_env **env)
{
	char		*temp;
	char		*ptr;
	t_env		*temp2;

	while ((*env)->prev != NULL)
		(*env) = (*env)->prev;
	temp2 = (*env);
	temp = ft_strjoin("=", val);
	while ((*env))
	{
		if ((ft_strstr((*env)->str, var)))
		{
			ptr = ft_strjoin(var, temp);
			(*env)->str = ft_strcpy((*env)->str, ptr);
			ft_strdel(&temp);
			ft_strdel(&ptr);
			(*env) = temp2;
			return (1);
		}
		(*env) = (*env)->next;
	}
	(*env) = temp2;
	return (-1);
}

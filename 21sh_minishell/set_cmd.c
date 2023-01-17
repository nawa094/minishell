/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 08:10:50 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/04 14:13:50 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

int	set_new(char **str, t_env **env, char *temp)
{
	t_env	*hold;

	hold = init_lst();
	hold->str = ft_strjoin(str[1], temp);
	(*env)->next = hold;
	hold->prev = (*env);
	(*env) = hold;
	ft_strdel(&temp);
	while ((*env)->prev != NULL)
		(*env) = (*env)->prev;
	return (1);
}

int	set_cmd(char **str, t_env **env)
{
	char		*temp;
	char		*ptr;

	if (str[2] == NULL)
		str[2] = ft_strnew(0);
	if (str[1] == NULL)
		return (1);
	temp = ft_strjoin("=", str[2]);
	while ((*env))
	{
		if ((ft_strstr((*env)->str, str[1])))
		{
			ptr = ft_strjoin(str[1], temp);
			(*env)->str = ft_strcpy((*env)->str, ptr);
			ft_strdel(&temp);
			ft_strdel(&ptr);
			return (1);
		}
		if ((*env)->next == NULL)
			break ;
		(*env) = (*env)->next;
	}
	return (set_new(str, env, temp));
}

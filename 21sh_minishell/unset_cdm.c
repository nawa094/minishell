/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cdm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 08:20:22 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/04 15:16:43 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

int		last_set(t_env *env)
{
	t_env	*last;

	last = env->prev;
	last->next = NULL;
	env->prev = NULL;
	ft_strdel(&(env->str));
	free(env);
	return (1);
}

int		unset_cmd(char **str, t_env **env)
{
	t_env	*ahead;
	t_env	*behind;
	t_env	**head;

	head = env;
	if (str[1] == NULL)
		return (1);
	while ((*env))
	{
		if (ft_strstr((*env)->str, str[1]))
		{
			if ((*env)->next == NULL)
				return (last_set((*env)));
			ahead = (*env)->next;
			behind = (*env)->prev;
			free(*env);
			ahead->prev = behind;
			behind->next = ahead;
			return (1);
		}
		env = &((*env)->next);
	}
	ft_putstr("couldn't find value\n");
	return (1);
}

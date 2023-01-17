/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:43:02 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/04 09:43:04 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	lst_del(t_env *env)
{
	t_env	*temp;

	while (env->prev != NULL)
		env = env->prev;
	while (env)
	{
		temp = env->next;
		free(env);
		env = temp;
	}
}

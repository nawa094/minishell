/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 09:28:36 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/02 09:28:39 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	edit_env(t_env *env)
{
	int				i;
	t_env			*head;
	char			**reenv;
	extern	char	**environ;

	i = 1;
	cpy_env(env);
	head = env;
	while (env->next != NULL)
	{
		env = env->next;
		i++;
	}
	reenv = (char **)malloc(sizeof(i + 2));
	i = 0;
	env = head;
	while (env)
	{
		reenv[i] = env->str;
		i++;
		env = env->next;
	}
	reenv[i] = NULL;
	env = head;
	environ = reenv;
}

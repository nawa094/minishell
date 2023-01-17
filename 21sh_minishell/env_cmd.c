/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:05:38 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/27 14:05:42 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

int		env_cmd(t_env **env)
{
	int		i;
	t_env	**head;

	i = 0;
	while ((*env)->prev != NULL)
		(*env) = (*env)->prev;
	head = env;
	while ((*head) != NULL)
	{
		ft_putstr((*head)->str);
		ft_putchar('\n');
		head = &((*head)->next);
	}
	return (1);
}

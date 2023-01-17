/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:28:32 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/04 08:49:31 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

void	uhm(t_env **head, t_env **curr, t_env **temp)
{
	curr = head;
	while ((*curr)->next != NULL)
		(*curr) = (*curr)->next;
	(*curr)->next = (*temp);
	(*temp)->prev = (*curr);
}

t_env	*cpy_lst(char **enviro)
{
	int		i;
	t_env	*temp;
	t_env	*head;
	t_env	*curr;

	i = 0;
	head = NULL;
	curr = NULL;
	while (enviro[i])
	{
		if (!(temp = init_lst()))
			return (NULL);
		temp->str = (enviro[i]);
		if (head == NULL)
			head = temp;
		else
			uhm(&head, &curr, &temp);
		i++;
	}
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 09:49:52 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/27 08:12:18 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

t_env	*init_lst(void)
{
	t_env *temp;

	temp = (t_env *)malloc(sizeof(t_env));
	temp->next = NULL;
	temp->str = NULL;
	temp->prev = NULL;
	return (temp);
}

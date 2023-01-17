/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 08:13:58 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/27 08:56:51 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

t_term		*init_term(void)
{
	t_term	*temp;

	temp = (t_term *)malloc(sizeof(t_term));
	temp->c = 0;
	temp->str = NULL;
	return (temp);
}

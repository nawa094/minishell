/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_his.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 08:47:07 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/26 08:47:29 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

t_his	*init_his(void)
{
	t_his	*temp;

	temp = (t_his *)malloc(sizeof(t_his));
	ft_bzero(temp, sizeof(t_his));
	return (temp);
}
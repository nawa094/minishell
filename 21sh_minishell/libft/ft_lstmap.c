/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:17:25 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/06/01 13:06:17 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;

	temp = NULL;
	if (lst)
	{
		temp = ft_lstmap(lst->next, (*f));
		ft_lstadd(&temp, f(lst));
		return (temp);
	}
	return (NULL);
}

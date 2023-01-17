/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:38:05 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/31 11:07:00 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	int		i;
	char	*temp;

	if (!str)
		return (NULL);
	i = 0;
	if ((size_t)start > ft_strlen(str))
		return (NULL);
	if (!(temp = malloc(len + 1)))
		return (NULL);
	ft_strncpy(temp, &str[start], len);
	temp[len] = '\0';
	return (temp);
}

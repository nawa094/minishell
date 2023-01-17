/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:12:42 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/28 14:18:38 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_str(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	else
		return (1);
}

char		*ft_strtrim(char const *str)
{
	int		i;
	int		k;
	char	*temp;

	if (!(str))
		return (NULL);
	i = 0;
	temp = (char *)str;
	k = ft_strlen((char *)str);
	if (!(is_str((char *)str)))
		return ((char *)str);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '"')
		i++;
	if (str[i] == '\0')
		return (ft_strnew(0));
	while (str[k] == ' ' || str[k] == '\n'
			|| str[k] == '\t' || str[k] == '\0' || str[k] == '"')
		k--;
	k = k + 1;
	return (ft_strsub((char *)str, i, (size_t)(k - i)));
}

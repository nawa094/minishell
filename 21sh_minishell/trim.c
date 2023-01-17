/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:37:07 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:34:16 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	is_str_q(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	else
		return (1);
}

char		*trim(char const *str)
{
	int		i;
	int		k;
	char	*temp;

	if (!(str))
		return (NULL);
	i = 0;
	temp = (char *)str;
	k = ft_strlen((char *)str);
	if (!(is_str_q((char *)str)))
		return ((char *)str);
	while (str[i] == '"')
		i++;
	if (str[i] == '\0')
		return (ft_strnew(0));
	if (str[k] == '\0')
		k--;
	while (str[k] == '"')
		k--;
	k = k + 1;
	return (ft_strsub((char *)str, i, (size_t)(k - i)));
}

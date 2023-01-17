/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 09:20:41 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:50:37 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char			*str_cpy_m(const char *str, char c, char b)
{
	int		x;
	char	*temp;

	x = 0;
	while (str[x] && str[x] != c && str[x] != b)
		x++;
	temp = ft_strsub(str, 0, x);
	return (temp);
}

int				how_many_m(const char *s, char c, char b)
{
	int pp;
	int count;

	pp = 0;
	count = 0;
	while (s[pp])
	{
		while (s[pp] == c || s[pp] == b)
			pp++;
		while (s[pp] != c && s[pp] != b && s[pp] != '\0')
			pp++;
		count++;
	}
	if (s[pp - 1] == c || s[pp - 1] == b)
		count -= 1;
	return (count);
}

char			**temp_cpy_m(const char *str, char c, char b, char **temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c || str[i] == b)
			i++;
		if (!str[i])
		{
			temp[j] = NULL;
			return (temp);
		}
		temp[j] = str_cpy_m(&str[i], c, b);
		j++;
		while (str[i] != c && str[i] != b && str[i] != '\0')
			i++;
	}
	temp[j] = NULL;
	return (temp);
}

char			**ft_split(char const *str, char c, char b)
{
	char	**temp;

	temp = NULL;
	if (!str)
		return (temp);
	if (ft_strlen(str) == 0)
		return (temp);
	if (!(temp = (char **)malloc(sizeof(char *) * (how_many_m(str, c, b) + 1))))
		return (NULL);
	temp = temp_cpy_m(str, c, b, temp);
	return (temp);
}

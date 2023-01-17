/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:08:27 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/23 15:52:52 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		j = (unsigned char)str1[i] - (unsigned char)str2[i];
		if (j > 0)
			return (j);
		if (j < 0)
			return (j);
		i++;
	}
	return (0);
}

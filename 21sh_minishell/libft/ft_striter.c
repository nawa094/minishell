/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:27:38 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/05/31 10:50:49 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *str, void (*f)(char *))
{
	int i;

	if (!str || !f)
		return ;
	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		f(&str[i]);
		i++;
	}
}
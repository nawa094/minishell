/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:17:42 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:28:12 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		join(char **line)
{
	int			i;
	int			size;
	char		*temp;
	char		buf[2];

	i = 0;
	temp = NULL;
	buf[0] = '\0';
	buf[1] = '\0';
	size = read(0, buf, 1);
	if (buf[0] == '\n')
		buf[0] = '\0';
	temp = ft_strjoin((*line), buf);
	free((*line));
	(*line) = temp;
	if (buf[0] == '\0')
		return (2);
	return (size);
}

int				get_next_line(char **line)
{
	int			size;

	size = 1;
	(*line) = ft_strnew(0);
	while (size == 1)
		size = join(line);
	return (size);
}

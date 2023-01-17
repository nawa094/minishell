/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 07:53:10 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/25 07:54:31 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	fatal(char *str)
{
	ft_putstr("error: ");
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
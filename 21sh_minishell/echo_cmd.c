/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:29:11 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/08/27 07:29:19 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

int		quote(char **str)
{
	char	*temp;
	int		i;

	i = 1;
	while (str[i])
	{
		temp = trim(str[i]);
		write(1, temp, ft_strlen(temp));
		if (str[i + 1] != NULL)
			ft_putchar(' ');
		if (str[i + 1] == NULL)
			ft_putchar('\n');
		free(temp);
		i++;
	}
	return (1);
}

int		dollar(char **str, t_env **env)
{
	char	*val;
	int		i;
	int		j;

	i = 1;
	j = 1;
	val = get_val(&str[i][j], (*env));
	ft_putstr(val);
	ft_putchar('\n');
	return (1);
}

int		echo_cmd(char **str, t_env **env)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	if (str[i] == NULL)
		return (0);
	if (ft_strcmpchr(str[i], '$') == 0)
		return (dollar(str, env));
	if (ft_strcmpchr(str[i], '"') == 0)
		return (quote(str));
	while (str[i])
	{
		write(1, str[i], ft_strlen(str[i]));
		if (str[i + 1] != NULL)
			ft_putchar(' ');
		if (str[i + 1] == NULL)
			ft_putchar('\n');
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:15:20 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/26 07:22:00 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minishell.h"

int		check_builtin(char **str, t_env *enviro)
{
	if (ft_strcmp(str[0], "echo") == 0)
		return (echo_cmd(str, &enviro));
	else if (ft_strcmp(str[0], "cd") == 0)
		return (cd_cmd(str, &enviro));
	else if (ft_strcmp(str[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(str[0], "setenv") == 0)
		return (set_cmd(str, &enviro));
	else if (ft_strcmp(str[0], "unsetenv") == 0)
		return (unset_cmd(str, &enviro));
	else if (ft_strcmp(str[0], "env") == 0)
		return (env_cmd(&enviro));
	return (0);
}

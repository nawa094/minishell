/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:32:52 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:57:44 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

int		last_dir(t_env **env)
{
	char	*last;
	char	*cwd;
	char	buf[4096];

	last = get_val("OLDPWD=", (*env));
	cwd = getcwd(buf, 4095);
	if (chdir(last) == 0)
	{
		set_env("OLDPWD", cwd, env);
		cwd = getcwd(buf, 4095);
		set_env("PWD", cwd, env);
		return (1);
	}
	ft_putstr("error: there was a problem changing to that directory.\n");
	return (1);
}

int		change_again(t_env **env, char **str)
{
	char	*cwd;
	int		i;
	char	buf[4096];

	cwd = getcwd(buf, 4095);
	i = ft_strcmpchr(str[1], '~') == 0 ? 2 : 1;
	chdir(get_val("HOME=", (*env)));
	if (chdir(&str[1][i]) == 0)
	{
		set_env("OLDPWD", cwd, env);
		cwd = getcwd(buf, 4095);
		set_env("PWD", cwd, env);
		return (1);
	}
	if (str[1][1] == '\0')
		return (1);
	ft_putstr("error: there was a problem changing to that directory.\n");
	return (1);
}

int		home_dir(t_env **env)
{
	char	*cwd;
	char	*home;
	char	buf[4096];

	home = get_val("HOME=", (*env));
	cwd = getcwd(buf, 4095);
	if (chdir(home) == 0)
	{
		set_env("OLDPWD", cwd, env);
		cwd = getcwd(buf, 4095);
		set_env("PWD", cwd, env);
		return (1);
	}
	ft_putstr("error: there was a problem changing to that directory.\n");
	return (1);
}

int		cd_cmd(char **str, t_env **env)
{
	char	*cwd;
	char	buf[4096];

	cwd = getcwd(buf, 4095);
	if (str[1] == NULL)
		return (home_dir(env));
	if (ft_strcmpchr(str[1], '/') == 0 || ft_strcmpchr(str[1], '~') == 0)
		return (change_again(env, str));
	if (ft_strcmp(str[1], "-") == 0)
		return (last_dir(env));
	if (chdir(str[1]) == 0)
	{
		set_env("OLDPWD", cwd, env);
		cwd = getcwd(buf, 4095);
		set_env("PWD", cwd, env);
		return (1);
	}
	ft_putstr("error: there was a problem changing to that directory.\n");
	return (1);
}

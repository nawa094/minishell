/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 14:34:16 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/28 10:07:56 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"
#define NO_CMD ft_putstr("\x1b[31m");ft_putstr(temp);ft_putstr("\x1b[0m");

char	*parse_str(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '/')
		{
			i++;
			return (&str[i]);
		}
		i--;
	}
	return (str);
}

int		launch_prog(char *name, char **str, char *path, char **environ)
{
	pid_t	pid;
	char	*cmd;

	cmd = join(name);
	pid = fork();
	if (pid == 0)
		execve(ft_strjoinfree(path, cmd), &str[0], environ);
	else if (pid < 0)
	{
		ft_putstr("error with forking\n");
		return (-1);
	}
	if (pid > 0)
		wait(&pid);
	free(cmd);
	return (1);
}

int		no_path(char **str, char **environ)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(str[0], &str[0], environ);
	else if (pid < 0)
	{
		ft_putstr("error with forking\n");
		return (1);
	}
	if (pid > 0)
		wait(&pid);
	return (1);
}

int		search_path(char **paths, char **str, char **environ, char *temp)
{
	int				i;
	DIR				*dir;
	struct dirent	*sd;

	i = 0;
	while (paths[i])
	{
		dir = opendir(paths[i]);
		while ((sd = readdir(dir)) != NULL)
		{
			if (ft_strcmp(sd->d_name, temp) == 0)
			{
				closedir(dir);
				return (launch_prog(sd->d_name, str, paths[i], environ));
			}
		}
		closedir(dir);
		i++;
	}
	NO_CMD
	ft_putstr(" 21sh: command not found\n");
	return (1);
}

int		exec_cmd(char **paths, char **str, char **environ)
{
	int				i;
	char			*temp;

	i = 0;
	temp = parse_str(str[0]);
	if (*str[0] == '/')
		return (no_path(str, environ));
	if (paths == NULL)
	{
		ft_putstr("No paths to executables found\n");
		return (1);
	}
	return (search_path(paths, str, environ, temp));
}

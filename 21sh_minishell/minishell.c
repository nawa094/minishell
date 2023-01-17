/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:14:48 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/28 09:19:22 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"
#include "term.h"
#include "termios.h"

int		upper(char **paths, char **args, t_env **env, char **enviro)
{
	while ((*env))
	{
		if (ft_strstr((*env)->str, "PATH="))
		{
			paths = ft_strsplit(&(*env)->str[5], ':');
			break ;
		}
		if ((*env)->next == NULL)
			break ;
		(*env) = (*env)->next;
	}
	cpy_env(*env);
	exec_cmd(paths, args, enviro);
	if (args)
		garbage(args);
	if (paths)
		garbage(paths);
	return (1);
}

int		parse(char *str, char **env, t_env **enviro)
{
	char		**paths;
	int			i;
	int			j;
	char		**args;

	i = 0;
	j = 0;
	if (*str == '\0')
		return (1);
	paths = NULL;
	args = ft_split(str, ' ', '\t');
	if (args[0] == NULL)
	{
		garbage(args);
		return (1);
	}
	if (check_builtin(args, (*enviro)) == 1)
	{
		if (args)
			garbage(args);
		return (1);
	}
	return (upper(paths, args, enviro, env));
}

int		main(void)
{
	extern char	**environ;
	t_env		*env;
	t_his		*his;
	t_term		*term;

	env = cpy_lst(environ);
	his = init_his();
	term = init_term();
	term->c = 0;
	prompt();
	while (1)
	{
		while (env->prev != NULL)
			env = env->prev;
		ft_readline(env, his, term);
		reset();
		prompt();
	}
	return (0);
}

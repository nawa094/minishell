/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 08:26:56 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/28 10:08:34 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <term.h>
#include <termios.h>
#include "libft/libft.h"

void		raw(struct termios old)
{
	struct termios raw;
	raw = old;
	//raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tputs(tgetstr("nd", NULL), 0, outfun2);
	if (tcsetattr(0, TCSAFLUSH, &raw) < 0)
		fatal("applying settings");
}

void		init_21_shell(void)
{
	struct termios old_sett;

	if (tcgetattr(0, &old_sett) < 0)
		fatal("setting up terminal");
	g_old_sett = old_sett;
	raw(old_sett);
}

void		ft_readline(t_env *env, t_his *his, t_term *term)
{
	char		buf[8];
	extern char **environ;
	int			i;
	int			len;
	
	init_21_shell();
	term->str = ft_strnew(0);
	i = 0;
	while ((len = read(STDIN_FILENO, buf, 8)))
	{
		buf[len] = '\0';
		i = keys(buf, his, term);
		if (i == 0 && *buf != 27)
		{
			while (buf[i])
			{
				if (ft_isprint(buf[i]))
				{
					ft_putchar(buf[i]);
					term->str = ft_strjoinfree(term->str, &buf[i]);
					term->c++;
				}
				i++;;
			}
		}
		if (buf[0] == '\n')
		{
			term->c = 0;
			if (ft_strcmp(term->str, "exit") == 0)
				exit(EXIT_SUCCESS);
			ft_putchar('\n');
			parse(term->str, environ, &env);
			break ;
		}
		ft_bzero(buf, sizeof(buf));
	}
}

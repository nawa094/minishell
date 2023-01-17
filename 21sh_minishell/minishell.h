/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:33:28 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/27 09:08:56 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <termios.h>
# include <term.h>
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

struct termios	g_old_sett;
typedef struct	s_env
{
	char			*str;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_his
{
	char			*str;
	struct s_his	*next;
	struct s_his	*prev;
}				t_his;

typedef struct s_term
{
	int				c;
	char			*str;
}				t_term;

int				check_builtin(char **str, t_env *env);
void			prompt(void);
void			backspace(t_term *term);
t_term			*init_term(void);
t_his			*init_his(void);
void			left(t_term *term);
int				outfun2(int c);
int				parse(char *str, char **env, t_env **enviro);
void			fatal(char *str);
void			reset(void);
void			init_21_term(void);
void			ft_readline(t_env *env, t_his *his, t_term *term);
int				keys(char *str, t_his *his, t_term *term);
void			lst_del(t_env *env);
void			edit_env(t_env *env);
void			cpy_env(t_env *env);
char			**ft_split(char const *str, char a, char b);
char			*trim(char const *str);
int				unset_cmd(char **str, t_env **env);
int				ft_strcmpchr(const char *str1, const char str2);
t_env			*init_lst(void);
t_env			*cpy_lst(char **enviro);
char			*get_val(char *str, t_env *env);
char			*ft_strjoinfree(char *s1, char *s2);
int				echo_cmd(char **str, t_env **env);
char			*join(char *cmd);
char			*set_val(char *str);
void			garbage(char **str);
int				cd_cmd(char **str, t_env **env);
int				pwd(void);
int				set_cmd(char **str, t_env **env);
int				env_cmd(t_env **env);
int				exec_cmd(char **paths, char **str, char **environ);
int				set_env(char *var, char *value, t_env **env);

#endif

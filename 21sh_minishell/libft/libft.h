/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmumbwe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:01:09 by nmumbwe           #+#    #+#             */
/*   Updated: 2018/09/03 13:26:01 by nmumbwe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1
# include <string.h>
# define MIN_LONG "-9223372036854775808"
# define MAX_LONG "9223372036854775807"
# include <stdarg.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <inttypes.h>
# include <wchar.h>

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int i);
int				ft_isprint(int c);

void			*ft_memset(void *str, int c, size_t n);
void			*ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str, const void *str2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putnbr_fd(int c, int fd);

char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strsub(const char *str1, unsigned int start, size_t len);
int				ft_strequ(char const *str1, char const *str2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_strdel(char **str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strcat(char *dest, const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *str);
char			**ft_strsplit(char const *str, char c);
char			*ft_strjoin(const char *str1, const char *str2);
size_t			ft_strlen(char const *str);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				is_space(const char c);
int				get_next_line(char **line);
char			*ft_strjoinfree(char *s1, char *s2);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
**	This is the begining of the ft_printf functions.
*/

typedef struct	s_flag
{
	int			hash;
	int			zero;
	int			plus;
	int			minus;
	int			space;
	int			width;
	int			period;
	int			max_width;
	int			per;
	int			ret;
	char		type;
}				t_flag;

typedef struct	s_length
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_length;

void			conv(char *str, t_flag *flag, va_list lst);
void			ft_putlong(long c, t_flag *flag);
void			ft_putlong_l(long long c, t_flag *flag);
void			ft_putnbrn(int c, t_flag *flag);
void			ft_putnchar(char c, t_flag *flag);
void			ft_putnstr(char *str, t_flag *flag);
void			ft_wcharput(wchar_t c, t_flag *flag);

int				character(t_flag *flag, va_list lst);
int				delegate(t_flag *flag, t_length *length, va_list lst);
int				ft_printf(const char *format, ...);
int				ft_wputstr(t_flag *flag, va_list lst);
int				ft_wputchar(t_flag *flag, va_list lst);
int				ft_wstrlen(wchar_t *str);
int				hex(t_flag *flag, va_list lst, t_length *length);
int				interger(t_flag *flag, va_list lst, t_length *length);
int				intmax(t_flag *flag, va_list lst, t_length *length);
int				long_int(t_flag *flag, va_list lst);
int				long_long(t_flag *flag, va_list lst);
int				octal(t_flag *flag, va_list lst, t_length *length);
int				per(t_flag *flag);
int				printp_addr(t_flag *flag, va_list lst);
int				search(const char *str, t_flag *flag, va_list lst);
int				signed_char(t_flag *flag, va_list lst);
int				size(t_flag *flag, va_list lst, t_length *length);
int				short_int(t_flag *flag, va_list lst, t_length *length);
int				string(t_flag *flag, va_list lst);
int				uns_int(t_flag *flag, va_list lst, t_length *length);

char			*flags(char **str, t_flag *flag);
char			*ft_itoa_base(long value, int base);
char			*ft_print_hex(unsigned int value, int base);
char			*manage_length(char **str, t_length *length);
char			*manage_precision(char **str, t_flag *flag);
char			*manage_width(char **str, t_flag *flag);
char			*type(char **str, t_flag *flag);

unsigned int	get_num(t_flag *flag, t_length *length, va_list lst);

uintmax_t		get_unsigned(va_list lst, t_length *length);

intmax_t		get_signed(t_flag *flag, t_length *length, va_list lst);

#endif

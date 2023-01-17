# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmumbwe <nmumbwe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 10:37:10 by nmumbwe           #+#    #+#              #
#    Updated: 2018/09/28 08:54:10 by nmumbwe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

INCL = ./minishell.h ./libft/libft.h

SRCS = cd_cmd.c check_builtin.c cpy_env.c cpy_lst.c echo_cmd.c edit_env.c \
			env_cmd.c exec_cmd.c ft_split.c ft_strcmpchr.c garbage.c \
			get_val.c \
			init_lst.c join.c lst_del.c minishell.c prompt.c pwd.c set_cmd.c \
			set_env.c set_val.c trim.c unset_cdm.c keys.c ft_readline.c \
			fatal.c reset.c outfun2.c left.c init_his.c init_term.c \
			backspace.c

ATTACH = ./libft/libft.a

all : $(NAME)

$(NAME) : $(SRCS)
	@make -C ./libft
	@gcc -Wall -Wextra -Werror $(SRCS) $(ATTACH) -I $(INCL) -ltermcap
	@mv ./a.out 21sh
	@echo "compiling..."
clean :
	@rm -f $(NAME)
	@echo "deleting 21sh..."
fclean : clean
	rm -f $(NAME)
re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:34:08 by bepifani          #+#    #+#              #
#    Updated: 2022/03/04 17:41:34 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GCC = gcc
LIBFT = ./bible2/libft.a
LIB_BINARY = -L ./bible2 -lft -lreadline -ledit
CFLAGS = -Wall -Werror -Wextra
INCLUDE_SYS	= /Users/bepifani/.brew/Cellar/readline/8.1.2/include
LIB_SYS	= /Users/bepifani/.brew/opt/readline/lib/

SRCS= splits.c split2.c maker_commands.c maker_com_helper.c symbols.c \
		split_for_com.c split_for_com2.c error.c make_cmd.c make_cmd_utils.c \
		checker.c checker_utils.c checker_redirect.c split3.c main.c 1pwd.c 1echo.c \
		1env.c 1exit.c execution.c init.c pipex_utils.c pipex_utils2.c pipex.c \
		redirs.c signal_utils.c utils_2.c utils_1.c utils_3.c utils_cd.c 1cd.c  \
		1unset.c 1export.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) ./bible2/libft.a $(NAME)

$(NAME): $(OBJS) $(LIBFT) minishell.h Makefile
	$(GCC) $(CFLAGS) $(OBJS) -L $(LIB_SYS) $(LIB_BINARY) -o $(NAME)

%.o				:	%.c
					$(GCC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_SYS)
							
$(LIBFT):
	make -C ./libft_l/ bonus

clean:
	rm -f $(OBJS) $(OBJSB)
	make -C ./libft_l/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
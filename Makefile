# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:34:08 by bepifani          #+#    #+#              #
#    Updated: 2022/03/04 14:49:25 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h
LIBFT = bible2/libft.a

FLAGS = gcc -Wall -Wextra -Werror
RFLAG = -lreadline

FILES = splits.c split2.c maker_commands.c maker_com_helper.c symbols.c \
		split_for_mas.c split_for_mas2.c error.c make_cmd.c make_cmd_utils.c \
		checker.c checker_utils.c checkr_redirect.c split3.c main.c 1pwd.c 1echo.c 

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o: %.c $(HEADER)
	$(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT) $(HEADER)
	$(FLAGS) $(RFLAG) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
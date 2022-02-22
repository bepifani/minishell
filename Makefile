# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:34:08 by bepifani          #+#    #+#              #
#    Updated: 2022/02/22 18:46:01 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h
LIBFT = bible2/libft.a

FLAGS = gcc -Wall -Wextra -Werror
RFLAG = -lreadline

FILES = ./gnl/get_next_line.c	./gnl/get_next_line_utils.c	main.c 1pwd.c 1echo.c	parser.c	splits.c

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
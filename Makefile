# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:34:08 by bepifani          #+#    #+#              #
#    Updated: 2022/02/15 16:43:40 by bepifani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = so_long.h
LIBFT = bible/libft.a

FLAGS = gcc -Wall -Wextra -Werror

FILES = ./gnl/get_next_line.c	./gnl/get_next_line_utils.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

%.o: %.c $(HEADER)
	$(FLAGS) -o $@ -c $<

$(NAME) : $(OBJ) $(LIBFT) $(MLX) $(HEADER)
	$(FLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

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
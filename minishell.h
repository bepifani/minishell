/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:36:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/03 16:01:16 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "minishell> "

# include "./bible2/libft.h"
# include "./gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>              
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

typedef struct s_pip {
	int	lpipe[2];
	int	rpipe[2];
	int	in;
	int	curr_index;
	int	last_index;
}	t_pip;

typedef struct s_info {
	char	*line;
	char	**commands;
	char	***cmd;
	char	**splited;
	int		promptflag;
	int		argc;
	char	**argv;
	char	**env;
	int		exit;
	int		err;
	int		count;
	int		pid;
	int		*last_r;
	//t_vars	*vars;
	t_pip	pip;
}	t_info;

int		ft_pwd(void);
int		ft_echo(char **line);


//parser.c
int		ft_check_pipe(t_info *info); // 1 - ок 0 - не ок
int		ft_check_str_pipe(char *str);
int		ft_check_scobe(t_info *info);
int		ft_chack_spase(t_info *info); // // 1 - ок 0 - не ок
int		ft_redirect_helper (int i, char *line);
int		ft_check_redirect(t_info *info); // 1 - ок 0 - не ок
int		ft_scobes(char *line); // в каких сейчас скобках 1 - "" 2 - '' 0 - не в скобках

//splits.c
int		ft_where_quot(char c, int code); 								//is_it_quot
size_t 	ft_words(char *str, char *c, int code); 						//ft_word_count_up
//static char	*ft_newword(char *str, char c, size_t *i) 				//ft_newword_up
char	**ft_free_mas(char **mas); 										//ft_mmyfree_up
char	**ft_split_for_words(char *str1, char *str2); 					//ft_split_up
char	*ft_redir1(char *str);
char	**ft_split_to_pipe(t_info *info);

//split2.c
size_t	ft_counter_for_words(char *str, char symbol); 					//ft_word_count_l
int		ft_helper_for_words(char *str1, int i, char *str2, int c); 		//ft_parser_split_helper
int		ft_split_helper(char *str1, int i, char *str2, int c); 			//ft_parser_split_helper2

//maker_commands.c
int		ft_str_redirs(char *str, int q); 								//ft_strrchr_upred
void	ft_make_redir(t_info *info, char *str, int pos); 				//ft_create_l
void	ft_make_redir2(t_info *info, char *str, int pos); 				//ft_create_ll
void	ft_make_redir3(t_info *info, char *str, int q); 				//ft_create_r
void	ft_maker_commands(t_info *info); 								//ft_rebildredir

//maker_com_helper.c
int		ft_helper(char *str, int *i); 									//helper
void	ft_skiper2(char *str, int *i, int *j); 							//ft_skipp
int		ft_find_name(char *str, int i, char symbol); 					//find_name_len
char	*ft_skiper(char *str); 											//ft_skipsimic
char	*ft_remake(t_info *info, int i, int name, int pos); 			//ft_rebilder

//symbols.c
void	ft_delete_symbol(char *str, char *line); 						//ft_delquot
void	ft_swaper(t_info *info, int q, char *str); 						//ft_swap_string
void	ft_first_comm(t_info *info); 									//ft_changefirstcomm
int		ft_checker_for_name(char *line); 								//check_name_var_pars
int		ft_checker_for_pars(char *str); 								//ft_checkenv_d_pars

#endif
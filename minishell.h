/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:36:14 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/04 14:47:48 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "minishell> "

# include "./bible2/libft.h"
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

int	g_error;

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
	t_pip	pip;
}	t_info;

int		ft_pwd(void);
int		ft_echo(char **line);

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

//split_for_mas.c
char	*ft_add_end(void); 												//ft_add_noth
int		ft_add_helper(t_info *info, char **mas, int i, int j); 			//add_pipe_helper
int		ft_add_pipe(t_info *info); 										//ft_add_pipe

//split_for_mas2.c
char	*ft_pipe_to_str(t_info *info, int *i, int *j); 					//pipe_to_string
char	*ft_gnl_join(char *line, char *buf); 							//ft_gnlstrjoin
int		ft_checker_env(char *str); 										//ft_checkenv_d
int		ft_swap_ask(t_info *info, int index, int i); 					//ft_swap_ask

//error.c
int		ft_skiper3(t_info *info); 										//ft_skip
int		ft_error(t_info *info, int c); 									//ft_error
void	ft_error2(char *srt, char *arg, int i); 						//ft_error_cmd
void	ft_error3(int i); 												//ft_convert_error

//make_cmd.c
int		ft_com_counter(char **mas); 									//find_com_count
char	**ft_create_mas(t_info *info, int *j); 							//ft_create_node
char	***ft_create_cmd(t_info *info); 								//ft_createrofcmd

//make_cmd_utils.c
char	**ft_get_modif_arg(char **argv); 								//get_modif_arg
char	**ft_add_string(char **arr, char *str); 						//ft_add_string
void	ft_mas_from_arr_helper(char *s, int *c, int *len); 				//foo_helper
char	**ft_mas_from_arr(char **arr); 									//foo_bar

//checker.c
int		ft_where_is_quot(char *s); 										//ft_quot
int		ft_colon(char **sst); 											//ft_semicolon
int		ft_check_spaces(t_info *info); 									//check_space_inquot
void	ft_opendollar(t_info *info); 									//ft_opendollar
int		ft_big_checker(t_info *info); 									//ft_com_check

//checker_utils.c
char	*ft_import(char *st, char *str, int i, int j); 					//ft_import
int		ft_enver(t_info *info, int index, int i, int j); 				//ft_enver
int		ft_swap_symbols(t_info *info, int index, int i); 				//ft_swap_env
int		ft_checker_for_pipes(t_info *info); 							//ft_check_pipes
void	ft_cutter(t_info *info); 										//ft_cutter

//checkr_redirect.c
int		ft_false_redir(char *s, int i); 								//err_redd
int		ft_check_reddir(t_info *info); 									//ft_check_reddir

//split3.c
int		ft_get_size_of_line(char *args, int *i); 						//get_interval_len
void	ft_maker_for_strings(int acc, char *args, char **splited); 		//make_strings
size_t	ft_word_count_up(char *s, char *c, int code); 					//ft_word_count_up2
char	**ft_split_wquots(char *args); 									//ft_split_wquots

#endif
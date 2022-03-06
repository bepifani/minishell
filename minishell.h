/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:53:22 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/06 14:15:03 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "./libft_l/libft.h"
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# define BUFFER_SIZE 1

int	g_error;

typedef struct s_pip
{
	int	lpipe[2];
	int	rpipe[2];
	int	in;
	int	curr_index;
	int	last_herdoc;
}	t_pip;

typedef struct s_infor
{
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
	t_list	*content;
	t_pip	pip;
}	t_infor;

void		pipex(char ***cmd, t_infor *st);
int			contain(char **cmd);
void		ft_mshfree_helper(int exc, t_infor *st);
void		ft_do_redir_left_deep(t_infor *st, int in);
void		do_redir_left(char **cmd, int *lpipe, t_infor *st);
void		do_redir_right(char **cmd, int *rpipe, t_infor *st);
void		do_command(char **cmd, int *rpipe, t_infor *st);
int			ft_check_buildins(char **cmd, t_infor *st, int count);
int			get_count_cmd(char ***cmd);
int			ft_cd_minus_helper(char *prev_dir, t_infor *st);
int			ft_cd(char *args, t_infor *st);
void		ft_exit(char *argv, t_infor *st);
void		ft_pwd(void);
void		get_env(t_infor *st);
int			ft_export(char *var, t_infor *st);
int			ft_unset(char *var, t_infor *st);
void		ft_echo(char *arg, t_infor *st);
void		ft_reinit_pip(t_infor *st);
void		ft_set_read(int *lpipe, int in);
void		ft_set_write(int *rpipe, int out);
void		redirect_r(char *cmd, t_infor *st);
int			redirect_l(char *cmd, t_infor *st);
void		here_doc(char *limiter);
char		*find_path(char *command, char **env);
void		execute(char *command, char **env, t_infor *st);
int			pipa_helper(char *arg, t_infor *st);
int			ft_mshfree1(t_infor *st, int code, int exc);
char		*ft_import(char *st, char *str, int i, int j);
int			ft_checkenv_d_pars(char *s);
int			ft_swap_ask(t_infor *st, int index, int i);
char		**ft_split_wquots(char *args);
int			set_envp(t_infor *st);
int			check_name_var(char *str);
void		ft_redirect(char *str, int *i);
void		sig_void2(int signum);
void		ft_changefirstcomm(t_infor *st);
void		ft_error_cmd(char *cmd, char *arg, int status);
char		**get_modif_arg(char **argv);
char		*ft_rebilder(t_infor *st, int i, int len, int index);
char		**ft_split_up(char *s, char *c);
size_t		ft_word_count_up(char *s, char *c, int code);
char		**ft_mmyfree(char **str);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
int			get_next_line(char **line);
void		ft_init(t_infor *st, int argc, char **argv, char **envp);
int			ft_skip(t_infor *st);
void		ft_putstr(char *s);
int			ft_com_check(t_infor *st);
int			ft_error(t_infor *st, int code);
int			ft_strcmp(char *s1, char *s2);
int			ft_strchr_up(char *b, char *c);
int			ft_parser_split_helper(char *s, int i, char *c, int code);
void		ft_com_split(t_infor *st);
char		*find_path(char *command, char **env);
char		*pipe_to_string(t_infor *st, int *i, int *j);
int			is_it_quot(char s, int code);
int			ft_swap_env(t_infor *st, int index, int i);
char		**ft_split_pars_up(char *args);
size_t		ft_word_count_l(char *s, char c);
int			ft_add_pipe(t_infor *st);
int			ft_check_pipes(t_infor *st);
char		*find_env(char *var, t_infor *st);
int			ft_check_reddir(t_infor *st);
void		ft_rebildredir(t_infor *st);
int			find_name_len(char *s, int i, char c);
char		*ft_gnlstrjoin(char *remains, char *buffer);
char		*ft_skipsimic(char *s);
int			open_file_h(char *redir, char *file, int flag);
void		ft_cutter(t_infor *st);
int			ft_checkenv_d(char *s);
int			ft_bad_env(t_infor *st, int index);
void		sig_void(int sig);
void		sig_handler(int sig);
void		ft_sigex(t_infor *st);
int			ft_quot(char *s);
char		**foo_bar(char **arr);
char		***ft_createrofcmd(t_infor *st);
void		ft_convert_error(int status);
int			ft_strrchr_upred(char *s, int c);
int			ft_set_in(t_infor *st, int in);
void		ft_last_red(t_infor *st, char **s);
int			ft_getlen(char *splited);
int			ft_changevar(char **splited, t_list **content, int len);
int			ft_parser_split_helper2(char *s, int i, char *c, int code);
int			ft_space_check(char *s);

#endif
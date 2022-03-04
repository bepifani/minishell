/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:13:08 by nbyrd             #+#    #+#             */
/*   Updated: 2022/03/04 15:59:15 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_redir_right(char **cmd, int *rpipe, t_info *info)
{
	int	i;

	i = 0;
	(void) info;
	while (cmd[i] && cmd[i][0] != '>')
		i++;
	if (cmd[i])
	{
		redirect_r(cmd[i], info);
		if (rpipe)
		{
			close(rpipe[0]);
			close(rpipe[1]);
		}
	}
	else if (rpipe)
		ft_set_write(rpipe, -1);
}

void	do_redir_left(char **cmd, int *lpipe, t_info *info)
{
	int	i;
	int	in;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i] && cmd[i][0] != '<')
		i++;
	if (cmd[i])
	{
		if (lpipe)
			close(lpipe[1]);
		if (lpipe)
			close(lpipe[0]);
		while (cmd[i][j] == '<')
			in = redirect_l(cmd[i++], info);
		ft_do_redir_left_deep(info, in);
		ft_set_read(NULL, in);
	}
	else if (lpipe)
		ft_set_read(lpipe, -1);
}

void	do_command(char **cmd, int *rpipe, t_info *info)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd[i][0] == '<')
		i++;
	while (cmd[i] && cmd[i][0] == '>')
		i++;
		if (!ft_strncmp("exit", cmd[i], 5) || !ft_strncmp("exit ", cmd[i], 5))
			exit(0);
	execute(cmd[i], info);
	close(rpipe[0]);
	close(rpipe[1]);
	exit(0);
}

void	ft_reinit_pip(t_info *st)
{
	close(st->pip.lpipe[0]);
	close(st->pip.lpipe[1]);
	close(st->pip.rpipe[0]);
	close(st->pip.rpipe[1]);
	close(st->pip.in);
	st->pip.lpipe[0] = -1;
	st->pip.lpipe[1] = -1;
	st->pip.rpipe[0] = -1;
	st->pip.rpipe[1] = -1;
	st->pip.in = -1;
}

void	ft_sigex(t_info *st)
{
	ft_putstr_fd("exit\n", 2);
	if (st->line)
		free(st->line);
	if (st->commands)
		ft_myfree(st->commands);
	exit(1);
}
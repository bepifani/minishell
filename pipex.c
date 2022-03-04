/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:03:11 by zafar             #+#    #+#             */
/*   Updated: 2022/03/04 15:56:24 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_cycle(char ***cmd, t_info *info, int i)
{
	int	pid;

	pipe(info->pip.rpipe);
	pid = fork_and_chain(info->pip.lpipe, info->pip.rpipe, cmd[i], info);
	close(info->pip.lpipe[0]);
	close(info->pip.lpipe[1]);
	info->pip.lpipe[0] = info->pip.rpipe[0];
	info->pip.lpipe[1] = info->pip.rpipe[1];
	i++;
	return (pid);
}

void	if_count_no_one(int i, int flag, char ***cmd, t_info *info)
{
	if (info->count != 1 && flag == 1)
	{
		info->pip.lpipe[0] = info->pip.rpipe[0];
		info->pip.lpipe[1] = info->pip.rpipe[1];
	}
	if (info->count != 1 && flag == 2)
	{
		info->pid = fork_and_chain(info->pip.lpipe, NULL, cmd[i], info);
		close(info->pip.lpipe[0]);
		close(info->pip.lpipe[1]);
	}
}

int	ft_check_buildins(char **cmd, t_info *st, int count)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!ft_strncmp("exit ", cmd[i], 5) || !ft_strncmp("exit", cmd[i], 5))
			ft_exit(cmd[i], st);
		if (count == 1)
		{
			if (!ft_strncmp("export ", cmd[i], 7) \
			|| !ft_strncmp("export", cmd[i], 7))
				return (ft_export(cmd[i], st));
			if (!ft_strncmp("unset ", cmd[i], 6) \
			|| !ft_strncmp("unset", cmd[i], 6))
				return (ft_unset(cmd[i], st));
			if (!ft_strncmp("cd ", cmd[i], 3) \
			|| !ft_strncmp("cd", cmd[i], 3))
				return (ft_cd(cmd[i], st));
		}
		i++;
	}
	return (0);
}

void	pipex(char ***cmd, t_info *info)
{
	int	i;
	int	count;
	int	pid;
	int	status;

	count = cmd_count(info);
	i = 1;
	info->count = count;
	if (count != 1)
		pipe(info->pip.rpipe);
	pid = fork_and_chain(NULL, info->pip.rpipe, cmd[0], info);
	if_count_no_one(i, 1, cmd, info);
	while (i < count - 1)
		pid = pipe_cycle(cmd, info, i++);
	info->pid = pid;
	if_count_no_one(i, 2, cmd, info);
	waitpid(info->pid, &status, 0);
	ft_error3(WEXITSTATUS(status));
	if ((!cmd[++i] && count != 1 && WEXITSTATUS(status) != 2) \
	|| (WEXITSTATUS(status) != 2 && count == 1))
		ft_check_buildins(cmd[count - 1], info, count);
	ft_reinit_pip(info);
}



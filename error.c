/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:49:32 by bepifani          #+#    #+#             */
/*   Updated: 2022/03/05 16:55:14 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_skiper3(t_info *info) //ft_skip
{
	if (info && info->line != NULL)
		free(info->line);
	return (0);
}

int	ft_error(t_info *info, int c) //ft_error
{
	if (c == 1)
	{
		ft_mshfree1(info, 1, -1); //????
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	if (c == 3)
	{
		ft_putstr_fd("msh: syntax error near unexpected token '|'", 2);
		ft_putstr_fd("\n", 2);
	}
	if (c == 4)
	{
		ft_putstr_fd("minishell: parse error", 2);
		ft_putstr_fd("\n", 2);
	}
	return (1);
}

void	ft_error2(char *srt, char *arg, int i) //ft_error_cmd
{
	ft_error3(i);
	if (g_error == 110)
		ft_putstr_fd("t found2\n", 2);
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(srt, 2);
		ft_putstr_fd(": ", 2);
		if (arg)
		{
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": ", 2);
		}
		if (i == 13)
			ft_putstr_fd("is a directory", 2);
		else
			ft_putstr_fd(strerror(i), 2);  //?????????????
	}
	write(2, "\n", 1);
}

void	ft_error3(int i) //ft_convert_error
{
	if (i == 2)
		g_error = 1;
	else if (i == 20)
		g_error = 1;
	else if (i == 13)
		g_error = 126;
	else
		g_error = i;
}
